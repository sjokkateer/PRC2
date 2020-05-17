#include <fstream>

#include "Group.h"

void Group::addStudent(Student *student)
{
    // Validation for if a student already is in this group
    // couldve been put here if return type were bool.
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

void Group::store(ofstream &outputFile)
{
    // Number of students then the student numbers belonging to this group.
    int numberOfStudents = this->getStudents().size();
    outputFile.write(reinterpret_cast<char *>(&numberOfStudents), sizeof(numberOfStudents));

    // Write for each student it's number to the file.
    int studentNumber;
    for (Student *student : this->getStudents())
    {
        studentNumber = student->getStudentNumber();
        outputFile.write(reinterpret_cast<char *>(&studentNumber), sizeof(studentNumber));
    }
}

vector<int> Group::load(ifstream &inputFile)
{
    int numberOfStudents;
    inputFile.read(reinterpret_cast<char *>(&numberOfStudents), sizeof(numberOfStudents));

    vector<int> studentNumbers;

    int studentNumber;
    for (int i = 0; i < numberOfStudents; i++)
    {
        inputFile.read(reinterpret_cast<char *>(&studentNumber), sizeof(studentNumber));
        studentNumbers.push_back(studentNumber);
    }

    return studentNumbers;
}
