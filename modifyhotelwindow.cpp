#include "modifyhotelwindow.h"
#include "ui_modifyhotelwindow.h"

ModifyHotelWindow::ModifyHotelWindow(Hotel *hotel, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifyHotelWindow)
{
    ui->setupUi(this);
    this->hotel=hotel;
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
    this->hotel->setName(this->name);
    this->hotel->setFloorsNumber(this->floors);

    for(int i=0;i<this->floors;i++){
        mfWindow = new modifyfloorwindow();
        mfWindow->show();
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
