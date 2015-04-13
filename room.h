#ifndef ROOM_H
#define ROOM_H

#include "person.h"

#include <QString>
#include <QList>
#include <QPushButton>
#include <QFormLayout>
#include <QLineEdit>
#include "modifyroomwindow.h"

enum class KeyState { NO_KEY, HOTEL_OWNED, ON_DESK, STUFF, GUEST, LOST };

class Room : public QObject
{
Q_OBJECT
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

    QList<Person *> getGuests() const;
    void setGuests(const QList<Person *> &value);

    QPushButton *getButton() const;
    void setButton(QPushButton *value);

    ModifyRoomWindow *getMrWindow() const;
    void setMrWindow(ModifyRoomWindow *value);

public slots:
    void modifyRoom();
private:
    QString name;
    int places;
    int occupiedPlaces;
    Person* keyOwner;
    QList<KeyState> keys;
    QList<Person*> guests;
    QPushButton *button;
    ModifyRoomWindow *mrWindow;
};

#endif // ROOM_H
