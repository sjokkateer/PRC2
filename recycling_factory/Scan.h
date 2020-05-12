#ifndef SCAN_H
#define SCAN_H

#include <iostream>
using namespace std;

class Scan
{
private:
    int serialNumber;
    int timesRecycled;
    Scan *next;

public:
    Scan(int number);             // post: this->serialNumber == number and this-> timesRecycled == 1
    virtual ~Scan();              // post: object has been destructed
    int getSerialNumber();        // post: this->serialNumber has been returned
    Scan *getNext();              // post: this->next has been returned
    void setNext(Scan *nextScan); // post: this->next == nextScan
    void recycle();               // post: this->timesRecycled has been increased by one
    int getTimesRecycled();       // post: this->timesRecycled has been returned
    friend ostream &operator<<(ostream &out, const Scan &scan)
    {
        string suffix = (scan.timesRecycled == 1) ? "." : "s.";

        out << scan.serialNumber << ": is recycled "
            << scan.timesRecycled << " time"
            << suffix;

        return out;
    }
};

#endif
