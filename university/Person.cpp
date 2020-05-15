#include "Person.h"

Person::Person()
{
}

Person::Person(const Person &obj)
{
    this->name = obj.name;
    this->age = obj.age;
}

Person::Person(string name, int age)
{
    this->name = name;
    this->age = age;
}

string Person::print() const
{
    return this->name;
}

Person &Person::operator=(const Person &person)
{
    if (this == &person)
    {
        return *this;
    }

    this->name = person.name;
    this->age = person.age;

    return *this;
}
