#include <iostream>

using namespace std;

#include "Student.h"

int main()
{
    Student s = Student("barnaby", 23, 1234567);
    s.addModule("PCS2", 7);
    s.addModule("PCS1", 8);

    // Copy constructor is called.
    Student s2 = s;

    cout << s << endl;
    cout << "---- grades ----" << endl;
    s.showGradeList();

    cout << endl;

    s.getGrades()[1]->setGrade(1);

    cout << s << endl;
    cout << "---- grades ----" << endl;
    s.showGradeList();

    cout << endl;

    cout << s2 << endl;
    cout << "---- grades ----" << endl;
    s2.showGradeList();

    return 0;
}
