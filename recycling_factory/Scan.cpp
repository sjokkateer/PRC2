#include <stdio.h>
#include "Scan.h"

Scan::Scan(int number)
{
    this->serialNumber = number;
    this->timesRecycled = 1;
    this->next = NULL;
}

Scan::~Scan()
{
    // This object is supposedly the tail if next is null.
    if (this->next != NULL)
    {
        delete this->next;
    }
}

int Scan::getSerialNumber()
{
    return this->serialNumber;
}

Scan *Scan::getNext()
{
    return this->next;
}

void Scan::setNext(Scan *nextScan)
{
    this->next = nextScan;
}

void Scan::recycle()
{
    this->timesRecycled++;
}

int Scan::getTimesRecycled()
{
    return this->timesRecycled;
}
