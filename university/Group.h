#ifndef GROUP_H
#define GROUP_H

#include <fstream>
#include <vector>
#include "Student.h"

using namespace std;

class Group
{
private:
    // These must be pointers, in case a student is deleted from the app.
    vector<Student *> students;

public:
    void addStudent(Student *student);
    bool removeStudent(int studenNumber);
    vector<Student *> getStudents();

    friend ostream &operator<<(ostream &out, const Group &group)
    {
        for (Student *student : group.students)
        {
            out << *student << endl;
        }

        return out;
    }
};

#endif
