#include <iostream>
#include <fstream>

using namespace std;

#include "University.h"

void hasBeenAdded(bool added);
void hasBeenRemoved(bool removed);
void printActionResult(string action, bool didHappen);

int main()
{
    University uni = University();
    bool added = uni.addStudent(1234567, "barnaby", 23);
    added = uni.addStudent(200, "Barteljaap", 50);

    int groupIndex = uni.createNewGroup(); // Will be newly pushed item thus last index.
    uni.addToGroup(groupIndex, 1234567);
    uni.showGroups();

    uni.addToGroup(groupIndex, 1234567);
    uni.showGroups();

    uni.addToGroup(groupIndex, 200);
    uni.showGroups();

    int firstGroup = groupIndex;

    groupIndex = uni.createNewGroup();
    uni.addToGroup(groupIndex, 200);
    uni.showGroups();

    uni.removeFromGroup(firstGroup, 200);
    uni.showGroups();

    // cout << endl;
    // cout << "STUDENTS: " << endl;
    // uni.showStudents();

    // bool removed = uni.removeStudent(2);
    // hasBeenRemoved(removed);

    // removed = uni.removeStudent(1234567);
    // hasBeenRemoved(removed);

    // cout << endl;
    // cout << "STUDENTS: " << endl;
    // uni.showStudents();

    // removed = uni.removeStudent(1234567);
    // hasBeenRemoved(removed);

    // removed = uni.removeStudent(200);
    // hasBeenRemoved(removed);

    // cout << endl;
    // cout << "STUDENTS: " << endl;
    // uni.showStudents();

    // Group g = Group();
    // Student s1 = Student("barnaby", 23, 1234567);
    // Student s2 = Student("kill face", 43, 133713337);
    // Student s3 = Student("xander", 35, 1333333);

    // g.addStudent(s1);
    // g.addStudent(s2);
    // g.addStudent(s3);

    // cout << g << endl;

    // g.removeStudent(133713337);

    // // So a higher level management class will take responsibility
    // // of the literal removal of students and dangling pointers.
    // // delete &s2;

    // cout << g << endl;

    // s.addModule("PCS2", 7);
    // s.addModule("PCS1", 8);

    // ofstream outputFile("students.dat", ios::binary);

    // if (outputFile.is_open())
    // {
    //     s.store(outputFile);
    //     outputFile.close();
    // }

    // Student newStudent;

    // ifstream inputFile("students.dat");

    // if (inputFile.is_open())
    // {
    //     newStudent.load(inputFile);
    //     inputFile.close();
    // }

    // cout << newStudent << endl;

    // newStudent.addModule("EDB3", 9);

    // // ofstream outputFile("students.dat", ios::binary);
    // outputFile.open("students.dat", ios::binary);
    // if (outputFile.is_open())
    // {
    //     newStudent.store(outputFile);
    //     outputFile.close();
    // }

    // newStudent.showGradeList();

    return 0;
}

void hasBeenAdded(bool added)
{
    printActionResult("added", added);
}

void hasBeenRemoved(bool removed)
{
    printActionResult("removed", removed);
}

void printActionResult(string action, bool didHappen)
{
    string result;
    if (didHappen)
    {
        result = "Has been";
    }
    else
    {
        result = "Has not been";
    }
    cout << result << " " << action << endl;
}
