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
    ModuleGrade(string moduleName, int moduleGrade);
    void showModule();
};

#endif
