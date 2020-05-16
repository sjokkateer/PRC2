#include <fstream>

#include "Group.h"

void Group::addStudent(Student *student)
{
    this->students.push_back(student);
}

bool Group::removeStudent(Student *student)
{
    for (int i = 0; i < this->students.size(); i++)
    {
        if (this->students[i]->getStudentNumber() == student->getStudentNumber())
        {
            this->students.erase(this->students.begin() + i);
            return true;
        }
    }

    return false;
}

vector<Student *> Group::getStudents()
{
    return this->students;
}
