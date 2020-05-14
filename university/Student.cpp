#include "Student.h"

Student::Student(string name, int age, int studentNumber) : Person(name, age)
{
    this->studentNumber = studentNumber;
}

Student::~Student()
{
    // delete all module grades.
}

void Student::addModule(string moduleName, int moduleGrade)
{
}

void showGradeList()
{
}

string Student::print() const
{
    return "(" + to_string(this->studentNumber) + ") " + Person::print();
}
