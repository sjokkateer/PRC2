#include <iostream>
#include <fstream>

using namespace std;

#include "University.h"

void hasBeenAdded(bool added);
void hasBeenRemoved(bool removed);
void printActionResult(string action, bool didHappen);

int main()
{
    // zero to exit.
    // All functions but split with their category for now.

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

    uni.outputGroup(groupIndex);

    int firstGroup = groupIndex;

    groupIndex = uni.createNewGroup();
    uni.addToGroup(groupIndex, 200);
    uni.showGroups();

    uni.removeFromGroup(firstGroup, 200);
    uni.showGroups();

    uni.addGradeToStudent(1234567, "PCS_2", 8);
    uni.addGradeToStudent(1234567, "EDB_3", 7);

    uni.outputGroup(groupIndex);

    uni.outputGroup(firstGroup);

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
