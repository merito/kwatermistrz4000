#include "modifyfloorwindow.h"
#include "ui_modifyfloorwindow.h"

modifyfloorwindow::modifyfloorwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifyfloorwindow)
{
    ui->setupUi(this);
    formLayout=findChild<QFormLayout *>("formLayout_2");
    labelsNames=NULL;
    labelsPlaces=NULL;
    lineEditsNames=NULL;
    lineEditsPlaces=NULL;
}

modifyfloorwindow::~modifyfloorwindow()
{
    delete ui;
}

void modifyfloorwindow::on_lineEdit_textChanged(const QString &arg1)
{
    this->rooms = arg1.toInt();

    if(labelsNames){
        delete[] labelsNames;
    }
    if(labelsPlaces){
        delete[] labelsPlaces;
    }
    if(lineEditsNames){
        delete[] lineEditsNames;
    }
    if(lineEditsPlaces){
        delete[] lineEditsPlaces;
    }

    labelsNames = new QLabel[this->rooms];
    labelsPlaces = new QLabel[this->rooms];

    lineEditsNames = new QLineEdit[this->rooms];
    lineEditsPlaces = new QLineEdit[this->rooms];

    for(int i=0;i<this->rooms;i++){
        QString labelName = QString("Numer lub nazwa pokoju %1.").arg(i+1);
        QString labelPlaces = QString("Liczba miejsc w pokoju %1.").arg(i+1);
        labelsNames[i].setText(labelName);
        labelsPlaces[i].setText(labelPlaces);
        formLayout->addRow(&labelsNames[i], &lineEditsNames[i]);
        formLayout->addRow(&labelsPlaces[i], &lineEditsPlaces[i]);
    }
}
