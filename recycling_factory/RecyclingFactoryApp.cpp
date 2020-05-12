#include <iostream>
#include <stdio.h>
#include "Scan.h"

using namespace std;

int main()
{
    Scan s = Scan(1);
    Scan s2 = Scan(2);
    s2.recycle();

    cout << s << endl;
    cout << s2 << endl;

    return 0;
}
