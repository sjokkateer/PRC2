#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <iostream>

using namespace std;

class Student : public Person
{
private:
    int studentNumber;

public:
    Student(string name, int age, int studentNumber);
    ~Student();
    void addModule(string moduleName, int moduleGrade);
    void showGradeList();

    string print() const;
    friend ostream &operator<<(ostream &out, const Student &student)
    {
        out << student.print();

        return out;
    }
};

#endif
