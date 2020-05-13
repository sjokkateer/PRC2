#include <iostream>
#include <stdio.h>
#include "Scan.h"
#include "ScanList.h"
#include "helpers.h"

using namespace std;

void displayGreeting();
void displayMenu();
void callAppropriateMethod(int choice, ScanList &sl);

#define EXIT 0

int main()
{
    ScanList sl = ScanList();

    int choice;
    displayGreeting();

    while (true)
    {
        displayMenu();
        choice = getIntegerInput();
        if (choice == EXIT)
            break;
        callAppropriateMethod(choice, sl);
        print();
    }

    // sl.addScan(5);
    // sl.addScan(5);
    // sl.addScan(12);
    // sl.addScan(1);
    // sl.addScan(1);
    // sl.addScan(1);
    // sl.addScan(1);
    // sl.addScan(1);
    // sl.addScan(7);
    // sl.addScan(12);
    // sl.addScan(12);
    // sl.addScan(13);

    // sl.removeScan(1);

    // sl.addScan(1);

    // cout << sl << endl;

    // cout << "1 is recycled: "
    //      << sl.getTimesRecycled(1)
    //      << " times."
    //      << endl;

    // cout << "7 is recycled: "
    //      << sl.getTimesRecycled(7)
    //      << " times."
    //      << endl;

    // cout << "5 is recycled: "
    //      << sl.getTimesRecycled(5)
    //      << " times."
    //      << endl;

    // cout << "12 is recycled: "
    //      << sl.getTimesRecycled(12)
    //      << " times."
    //      << endl;

    return 0;
}

void displayGreeting()
{
    print();
    print("Welcome to the scanlist application");
    print("Here you can scan objects with serial numbers.");
    print("NOTE!");
    print("The scan list is displayed as: serialNo (times recycled) -> next scan");
    print();
}

void displayMenu()
{
    print("Scan List");
    print("---------");
    print("0 to exit");
    print("1 display the scan list");
    print("2 scan a serialnumber");
    print("3 remove a scan by serialnumber");
    print("4 display number of times recycled by serialnumber");
    print("5 create new scan list (removes all old data)");
    print();
}

void callAppropriateMethod(int choice, ScanList &scanList)
{
    int serialNumber;
    string message;

    bool successfullyRemoved;
    int numberOfTimesRecycled;

    switch (choice)
    {
    case 1:
        cout << scanList << endl;
        break;
    case 2:
        serialNumber = getIntegerInput("Please enter a serial number: ");
        scanList.addScan(serialNumber);
        break;
    case 3:
        serialNumber = getIntegerInput("Please enter a serial number: ");
        successfullyRemoved = scanList.removeScan(serialNumber);
        message = "successfully removed";

        if (!successfullyRemoved)
        {
            message = "not " + message;
        }

        print();

        message = to_string(serialNumber) + " was " + message;
        print(message);
        break;
    case 4:
        serialNumber = getIntegerInput("Please enter a serial number: ");
        numberOfTimesRecycled = scanList.getTimesRecycled(serialNumber);

        print();

        message = to_string(serialNumber) + " was " + to_string(numberOfTimesRecycled) + " times recycled.";
        print(message);
        break;
    case 5:
        scanList = ScanList();
        break;
    default:
        break;
    }
}
