#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mainLayout = findChild<QVBoxLayout *>("verticalLayout");
    setWindowIcon(QIcon(":resources/icon.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNowy_triggered()
{
    Hotel::getInstance().clearHotel();
    mhWindow = new ModifyHotelWindow();
    mhWindow->exec();

    drawContent();
}

void MainWindow::drawContent()
{
    QString windowTitle = QString("Kwatermistrz4000 - Ośrodek %1").
            arg(Hotel::getInstance().getName());
    setWindowTitle(windowTitle);

    QList<Floor*>::iterator floorIterator;

    for(floorIterator=Hotel::getInstance().getFloors()->begin();
        floorIterator!=Hotel::getInstance().getFloors()->end();
        ++floorIterator){

        QString floorTitle = QString("Piętro %1").arg(
                    (*floorIterator)->getName());
        mainLayout->addWidget(new QLabel(floorTitle));
        QHBoxLayout *floorLayout = new QHBoxLayout();
        mainLayout->addLayout(floorLayout);

        QList<Room*>::iterator roomIterator;
        for(roomIterator=(*floorIterator)->getRooms()->begin();
            roomIterator!=(*floorIterator)->getRooms()->end();
            ++roomIterator){
            QString buttonLabel = QString("%1 %2/%3").arg(
                        (*roomIterator)->getName()).arg(
                        (*roomIterator)->getOccupiedPlaces()).arg(
                        (*roomIterator)->getPlaces());
            (*roomIterator)->getButton()->setText(buttonLabel);
            floorLayout->addWidget( (*roomIterator)->getButton() );
        }
    }



}
QString MainWindow::getFileName() const
{
    return fileName;
}

void MainWindow::setFileName(const QString &value)
{
    fileName = value;
}


void MainWindow::on_actionWczyt_dom_hotel_triggered()
{
    Hotel::getInstance().clearHotel();
    int testFloors = 10;
    int roomsParter = 2;
    Hotel::getInstance().setName("Testowy");
    Hotel::getInstance().setFloorsNumber(testFloors);
    for(int i=0;i<testFloors;i++){
        Floor *tempFloor = new Floor();
        tempFloor->setName(QString("Piętro %1").arg(i+1));
        tempFloor->setRoomsNumber(roomsParter);
        for(int j=0;j<roomsParter;j++){
            Room *tempRoom = new Room();
            tempRoom->setName(QString("Zbiorówka %1").arg(j+i+2));
            tempRoom->setPlaces(j+3);
            tempFloor->getRooms()->append(tempRoom);
        }
        Hotel::getInstance().getFloors()->append(tempFloor);
    }

    drawContent();
}

int MainWindow::toTextFile(QFile* file){
    if( file->open(QIODevice::ReadWrite) ){
        QTextStream stream(file);

        stream << Hotel::getInstance().getName() << endl;
        stream << Hotel::getInstance().getFloorsNumber() << endl;

        for(int i=0;i<Hotel::getInstance().getFloorsNumber();++i){
            stream << Hotel::getInstance().getFloors()->at(i)->getName() << endl;
            stream << Hotel::getInstance().getFloors()->at(i)->getRoomsNumber() << endl;
            for(int j=0;j<Hotel::getInstance().getFloors()->at(i)->getRoomsNumber();++j){
                stream << Hotel::getInstance().getFloors()->at(i)->getRooms()->at(j)->getName() << endl;
                stream << Hotel::getInstance().getFloors()->at(i)->getRooms()->at(j)->getPlaces() << endl;
                stream << Hotel::getInstance().getFloors()->at(i)->getRooms()->at(j)->getOccupiedPlaces() << endl;
                for(int k=0;k<Hotel::getInstance().getFloors()->at(i)->getRooms()->at(j)->getOccupiedPlaces();++k){
                    stream << Hotel::getInstance().getFloors()->at(i)->getRooms()->at(j)->getGuests().at(k)->getName() << endl;
                }
            }
        }
        return 0;
    }else{
        return 1;
    }
}

void MainWindow::on_actionZapisz_jako_triggered()
{
    QString tempFile = QFileDialog::getSaveFileName(this, "Zapisz kwaterbazę", "./kwaterbaza.txt", "Pliki tekstowe (*.txt)");
    if (tempFile != ""){
        this->setFileName( tempFile );
        QFile *file = new QFile(tempFile);
        toTextFile(file);
        delete file;
    }

}

void MainWindow::on_actionZapisz_triggered()
{
    if(this->getFileName() == ""){
        QString tempFile = QFileDialog::getSaveFileName(this, "Zapisz kwaterbazę", "./kwaterbaza.txt", "Pliki tekstowe (*.txt)");
        if (tempFile != ""){
            this->setFileName( tempFile );
            QFile *file = new QFile(tempFile);
            toTextFile(file);
            delete file;
        }
    }else{
        QFile *file = new QFile(this->getFileName());
        toTextFile(file);
        delete file;
    }
}

void MainWindow::on_actionZako_cz_triggered()
{
    this->close();
}

void MainWindow::on_actionOtw_rz_triggered()
{
    QString tempFile = QFileDialog::getOpenFileName(this, "Otwórz zapisaną kwaterbazę", "./", "Pliki tekstowe (*.txt)");
    if( tempFile != "" ){
        this->setFileName( tempFile );
    }else{
        return;
    }

    Hotel::getInstance().clearHotel();

    QFile *file = new QFile(this->getFileName());

    if(!file->open(QIODevice::ReadOnly)) {
        return;
    }

    QTextStream in(file);

    //QString line = in.readLine();
    Hotel::getInstance().setName(in.readLine());
    Hotel::getInstance().setFloorsNumber(in.readLine().toInt());
    for(int i=0;i<Hotel::getInstance().getFloorsNumber();++i){
        Floor *tempFloor = new Floor();
        tempFloor->setName(in.readLine());
        tempFloor->setRoomsNumber(in.readLine().toInt());
        for(int j=0;j<tempFloor->getRoomsNumber();++j){
            Room *tempRoom = new Room();
            tempRoom->setName(in.readLine());
            tempRoom->setPlaces(in.readLine().toInt());
            int occupied = in.readLine().toInt();
            Person *tempPerson;
            for(int k=0;k<occupied;++k){
                tempPerson = new Person();
                tempPerson->setName(in.readLine());
                tempRoom->appendGuest(tempPerson);
            }
            tempFloor->getRooms()->append(tempRoom);
        }
        Hotel::getInstance().getFloors()->append(tempFloor);
    }

    delete file;

    drawContent();
}
