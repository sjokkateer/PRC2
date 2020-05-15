#include <iostream>
#include <fstream>

using namespace std;

#include "Student.h"

int main()
{
    // Student s = Student("barnaby", 23, 1234567);
    // s.addModule("PCS2", 7);
    // s.addModule("PCS1", 8);

    // ofstream outputFile("students.txt");

    // if (outputFile.is_open())
    // {
    //     outputFile << s;
    // }

    // outputFile.close();

    Person p = Person("barnaby", 23);

    cout << p << endl;

    ofstream outputFile("persons.dat", ios::binary);

    if (outputFile.is_open())
    {
        p.store(outputFile);
        outputFile.close();
    }

    // ifstream inputFile("persons.dat", ios::binary);

    // Person newP;

    // if (inputFile.is_open())
    // {
    //     newP.load(inputFile);
    //     inputFile.close();
    // }

    // cout << newP << endl;

    // // Copy constructor is called.
    // Student s2 = s;

    // cout << s << endl;
    // cout << "---- grades ----" << endl;
    // s.showGradeList();

    // cout << endl;

    // // If all went well, changing a grade does not affect the other student's grades
    // s.getGrades()[1]->setGrade(1);

    // cout << s << endl;
    // cout << "---- grades ----" << endl;
    // s.showGradeList();

    // cout << endl;

    // cout << s2 << endl;
    // cout << "---- grades ----" << endl;
    // s2.showGradeList();

    return 0;
}
