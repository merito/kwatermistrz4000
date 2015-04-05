#include "hotel.h"

Hotel& Hotel::getInstance(){
    static Hotel instance;
    return instance;
}

Hotel::Hotel()
{

}

Hotel::~Hotel()
{

}
int Hotel::getFloorsNumber() const
{
    return floorsNumber;
}

void Hotel::setFloorsNumber(int value)
{
    floorsNumber = value;
}
QString Hotel::getName() const
{
    return name;
}

void Hotel::setName(const QString &value)
{
    name = value;
}
QList<Floor> *Hotel::getFloors()
{
    return &floors;
}





