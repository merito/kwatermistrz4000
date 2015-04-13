#ifndef HOTEL_H
#define HOTEL_H

#include <QObject>
#include "floor.h"

class Hotel
{
public:
    static Hotel& getInstance();
    void clearHotel();

    int getFloorsNumber() const;
    void setFloorsNumber(int value);

    QString getName() const;
    void setName(const QString &value);

    QList<Floor *> *getFloors();

private:
    Hotel();
    ~Hotel();

    QString name;
    int floorsNumber;
    QList<Floor *> floors;
};

#endif // HOTEL_H
