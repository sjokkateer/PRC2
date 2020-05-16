#include <iostream>
#include <fstream>

using namespace std;

#include "Student.h"
#include "Group.h"

int main()
{
    Group g = Group();
    Student s1 = Student("barnaby", 23, 1234567);
    Student s2 = Student("kill face", 43, 133713337);
    Student s3 = Student("xander", 35, 1333333);

    g.addStudent(s1);
    g.addStudent(s2);
    g.addStudent(s3);

    cout << g << endl;

    g.removeStudent(133713337);

    // So a higher level management class will take responsibility
    // of the literal removal of students and dangling pointers.
    // delete &s2;

    cout << g << endl;

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
