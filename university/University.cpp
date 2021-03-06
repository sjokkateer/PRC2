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
    // Normally I would add this kind of validation to a validator
    // object that also returns an array of error messages.
    if (!Student::isValidStudentNumber(studentNumber))
    {
        return false;
    }

    Student *student = this->findStudent(studentNumber);

    if (student)
    {
        return false;
    }

    // There is no validation for age though.
    // even though it gets handled by the helper function atm, that
    // only positive numbers can be given.
    student = new Student(name, age, studentNumber);
    this->students.push_back(student);

    return true;
}

bool University::removeStudent(int studentNumber)
{
    Student *student = NULL;

    for (int i = 0; i < this->students.size(); i++)
    {
        student = this->students[i];

        if (student->getStudentNumber() == studentNumber)
        {
            // Remove student from groups first.
            this->removeFromGroups(studentNumber);

            // Use erase to manage the removal of the student pointer.
            this->students.erase(this->students.begin() + i);
            return true;
        }
    }

    return false;
}

// Synchronizes the groups, since the student with studentNumber
// is non existent atm.
void University::removeFromGroups(int studentNumber)
{
    for (int i = 0; i < this->groups.size(); i++)
    {
        this->removeFromGroup(i, studentNumber);
    }
}

void University::showStudents()
{
    for (Student *student : this->students)
    {
        cout << *student << endl;
        cout << endl;
    }
}

// Is responsible for outputting the student's details to a text file.
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
        // Dereference to an object.
        outputFile << *student;
        outputFile.close();
        return true;
    }

    return false;
}

bool University::addGradeToStudent(int studentNumber, string moduleName, int moduleGrade)
{
    if (!Student::isValidStudentNumber(studentNumber))
    {
        return false;
    }

    Student *student = this->findStudent(studentNumber);

    if (!student)
    {
        return false;
    }

    // Same here, no validation for the grade even though this is handled
    // by the helper function atm.
    student->addModule(moduleName, moduleGrade);
    return true;
}

// Return value is not used atm, it was when testing functions
// individually.
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
    // Maybe mathematically 0 <= groupIndex < groupSize wouldve been nicer
    // Although the logic would be expressed as coded imo.
    return groupIndex >= 0 && groupIndex < this->groups.size();
}

bool University::removeFromGroup(int groupIndex, int studentNumber)
{
    if (!this->withinBoundries(groupIndex))
    {
        return false;
    }

    Student *student = this->findStudent(studentNumber);

    if (!student)
    {
        return false;
    }

    Group *group = this->groups[groupIndex];
    return group->removeStudent(student);
}

void University::showGroups()
{
    // Change to for loop to have index as well.
    for (int i = 0; i < this->groups.size(); i++)
    {
        cout << "(" << i + 1 << ") " << *this->groups[i] << endl;
    }

    cout << endl;
}

// Writes a group to a text file.
bool University::outputGroup(int groupIndex)
{
    if (this->withinBoundries(groupIndex))
    {
        Group *group = this->groups[groupIndex];
        return this->write(groupIndex, group);
    }

    return false;
}

bool University::write(int groupIndex, Group *group)
{
    string fileName = "group_" + to_string(groupIndex + 1);
    ofstream outputFile(fileName);

    if (outputFile.is_open())
    {
        outputFile << *group;
        outputFile.close();
        return true;
    }

    return false;
}

void University::store(ofstream &outputFile) const
{
    int numberOfStudents = this->students.size();
    // By ref since it needs to be a pointer for reinterpret_cast.
    outputFile.write(reinterpret_cast<char *>(&numberOfStudents), sizeof(numberOfStudents));

    // Then serialize all students
    for (Student *student : this->students)
    {
        student->store(outputFile);
    }

    // Same for groups.
    int numberOfGroups = this->groups.size();
    outputFile.write(reinterpret_cast<char *>(&numberOfGroups), sizeof(numberOfGroups));

    for (Group *group : this->groups)
    {
        group->store(outputFile);
    }
}

void University::load(ifstream &inputFile)
{
    int numberOfStudents;
    // Cause it needs to know how many bytes it has to read into the passed value.
    inputFile.read(reinterpret_cast<char *>(&numberOfStudents), sizeof(numberOfStudents));

    Student *student;
    for (int i = 0; i < numberOfStudents; i++)
    {
        student = new Student();
        student->load(inputFile);
        this->students.push_back(student);
    }

    // create n empty groups based on original number of groups.
    int numberOfGroups;
    inputFile.read(reinterpret_cast<char *>(&numberOfGroups), sizeof(numberOfGroups));

    vector<int> studentNumbers;
    Group *group;
    for (int i = 0; i < numberOfGroups; i++)
    {
        group = new Group();
        studentNumbers = group->load(inputFile);

        // Map the corresponding students
        for (int studentNumber : studentNumbers)
        {
            student = this->findStudent(studentNumber);

            if (student)
            {
                // If the student number exists in our university's collection we add it back to the group.
                group->addStudent(student);
            }
        }

        // Finally push the group with student pointers onto the vector.
        this->groups.push_back(group);
    }
}
