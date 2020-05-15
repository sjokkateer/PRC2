#include "Person.h"

Person::Person()
{
    this->name = "unknown";
    this->age = -1;
}

Person::Person(const Person &obj)
{
    this->name = obj.name;
    this->age = obj.age;
}

Person::Person(string name, int age)
{
    this->name = name;
    this->age = age;
}

string Person::print() const
{
    return this->name + " " + to_string(this->age);
}

void Person::store(ofstream &outFile)
{
    // Cast int pointer to char * and write it to file with size.
    outFile.write(reinterpret_cast<char *>(&this->age), sizeof(this->age));

    // Store name
    int nameLength = this->name.length();

    outFile.write(reinterpret_cast<char *>(&nameLength), sizeof(int));
    // data method of string returns pointer to the character array represented by the value of string.
    // This is however not prepended with the \0 termination character.
    // We store the length before the actual data.

    // I wrote sizeof(nameLength) initially lol.
    // The problem was that the size of namelength was 4 (bytes) the size of an int
    // and thus on reading we got barn instead of barnaby.
    outFile.write(this->name.data(), nameLength);
}

void Person::load(ifstream &inputFile)
{
    inputFile.read(reinterpret_cast<char *>(&this->age), sizeof(this->age));

    const int BUFFER_SIZE = 256;
    static char buffer[BUFFER_SIZE]; //used to read names, static to only have one such.

    int nameLength;
    inputFile.read(reinterpret_cast<char *>(&nameLength), sizeof(int));

    inputFile.read(buffer, nameLength);
    buffer[nameLength] = '\0';
    this->name = buffer;
}

Person &Person::operator=(const Person &person)
{
    if (this == &person)
    {
        return *this;
    }

    this->name = person.name;
    this->age = person.age;

    return *this;
}
