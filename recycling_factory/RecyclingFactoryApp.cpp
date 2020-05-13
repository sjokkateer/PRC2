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

    cout << sl << endl;

    return 0;
}
