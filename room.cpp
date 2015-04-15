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

    for(int i=0;i<this->getPlaces();i++){
        if(i < this->getGuests().length()){
            mrWindow->getLineEdits()[i].setText(this->getGuests()[i]->getName());
            formLayout->addRow(new QLabel(QString("%1.").arg(i+1)), &(mrWindow->getLineEdits()[i]));
        }else{
            formLayout->addRow(new QLabel(QString("%1.").arg(i+1)), &(mrWindow->getLineEdits()[i]));
        }
    }

    }
    mrWindow->exec();

    this->button->setText(QString("%1 %2/%3").arg(
                              this->getName()).arg(
                              this->getOccupiedPlaces()).arg(
                              this->getPlaces()));

    QColor colGreen(Qt::green);
    QColor colYellow(Qt::yellow);
    QColor colRed(Qt::red);

    double ratio = (double)this->getOccupiedPlaces()/this->getPlaces();

    if( ratio < 0.4 ){
        QString qss = QString("background-color: %1").arg(colGreen.name());
        this->getButton()->setStyleSheet(qss);
    }else
    if( ratio < 0.7){
        QString qss = QString("background-color: %1").arg(colYellow.name());
        this->getButton()->setStyleSheet(qss);
    }else{
        QString qss = QString("background-color: %1").arg(colRed.name());
        this->getButton()->setStyleSheet(qss);
    }
}

void Room::saveChanges()
{
    for(int i=0;i<this->guests.length();++i){
        delete this->guests[i];
    }

    this->guests.clear(); //delete

    for(int i=0;i<this->places;++i){
        if(this->getMrWindow()->getLineEdits()[i].text() != ""){
            this->guests.append(new Person(this->getMrWindow()->getLineEdits()[i].text()));
        }
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

