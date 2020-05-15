#include <fstream>
#include "ModuleGrade.h"

ModuleGrade::ModuleGrade()
{
    this->moduleName = "unknown";
    this->moduleGrade = -1;
}

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

void ModuleGrade::store(ofstream &outputFile)
{
    // first the grade cause easier.
    outputFile.write(reinterpret_cast<char *>(&this->moduleGrade), sizeof(this->moduleGrade));

    // then the module name length
    int moduleNameLength = this->moduleName.length();
    outputFile.write(reinterpret_cast<char *>(&moduleNameLength), sizeof(moduleNameLength));

    // followed by the actual string data.
    outputFile.write(this->moduleName.data(), moduleNameLength);
}

void ModuleGrade::load(ifstream &inputFile)
{
    inputFile.read(reinterpret_cast<char *>(&this->moduleGrade), sizeof(this->moduleGrade));

    const int BUFFER_SIZE = 256;
    static char buffer[BUFFER_SIZE];

    int moduleNameLength;
    inputFile.read(reinterpret_cast<char *>(&moduleNameLength), sizeof(moduleNameLength));

    inputFile.read(buffer, moduleNameLength);
    buffer[moduleNameLength] = '\0';

    this->moduleName = buffer;
}
