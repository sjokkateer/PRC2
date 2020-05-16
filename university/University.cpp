#include "University.h"

University::~University()
{
    for (Student *student : this->students)
    {
        delete student;
    }

    for (Group *group : this->groups)
    {
        delete group;
    }
}

Student *University::findStudent(int studentNumber)
{
    for (Student *student : this->students)
    {
        if (student->getStudentNumber() == studentNumber)
        {
            return student;
        }
    }

    return NULL;
}

bool University::addStudent(int studentNumber, string name, int age)
{
    if (!Student::isValidStudentNumber(studentNumber))
    {
        return false;
    }

    Student *student = this->findStudent(studentNumber);

    if (student)
    {
        return false;
    }

    student = new Student(name, age, studentNumber);
    this->students.push_back(student);

    return true;
}

bool University::removeStudent(int studentNumber)
{
    // For now delete pointer, later on we want to remove
    // the student from every group first.
    Student *student = NULL;

    for (int i = 0; i < this->students.size(); i++)
    {
        student = this->students[i];
        if (student->getStudentNumber() == studentNumber)
        {
            // Use erase to manage the removal of the student pointer.
            this->students.erase(this->students.begin() + i);
            return true;
        }
    }

    return false;
}

void University::showStudents()
{
    for (Student *student : this->students)
    {
        cout << *student << endl;
    }
}

bool University::outputStudent(int studentNumber)
{

    if (Student::isValidStudentNumber(studentNumber))
    {
        Student *student = this->findStudent(studentNumber);

        if (student)
        {
            // In case it failed, will return false as well.
            return this->write(student);
        }
    }

    return false;
}

bool University::write(Student *student)
{
    string studentFileName = "student_" + to_string(student->getStudentNumber());
    ofstream outputFile(studentFileName);

    if (outputFile.is_open())
    {
        outputFile << *student;
        outputFile.close();
        return true;
    }

    return false;
}

int University::createNewGroup()
{
    Group *g = new Group();
    this->groups.push_back(g);

    return this->groups.size() - 1;
}

bool University::removeGroup(int groupIndex)
{
    if (!this->withinBoundries(groupIndex))
    {
        return false;
    }

    this->groups.erase(this->groups.begin() + groupIndex);
    return true;
}

bool University::addToGroup(int groupIndex, int studentNumber)
{
    if (!this->withinBoundries(groupIndex))
    {
        return false;
    }

    Student *student = this->findStudent(studentNumber);

    if (!student || this->alreadyInGroup(groupIndex, student))
    {
        return false;
    }

    Group *group = this->groups[groupIndex];
    group->addStudent(student);

    return true;
}

bool University::alreadyInGroup(int groupIndex, Student *student)
{
    Group *group = this->groups[groupIndex];

    for (Student *studentInGroup : group->getStudents())
    {
        if (student->getStudentNumber() == studentInGroup->getStudentNumber())
        {
            return true;
        }
    }

    return false;
}

bool University::withinBoundries(int groupIndex)
{
    return groupIndex >= 0 && groupIndex < this->groups.size();
}

void University::showGroups()
{
    for (Group *group : this->groups)
    {
        cout << *group << endl;
    }
}