#include <iostream>
#include "PiggyBank.h"
using namespace std;

int main()
{
    PiggyBank pb = PiggyBank("Remy", 5);
    int balance;
    pb.getBalance(balance);

    cout << "Piggy bank's balance = " << balance << endl;

    return 0;
}
