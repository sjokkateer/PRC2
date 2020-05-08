#include <iostream>
#include "PiggyBank.h"
using namespace std;

void PiggyBank::init(string name, int startBalance)
{
    id = ++pbId;

    owner = name;
    balance = startBalance;
    broken = false;
}

PiggyBank::PiggyBank()
{
    // Default constructor only as place holder
    this->id = -1;
    this->owner = "unknown";
    this->balance = -1;
}

PiggyBank::PiggyBank(string name)
{
    init(name, 0);
}

PiggyBank::PiggyBank(string name, int startBalance)
{
    init(name, startBalance);
}

PiggyBank PiggyBank::create()
{
    return PiggyBank::createFrom("", 0);
}

PiggyBank PiggyBank::createFrom(string ownerName)
{
    return PiggyBank(ownerName);
}

PiggyBank PiggyBank::createFrom(string ownerName, int startBalance)
{
    return PiggyBank(ownerName, startBalance);
}

PiggyBank::~PiggyBank()
{
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

bool PiggyBank::belongsTo(int id)
{
    return id == this->id;
}

string PiggyBank::toString()
{
    string result = owner + "'s piggy bank ";

    if (owner.length() == 0)
    {
        result = "no one" + result;
    }

    result = " (" + to_string(id) + ") " + result;

    if (isBroken())
    {
        result += "is broken.";
    }
    else
    {
        result += "contains €" + to_string(balance) + '.';
    }

    return result;
}

int PiggyBank::getId()
{
    return PiggyBank::pbId;
}

int PiggyBank::getNumber()
{
    return this->id;
}
