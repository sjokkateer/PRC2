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
    Person(const Person &obj);
    Person(string name, int age);
    virtual string print() const;
    Person &operator=(const Person &person);
    friend ostream &operator<<(ostream &out, const Person &person)
    {
        out << person.print();

        return out;
    }
};

#endif
