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
    bool removeStudent(Student *student);
    vector<Student *> getStudents();

    friend ostream &operator<<(ostream &out, const Group &group)
    {
        out << "Group: \n";

        for (Student *student : group.students)
        {
            out << *student << endl;
        }

        return out;
    }

    void store(ofstream &outputFile);
    vector<int> load(ifstream &inputFile); // Returns the student numbers of students that were added to this group
};

#endif
