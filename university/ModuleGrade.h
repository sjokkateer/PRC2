#ifndef MODULE_GRADE_H
#define MODULE_GRADE_H

#include <iostream>

using namespace std;

class ModuleGrade
{
private:
    string moduleName;
    int moduleGrade;

public:
    ModuleGrade(const ModuleGrade &obj);
    ModuleGrade(string moduleName, int moduleGrade);
    void showModule();
    void setGrade(int newGrade);

    friend ostream &operator<<(ostream &out, const ModuleGrade &moduleGrade)
    {
        out << "Module: " << moduleGrade.moduleName << " Grade: " << moduleGrade.moduleGrade;

        return out;
    }
};

#endif
