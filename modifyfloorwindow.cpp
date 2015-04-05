#include "modifyfloorwindow.h"
#include "ui_modifyfloorwindow.h"

modifyfloorwindow::modifyfloorwindow(int number, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifyfloorwindow)
{
    ui->setupUi(this);
    formLayout=findChild<QFormLayout *>("formLayout_2");

    QString title = QString("Szczegóły pokoi na piętrze %1").
            arg(Hotel::getInstance().getFloors()->last().getName());
    setWindowTitle(title);

    this->rooms = Hotel::getInstance().getFloorsNumber();

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

modifyfloorwindow::~modifyfloorwindow()
{
    delete ui;
}

void modifyfloorwindow::on_buttonBox_accepted()
{
    for(int i=0;i<this->getRooms();i++){
        Room temp;
        temp.setName(lineEditsNames[i].text());
        temp.setFreePlaces(lineEditsPlaces[i].text().toInt());
        temp.setOccupiedPlaces(0);
        Hotel::getInstance().getFloors()->last().getRooms().append(temp);
    }
}
int modifyfloorwindow::getRooms() const
{
    return rooms;
}

void modifyfloorwindow::setRooms(int value)
{
    rooms = value;
}

