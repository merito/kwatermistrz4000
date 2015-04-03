#ifndef FLOOR_H
#define FLOOR_H

#include <QObject>
#include "room.h"

class Floor
{
public:
    Floor();
    ~Floor();
private:
    QString name;
    int roomsNumber;
    QList<Room> rooms;
};

#endif // FLOOR_H
