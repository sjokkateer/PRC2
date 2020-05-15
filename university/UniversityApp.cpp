#include <iostream>
#include <fstream>

using namespace std;

#include "Student.h"

int main()
{
    // Student s = Student("barnaby", 23, 1234567);
    // s.addModule("PCS2", 7);
    // s.addModule("PCS1", 8);

    // ofstream outputFile("students.dat", ios::binary);

    // if (outputFile.is_open())
    // {
    //     s.store(outputFile);
    //     outputFile.close();
    // }

    Student newStudent;

    ifstream inputFile("students.dat");

    if (inputFile.is_open())
    {
        newStudent.load(inputFile);
        inputFile.close();
    }

    cout << newStudent << endl;

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
