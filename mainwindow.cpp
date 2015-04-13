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
                //QObject::connect((*roomIterator).getButton(), SIGNAL(clicked()), &(*roomIterator), SLOT(modifyRoom()) );
        }
    }



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
            tempRoom->setOccupiedPlaces(0);
            tempFloor->getRooms()->append(tempRoom);
        }
        Hotel::getInstance().getFloors()->append(tempFloor);
    }

    drawContent();
}
