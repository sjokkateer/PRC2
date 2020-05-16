#include <iostream>
#include <fstream>

using namespace std;

#include "University.h"
#include "helpers.h"

void displayGreeting();
void displayMenu();
void callAppropriateMethod(int choice, University &university);

string getStudentName();
string getModuleName();
string getNameForTopic(string topic);
int getStudentNumber();

int getGroupNumber();

void initializeUniversity(University &university);
void storeUniversityState(const University &university);

void hasBeenOutput(string topic, bool successfullyOutput);
void hasBeenAdded(string topic, bool added);
void hasBeenRemoved(string topic, bool removed);
void printActionResult(string topic, string action, bool didHappen);

#define EXIT 0

int main()
{
    University uni = University();
    initializeUniversity(uni);

    int choice;
    displayGreeting();

    while (true)
    {
        displayMenu();
        choice = getIntegerInput();
        if (choice == EXIT)
            break;
        callAppropriateMethod(choice, uni);
        print();
    }

    storeUniversityState(uni);
    return 0;
}

void displayGreeting()
{
    print();
    print("Welcome to the University");
    print("This application allows you to manage students and groups of students");
    print("Once you exit the application, the state of the university will be serialized");
    print("On next startup, the old state will be loaded for you to continue where you left off");
    print();
}

void displayMenu()
{
    print("UNIVERSITY");
    print("----------");
    print("0 to exit");

    print("STUDENTS");
    print("--------");
    print("1 to add student");
    print("2 to remove student");
    print("3 to add a grade to student");
    print("4 to show all students");
    print("5 to write a student to file");
    print();

    print("GROUPS");
    print("------");
    print("6 to create a group");
    print("7 to remove a group");
    print("8 to add a student to a group");
    print("9 to remove a student from a group");
    print("10 to show all groups");
    print("11 to write a group to file");
    print();
}

void callAppropriateMethod(int choice, University &university)
{
    int studentNumber;
    string name;
    int age;
    bool added;
    bool removed;

    string moduleName;
    int moduleGrade;

    bool successfullyOutput;

    int groupIndex;

    cout << endl;

    switch (choice)
    {
    case 1:
        name = getStudentName();
        studentNumber = getStudentNumber();
        age = getIntegerInput("Please enter an age: ");
        added = university.addStudent(studentNumber, name, age);

        hasBeenAdded("student", added);
        break;
    case 2:
        studentNumber = getStudentNumber();
        removed = university.removeStudent(studentNumber);

        hasBeenRemoved("student", removed);
        break;
    case 3:
        studentNumber = getStudentNumber();
        moduleName = getModuleName();
        moduleGrade = getIntegerInput("Please enter a grade: ");

        added = university.addGradeToStudent(studentNumber, moduleName, moduleGrade);
        hasBeenAdded("grade", added);
        break;
    case 4:
        print("--- STUDENTS ---");
        university.showStudents();
        break;
    case 5:
        studentNumber = getStudentNumber();
        successfullyOutput = university.outputStudent(studentNumber);

        hasBeenOutput("student", successfullyOutput);
        break;
    case 6:
        university.createNewGroup();
        print("New group created");
        break;
    case 7:
        university.showGroups();

        groupIndex = getGroupNumber();
        removed = university.removeGroup(groupIndex);

        hasBeenRemoved("group", removed);
        break;
    case 8:
        university.showGroups();

        groupIndex = getGroupNumber();
        studentNumber = getStudentNumber();
        added = university.addToGroup(groupIndex, studentNumber);

        hasBeenAdded("student", added);
        cout << " to group.";
        break;
    case 9:
        university.showGroups();

        groupIndex = getGroupNumber();
        studentNumber = getStudentNumber();
        removed = university.addToGroup(groupIndex, studentNumber);

        hasBeenAdded("student", removed);
        cout << " from group.";
        break;
    case 10:
        print("--- GROUPS ---");
        university.showGroups();
        break;
    case 11:
        university.showGroups();

        groupIndex = getGroupNumber();
        successfullyOutput = university.outputGroup(groupIndex);

        hasBeenOutput("group", successfullyOutput);
        break;
    default:
        break;
    }

    cout << endl;
}

void initializeUniversity(University &university)
{
    ifstream inputFile(UNIVERSITY_DATA_FILE);
    if (inputFile.is_open())
    {
        university.load(inputFile);
        inputFile.close();
    }
}

void storeUniversityState(const University &university)
{
    ofstream outputFile(UNIVERSITY_DATA_FILE);
    if (outputFile.is_open())
    {
        university.store(outputFile);
        outputFile.close();
    }
}

void hasBeenAdded(string topic, bool added)
{
    printActionResult(topic, "added", added);
}

void hasBeenRemoved(string topic, bool removed)
{
    printActionResult(topic, "removed", removed);
}

void printActionResult(string topic, string action, bool didHappen)
{
    string message = topic + " has ";
    if (!didHappen)
    {
        message += "not ";
    }

    message += "been " + action;

    cout << message;
}

string getStudentName()
{
    return getNameForTopic("student");
}

string getNameForTopic(string topic)
{
    cin.ignore();

    string name;
    // This does however return for ex 1.23 as a name
    while (isEmptyString(name) || !isNotInteger(name))
    {
        cout << "Please enter a name for the " + topic + ": ";
        getline(cin, name);
    }

    return name;
}

string getModuleName()
{
    return getNameForTopic("module");
}

int getStudentNumber()
{
    return getIntegerInput("Please enter a student number: ");
}

void hasBeenOutput(string topic, bool successfullyOutput)
{
    printActionResult(topic, "output", successfullyOutput);
}

int getGroupNumber()
{
    return getIntegerInput("Please enter a group number: ") - 1;
}
