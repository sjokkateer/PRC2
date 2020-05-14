#ifndef PERSON_H
#define PERSON_H

#include <iostream>

using namespace std;

class Person
{
private:
    string name;
    int age;

public:
    Person();
    Person(string name, int age);

    // const has to do such that we cannot change this after we passed it into the
    // output buffer? Can be called on a constant object
    virtual string print() const;
    friend ostream &operator<<(ostream &out, const Person &person)
    {
        out << person.print();

        return out;
    }
};

#endif
