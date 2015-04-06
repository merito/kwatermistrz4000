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
    QString getName() const;
    void setName(const QString &value);

    int getPlaces() const;
    void setPlaces(int value);

    int getOccupiedPlaces() const;
    void setOccupiedPlaces(int value);

    Person *getKeyOwner() const;
    void setKeyOwner(Person *value);

    QList<Person> getGuests() const;
    void setGuests(const QList<Person> &value);

private:
    QString name;
    int places;
    int occupiedPlaces;
    Person* keyOwner;
    QList<KeyState> keys;
    QList<Person> guests;
};

#endif // ROOM_H
