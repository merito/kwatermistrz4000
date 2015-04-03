#ifndef HOTEL_H
#define HOTEL_H

#include <QObject>
#include "floor.h"

class Hotel
{
public:
    Hotel();
    ~Hotel();
private:
    QString name;
    int floorsNumber;
    QList<Floor> floors;
};

#endif // HOTEL_H
