#ifndef PIGGY_BANK_H
#define PIGGY_BANK_H

#include <iostream>
using namespace std;

class PiggyBank
{
private:
    string owner; // PiggyBank owner
    int balance;  // Current balance in PiggyBank
    bool broken;  // true if PiggyBank is broken, else false

    void init(string name = "", int startBalance = 0);

public:
    PiggyBank(void);                          /* post: a PiggyBank object is created, owner equals "",broken is false, balance is 0*/
    PiggyBank(string name);                   /* post: a PiggyBank object is created, owner equals name,broken is false, balance is 0*/
    PiggyBank(string name, int startBalance); /* post: a PiggyBank object is created, owner equals name,broken is false, balance is startBalance*/

    string getOwnerName();          /* post: the PiggyBank owner's name is returned*/
    void setOwnerName(string name); /* post: the PiggyBank owner's name is set to name*/

    bool isBroken(); /* the value of broken is returned */

    int getBalance(int &amount); /* if !broken then 0 is returned and amount = PiggyBanks balance else -1 is returned*/

    void depositMoney(int amount); /* post: if !broken then amount is added to PiggyBanksbalanceelse nothing has changed*/

    int smash(); /* pre : PiggyBank is not brokenpost: return current balance and PiggyBank is broken*/

    string toString();
};

#endif
