#include "modifyhotelwindow.h"
#include "ui_modifyhotelwindow.h"

ModifyHotelWindow::ModifyHotelWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifyHotelWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":resources/icon.png"));

    formLayout=findChild<QFormLayout *>("formLayout");
    labelsNames = NULL;
    labelsRooms = NULL;
    lineEditsNames = NULL;
    lineEditsRooms = NULL;
}

ModifyHotelWindow::~ModifyHotelWindow()
{
    delete ui;
}

void ModifyHotelWindow::on_buttonBox_accepted()
{
    Hotel::getInstance().setName(this->name);
    Hotel::getInstance().setFloorsNumber(this->floors);

    Floor temp;
    for(int i=0;i<this->floors;i++){
        temp.setName(lineEditsNames[i].text());
        temp.setRoomsNumber(lineEditsRooms->text().toInt());
        Hotel::getInstance().getFloors()->append(temp);
        mfWindow = new modifyfloorwindow(i);
        mfWindow->exec();
    }
}

void ModifyHotelWindow::on_lineEdit_textChanged(const QString &arg1)
{
    this->floors=arg1.toInt();

    if(labelsNames){
        delete[] labelsNames;
    }
    if(labelsRooms){
        delete[] labelsRooms;
    }
    if(lineEditsNames){
        delete[] lineEditsNames;
    }
    if(lineEditsRooms){
        delete[] lineEditsRooms;
    }

    labelsNames = new QLabel[this->floors];
    labelsRooms = new QLabel[this->floors];

    lineEditsNames = new QLineEdit[this->floors];
    lineEditsRooms = new QLineEdit[this->floors];

    for(int i=0;i<this->floors;i++){
        QString labelName = QString("Numer lub nazwa piętra %1.").arg(i+1);
        QString labelRoom = QString("Liczba pokoi na piętrze %1.").arg(i+1);
        labelsNames[i].setText(labelName);
        labelsRooms[i].setText(labelRoom);
        formLayout->addRow(&labelsNames[i], &lineEditsNames[i]);
        formLayout->addRow(&labelsRooms[i], &lineEditsRooms[i]);
    }
}

void ModifyHotelWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    this->name=arg1;
}
