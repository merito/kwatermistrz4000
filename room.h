#ifndef ROOM_H
#define ROOM_H

#include "person.h"

#include <QString>
#include <QList>

enum class KeyState { NO_KEY, HOTEL_OWNED, ON_DESK, STUFF, GUEST, LOST };

class Room
{
public:
    Room();
    ~Room();
private:
    QString name;
    int freePlaces;
    int occupiedPlaces;
    Person* keyOwner;
    QList<KeyState> keys;
    QList<Person> guests;
};

#endif // ROOM_H
