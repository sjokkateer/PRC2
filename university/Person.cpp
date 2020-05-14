#include "Person.h"

Person::Person()
{
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
