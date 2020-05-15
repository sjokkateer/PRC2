#include "ModuleGrade.h"

ModuleGrade::ModuleGrade(const ModuleGrade &obj)
{
    this->moduleName = obj.moduleName;
    this->moduleGrade = obj.moduleGrade;
}

ModuleGrade::ModuleGrade(string moduleName, int moduleGrade)
{
    this->moduleName = moduleName;
    this->moduleGrade = moduleGrade;
}

void ModuleGrade::setGrade(int newGrade)
{
    this->moduleGrade = newGrade;
}

void ModuleGrade::showModule()
{
    cout << *this << endl;
}
