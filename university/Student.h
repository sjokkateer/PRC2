#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include "ModuleGrade.h"
#include <iostream>
#include <vector>

using namespace std;

class Student : public Person
{
private:
    int studentNumber;
    vector<ModuleGrade *> gradeList;

public:
    Student(const Student &obj);
    Student(string name, int age, int studentNumber);
    ~Student();
    void addModule(string moduleName, int moduleGrade);
    void showGradeList();
    vector<ModuleGrade *> getGrades();
    string print() const;
    Student &operator=(const Student &student);

    friend ostream &operator<<(ostream &out, const Student &student)
    {
        out << student.print() << "\n";

        // Also output the collection of grades.
        for (ModuleGrade *grade : student.gradeList)
        {
            // Write the objects, not the memory addresses
            out << *grade << ",";
        }

        out << endl;

        return out;
    }

    // friend istream &operator>>(istream &in, Student &student)
    // {
    //     in >> student.studentNumber;
    // }
};

#endif
