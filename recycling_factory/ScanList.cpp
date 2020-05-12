#include <stdio.h>
#include "ScanList.h"

ScanList::ScanList()
{
    // But we could use a nullptr since scans is a pointer.
    this->scans = NULL;
}

ScanList::~ScanList()
{
    // Delete all scan objects in the linked list.
}

void addScan(int serialNumber)
{
    // Serial numbers are in ascending order.
}

bool removeScan(int serialNumber)
{
    return false;
}

int getTimesRecycled(int serialNumber)
{
    return -1;
}
