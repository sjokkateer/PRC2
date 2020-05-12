#ifndef SCAN_LIST_H
#define SCAN_LIST_H

#include "Scan.h"

class ScanList
{
private:
    Scan *scans; // pointer to linked list of Scans
public:
    ScanList();                             // post: this->scans is empty
    virtual ~ScanList();                    // post: all scans have been destructed
    void addScan(int serialNumber);         // pre: serialNumbers are in ascending order in linked list scans
                                            // post: IF serialNumberis not present in the list
                                            // THEN a new scan with serialNumber has been added in the right place
                                            // ELSE its timesRecycled has been increased by one
    bool removeScan(int serialNumber);      // post: IF serialNumber is present in the list
                                            // THEN scan has been removed from it and true has been returned
                                            // ELSE false has been returned
    int getTimesRecycled(int serialNumber); // post: IF a scan with serialNumber is present in the list
                                            // THEN returns the value of timesRecycled of that scan // ELSE returns 0
};

#endif
