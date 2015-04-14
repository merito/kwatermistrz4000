#include "room.h"
#include <QDebug>

Room::Room()
{
    this->button = new QPushButton();
    this->mrWindow = nullptr;
    QObject::connect(this->getButton(), SIGNAL(clicked()), this, SLOT(modifyRoom()) );
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
    return this->guests.length();
}

Person *Room::getKeyOwner() const
{
    return keyOwner;
}

void Room::setKeyOwner(Person *value)
{
    keyOwner = value;
}
QList<Person*> Room::getGuests()
{
    return guests;
}

void Room::setGuests(const QList<Person *> &value)
{
    guests = value;
}

void Room::appendGuest(Person *guest){
    this->guests.append(guest);
}

void Room::modifyRoom()
{
    if(this->mrWindow == nullptr){

    this->mrWindow = new ModifyRoomWindow();
    QObject::connect(this->mrWindow, SIGNAL(accepted()), this, SLOT(saveChanges()));
    mrWindow->setWindowIcon(QIcon(":resources/icon.png"));
    mrWindow->setWindowTitle(QString("Lista osób w pokoju %1").arg(this->getName()));
    QFormLayout *formLayout = mrWindow->findChild<QFormLayout *>("formLayout");
    formLayout->addRow(new QLabel("Lista osób:"));

    mrWindow->setLineEdits(new QLineEdit[this->getPlaces()]);

    QList<Person*>::iterator it;
    it=this->getGuests().begin();

    for(int i=0;i<this->getPlaces();i++){
        if(i < this->getGuests().length()){
            mrWindow->getLineEdits()[i].setText((*it)->getName());
            formLayout->addRow(new QLabel(QString("%1.").arg(i+1)), &(mrWindow->getLineEdits()[i]));
            it++;
        }else{
            formLayout->addRow(new QLabel(QString("%1.").arg(i+1)), &(mrWindow->getLineEdits()[i]));
        }
    }

    }
    mrWindow->exec();
}

void Room::saveChanges()
{
    for(int i=0;i<this->guests.length();++i){
        delete this->guests[i];
    }

    this->guests.clear(); //delete

    for(int i=0;i<this->places;++i){
        this->guests.append(new Person(this->getMrWindow()->getLineEdits()[i].text()));
    }
}

ModifyRoomWindow *Room::getMrWindow() const
{
    return mrWindow;
}

void Room::setMrWindow(ModifyRoomWindow *value)
{
    mrWindow = value;
}

QPushButton *Room::getButton() const
{
    return button;
}

void Room::setButton(QPushButton *value)
{
    button = value;
}

