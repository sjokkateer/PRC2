#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <fstream>

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

    Person &operator=(const Person &person);
    virtual string print() const;

    virtual void store(ofstream &outFile);
    virtual void load(ifstream &inFile);

    friend ostream &operator<<(ostream &out, const Person &person)
    {
        out << person.print();

        return out;
    }
};

#endif
