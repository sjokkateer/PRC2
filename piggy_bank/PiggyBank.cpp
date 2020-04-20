#include <iostream>
#include "PiggyBank.h"
using namespace std;

void PiggyBank::init(string name, int startBalance)
{
    owner = name;
    balance = startBalance;
    broken = false;
}

PiggyBank::PiggyBank(void)
{
    init();
}

PiggyBank::PiggyBank(string name)
{
    init(name);
}

PiggyBank::PiggyBank(string name, int startBalance)
{
    init(name, startBalance);
}

string PiggyBank::getOwnerName()
{
    return owner;
}

void PiggyBank::setOwnerName(string name)
{
    owner = name;
}

bool PiggyBank::isBroken()
{
    return broken;
}

int PiggyBank::getBalance(int &amount)
{
    if (!isBroken())
    {
        amount = balance;
        return 0;
    }

    return -1;
}

void PiggyBank::depositMoney(int amount)
{
    if (!isBroken())
    {
        balance += amount;
    }
}

int PiggyBank::smash()
{
    if (!isBroken())
    {
        broken = true;
        return balance;
    }

    return -1;
}

string PiggyBank::toString()
{
    string result = owner + "'s piggy bank ";

    if (isBroken())
    {
        result += " is broken.";
    }
    else
    {
        result += "contains €" + balance + '.';
    }

    return result;
}
