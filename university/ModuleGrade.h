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
    ModuleGrade();
    ModuleGrade(const ModuleGrade &obj);
    ModuleGrade(string moduleName, int moduleGrade);
    void showModule();
    void setGrade(int newGrade);

    void store(ofstream &outputFile);
    void load(ifstream &inputFile);

    friend ostream &operator<<(ostream &out, const ModuleGrade &moduleGrade)
    {
        out << moduleGrade.moduleName << ":" << moduleGrade.moduleGrade;

        return out;
    }
};

#endif
