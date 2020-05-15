#include "Student.h"

#include <iostream>

Student::Student(const Student &obj) : Person(obj)
{
    this->studentNumber = obj.studentNumber;
    // Push all grades from obj into the vector of this object
    for (ModuleGrade *grade : obj.gradeList)
    {
        this->gradeList.push_back(new ModuleGrade(*grade));
    }
}

Student::Student(string name, int age, int studentNumber) : Person(name, age)
{
    this->studentNumber = studentNumber;
}

Student::~Student()
{
    // delete all module grades (dynamic memory).
    for (ModuleGrade *grade : this->gradeList)
    {
        delete grade;
    }
}

void Student::addModule(string moduleName, int moduleGrade)
{
    // Dynamic memory
    ModuleGrade *grade = new ModuleGrade(moduleName, moduleGrade);
    this->gradeList.push_back(grade);
}

void Student::showGradeList()
{
    for (ModuleGrade *grade : this->gradeList)
    {
        grade->showModule();
    }
}

vector<ModuleGrade *> Student::getGrades()
{
    return this->gradeList;
}

string Student::print() const
{
    return to_string(this->studentNumber) + " " + Person::print();
}

Student &Student::operator=(const Student &student)
{
    // This is already a pointer
    // student is an actual object thus we have to use the reference operator
    // to compare if they are located in the same address in memory and therefore identical data.
    if (this == &student)
    {
        return *this;
    }

    // Call parent class' assignment operator.
    Person::operator=(student);

    // Remove grades and clear vector of grades.
    for (ModuleGrade *grade : this->gradeList)
    {
        delete grade;
    }

    this->gradeList.clear();

    // Copy over grades from other object.
    for (ModuleGrade *grade : student.gradeList)
    {
        this->gradeList.push_back(new ModuleGrade(*grade));
    }

    return *this;
}
