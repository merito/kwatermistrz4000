#include "room.h"

Room::Room()
{
    this->button = new QPushButton();
    //QObject(this, SIGNAL(clicked()), this, SLOT(modifyRoom()) );
}

Room::~Room()
{
    //delete button;
    //delete keyOwner;
}
QString Room::getName() const
{
    return name;
}

void Room::setName(const QString &value)
{
    name = value;
}
int Room::getPlaces() const
{
    return places;
}

void Room::setPlaces(int value)
{
    places = value;
}
int Room::getOccupiedPlaces() const
{
    return occupiedPlaces;
}

void Room::setOccupiedPlaces(int value)
{
    occupiedPlaces = value;
}
Person *Room::getKeyOwner() const
{
    return keyOwner;
}

void Room::setKeyOwner(Person *value)
{
    keyOwner = value;
}
QList<Person> Room::getGuests() const
{
    return guests;
}

void Room::setGuests(const QList<Person> &value)
{
    guests = value;
}

void Room::modifyRoom()
{
    mrWindow = new ModifyRoomWindow();
    mrWindow->setWindowIcon(QIcon(":resources/icon.png"));
    mrWindow->setWindowTitle(QString("Lista osób w pokoju %1").arg(this->getName()));
    QFormLayout *formLayout = mrWindow->findChild<QFormLayout *>("formLayout");
    formLayout->addRow(new QLabel("Lista osób:"));

    QLineEdit *lineEdits = new QLineEdit[this->getPlaces()];

    QList<Person>::iterator it;
    it=this->getGuests().begin();

    for(int i=0;i<this->getPlaces();i++){
        if(it!=this->getGuests().end()){
            lineEdits[i].setText((*it).getName());
            formLayout->addRow(new QLabel(QString("%1.").arg(i+1)), &lineEdits[i]);
        }
    }
    mrWindow->exec();
}
QPushButton *Room::getButton() const
{
    return button;
}

void Room::setButton(QPushButton *value)
{
    button = value;
}

