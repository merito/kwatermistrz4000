#ifndef HOTEL_H
#define HOTEL_H

#include <QObject>
#include "floor.h"

class Hotel
{
public:
    Hotel();
    ~Hotel();
    int getFloorsNumber() const;
    void setFloorsNumber(int value);

    QString getName() const;
    void setName(const QString &value);

private:
    QString name;
    int floorsNumber;
    QList<Floor> floors;
};

#endif // HOTEL_H
