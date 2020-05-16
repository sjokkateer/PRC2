#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include <vector>
#include "Student.h"
#include "Group.h"

#define UNIVERSITY_DATA_FILE "university.dat"

class University
{
private:
    vector<Student *> students;
    vector<Group *> groups;
    Student *findStudent(int studentNumber);
    bool write(Student *student);

public:
    ~University();                                            // Remove all dynamic memory
    bool addStudent(int studentNumber, string name, int age); // If not exists add
    bool removeStudent(int studentNumber);                    // if not exists false
    void showStudents();                                      // Only loops over and outputs each student
    bool outputStudent(int studentNumber);                    // Writes the students details to a text file
};

#endif
