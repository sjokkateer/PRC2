#include <iostream>
#include <stdio.h>
#include "Scan.h"
#include "ScanList.h"

using namespace std;

int main()
{
    ScanList sl = ScanList();

    sl.addScan(5);
    sl.addScan(5);
    sl.addScan(12);
    sl.addScan(1);
    sl.addScan(1);
    sl.addScan(1);
    sl.addScan(1);
    sl.addScan(1);
    sl.addScan(7);
    sl.addScan(12);
    sl.addScan(12);
    sl.addScan(13);

    sl.removeScan(1);

    sl.addScan(1);

    cout << sl << endl;

    cout << "1 is recycled: "
         << sl.getTimesRecycled(1)
         << " times."
         << endl;

    cout << "7 is recycled: "
         << sl.getTimesRecycled(7)
         << " times."
         << endl;

    cout << "5 is recycled: "
         << sl.getTimesRecycled(5)
         << " times."
         << endl;

    cout << "12 is recycled: "
         << sl.getTimesRecycled(12)
         << " times."
         << endl;

    return 0;
}
