#include <fstream>

#include "Group.h"

void Group::addStudent(Student &student)
{
    this->students.push_back(&student);
}

bool Group::removeStudent(int studentNumber)
{
    // To remove student from the group we just use regular remove
    for (int i = 0; i < this->students.size(); i++)
    {
        if (this->students[i]->getStudentNumber() == studentNumber)
        {
            this->students.erase(this->students.begin() + i);
            return true;
        }
    }

    return false;
}
