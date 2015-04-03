#include "modifyhotelwindow.h"
#include "ui_modifyhotelwindow.h"

ModifyHotelWindow::ModifyHotelWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifyHotelWindow)
{
    ui->setupUi(this);
    formLayout=findChild<QFormLayout *>("formLayout");
    labels = NULL;
    lineEdits = NULL;
}

ModifyHotelWindow::~ModifyHotelWindow()
{
    delete ui;
}

void ModifyHotelWindow::on_buttonBox_accepted()
{

}

void ModifyHotelWindow::on_lineEdit_textChanged(const QString &arg1)
{
    this->floors=arg1.toInt();

    if(labels){
        delete[] labels;
    }
    if(lineEdits){
        delete[] lineEdits;
    }

    labels = new QLabel[this->floors];
    lineEdits = new QLineEdit[this->floors];

    for(int i=0;i<this->floors;i++){
        QString label = QString("Liczba pokoi na piętrze %1.").arg(i+1);
        labels[i].setText(label);
        formLayout->addRow(&labels[i], &lineEdits[i]);
    }
}
