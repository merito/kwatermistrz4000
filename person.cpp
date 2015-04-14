#include "person.h"

Person::Person()
{

}

Person::Person(QString name)
{
    this->setName(name);
}

Person::~Person()
{

}
QString Person::getName() const
{
    return name;
}

void Person::setName(const QString &value)
{
    name = value;
}


