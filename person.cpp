#include "person.h"
Person::Person()
{
    this->id=0;
    this->number=" ";
    this->name=" ";
}
Person::Person(int id, QString name, QString number)
{
    this->id = id;
    this->name = name;
    this->number = number;
}

int Person::getId()
{
    return this->id;
}

QString Person::getName()
{
    return this->name;
}

QString Person::getNumber()
{
    return this->number;
}

void Person::setId(int id)
{
    this->id = id;
}

void Person::setName(QString name)
{
    this->name = name;
}

void Person::setNumber(QString number)
{
    this->number = number;
}




