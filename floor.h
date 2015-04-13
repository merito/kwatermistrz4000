#ifndef FLOOR_H
#define FLOOR_H

#include <QObject>
#include "room.h"

class Floor
{
public:
    Floor();
    ~Floor();
    QString getName() const;
    void setName(const QString &value);

    int getRoomsNumber() const;
    void setRoomsNumber(int value);

    QList<Room*>* getRooms();
private:
    QString name;
    int roomsNumber;
    QList<Room*> rooms;
};

#endif // FLOOR_H
