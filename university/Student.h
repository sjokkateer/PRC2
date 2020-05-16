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
    Student();
    Student(const Student &obj);
    Student(string name, int age, int studentNumber);
    ~Student();
    void addModule(string moduleName, int moduleGrade);
    void showGradeList();
    vector<ModuleGrade *> getGrades();
    int getStudentNumber();

    void store(ofstream &outFile);
    void load(ifstream &inFile);

    string print() const;
    Student &operator=(const Student &student);

    friend ostream &operator<<(ostream &out, const Student &student)
    {
        out << student.print() << "\n";

        // Also output the collection of grades.
        for (int i = 0; i < student.gradeList.size(); i++)
        {
            // Write the objects, not the memory addresses
            out << *(student.gradeList[i]);

            if (i < student.gradeList.size() - 1)
            {
                out << ", ";
            }
        }

        return out;
    }

    // friend istream &operator>>(istream &in, Student &student)
    // {
    //     in >> student.studentNumber;
    // }
};

#endif
