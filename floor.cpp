#include "floor.h"

Floor::Floor()
{

}

Floor::~Floor()
{

}
QString Floor::getName() const
{
    return name;
}

void Floor::setName(const QString &value)
{
    name = value;
}
int Floor::getRoomsNumber() const
{
    return roomsNumber;
}

void Floor::setRoomsNumber(int value)
{
    roomsNumber = value;
}
QList<Room *> *Floor::getRooms()
{
    return &rooms;
}
