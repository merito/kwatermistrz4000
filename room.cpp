#include "room.h"

Room::Room()
{

}

Room::~Room()
{

}
QString Room::getName() const
{
    return name;
}

void Room::setName(const QString &value)
{
    name = value;
}
int Room::getFreePlaces() const
{
    return freePlaces;
}

void Room::setFreePlaces(int value)
{
    freePlaces = value;
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






