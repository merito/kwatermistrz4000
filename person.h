#ifndef PERSON_H
#define PERSON_H

#include <QString>

class Person
{
public:
    Person();
    ~Person();
private:
    bool state;
    QString name;
    QString telNumber;
};

#endif // PERSON_H
