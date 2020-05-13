#include <stdio.h>
#include "ScanList.h"
#include "Scan.h"

ScanList::ScanList()
{
    this->scans = NULL;
}

ScanList::~ScanList()
{
    // Delete the head, if head will delete next it will work out recursively.
    if (this->scans != NULL)
    {
        delete this->scans;
    }
}

void ScanList::addScan(int serialNumber)
{
    Scan *current = this->scans;
    Scan *nextScan;

    if (current == NULL || serialNumber < current->getSerialNumber())
    {
        nextScan = new Scan(serialNumber);
        nextScan->setNext(this->scans);
        this->scans = nextScan;
    }
    else
    {
        Scan *scan = NULL;
        Scan *previous = NULL;

        while (current != NULL) // Will always be executed once, once we get here.
        {
            // Alternatively we could have looped until next == NULL or next serialNumber > serialNumber
            if (serialNumber < current->getSerialNumber())
            {
                nextScan = new Scan(serialNumber);
                scan = nextScan;
                scan->setNext(current);

                if (previous != NULL)
                {
                    previous->setNext(scan);
                }
                return;
            }
            else if (serialNumber == current->getSerialNumber())
            {
                current->recycle();
                return;
            }

            previous = current;
            current = current->getNext();
        }

        // It's the new tail.
        nextScan = new Scan(serialNumber);
        scan = nextScan;
        previous->setNext(scan);
    }
}

bool ScanList::removeScan(int serialNumber)
{
    return false;
}

int ScanList::getTimesRecycled(int serialNumber)
{
    return -1;
}
