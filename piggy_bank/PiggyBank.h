#ifndef PIGGY_BANK_H
#define PIGGY_BANK_H

#include <iostream>
using namespace std;

#define DELIM '\n'

class PiggyBank
{
private:
    static int pbId;

    int id;       // unique id to identify the object
    string owner; // PiggyBank owner
    int balance;  // Current balance in PiggyBank
    bool broken;  // true if PiggyBank is broken, else false

    void init(string name, int startBalance);

public:
    PiggyBank();                              /* post: a PiggyBank object is created, owner equals "",broken is false, balance is 0*/
    PiggyBank(string name);                   /* post: a PiggyBank object is created, owner equals name,broken is false, balance is 0*/
    PiggyBank(string name, int startBalance); /* post: a PiggyBank object is created, owner equals name,broken is false, balance is startBalance*/

    ~PiggyBank(); /* Destruct the object */

    string getOwnerName();          /* post: the PiggyBank owner's name is returned*/
    void setOwnerName(string name); /* post: the PiggyBank owner's name is set to name*/

    bool isBroken(); /* the value of broken is returned */

    int getBalance(int &amount); /* if !broken then 0 is returned and amount = PiggyBanks balance else -1 is returned*/

    void depositMoney(int amount); /* post: if !broken then amount is added to PiggyBanksbalanceelse nothing has changed*/

    int smash(); /* pre : PiggyBank is not brokenpost: return current balance and PiggyBank is broken*/

    bool belongsTo(int id); /* used to check whether this id belongs to the piggy under investigation */

    string toString(); /* Returns the object's string representation */

    static int getId(); /* Returns the unique identifier */

    // Ofstream inherits from ostream, thus can also be used.
    friend ostream &operator<<(ostream &out, const PiggyBank &piggyBank) /* Overload the << operator to serialize object to file */
    {
        // \n doesnt flush the buffer whereas endl does.
        out << piggyBank.id << DELIM
            << piggyBank.owner << DELIM
            << piggyBank.balance << DELIM
            << piggyBank.broken << endl;

        return out;
    }

    friend istream &operator>>(istream &in, PiggyBank &piggyBank) /* Overload the >> operator to deserialize the object from file */
    {
        in >> piggyBank.id;
        // Ignore the newline character
        in.ignore();
        // Otherwise getline will immediatly exit since it encounters the newline char as first char.
        getline(in, piggyBank.owner);
        in >> piggyBank.balance >> piggyBank.broken;

        return in;
    }
};

#endif
