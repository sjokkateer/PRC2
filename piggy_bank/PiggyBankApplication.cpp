#include <iostream>
#include "PiggyBank.h"
using namespace std;

// One additional file for helper functions probably, that validate the input and such.
void print(const char *message);
void print();
void printGreeting();
void displayMenu();
int getChoiceUntilValid();
bool isEmptyString(string s);
bool isNotInteger(string choiceAsString);
void callAppropriateMethod(int choice, PiggyBank &piggyBank);
string getOwnerName();
int getDepositAmount();

int main()
{
    const int EXIT = 0;
    int choice;
    PiggyBank piggyBank = PiggyBank();

    printGreeting();

    while (true)
    {
        displayMenu();
        choice = getChoiceUntilValid();
        if (choice == EXIT)
            break;
        callAppropriateMethod(choice, piggyBank);
    }

    // goodBye();
    return 0;
}

void print(const char *message)
{
    cout << message << endl;
}

void print()
{
    print("");
}

void printGreeting()
{
    print("Welcome to the piggy bank app.");
    print("Through this app you can interact with your piggy bank.");
    print();
}

void displayMenu()
{
    print("Piggy Bank");
    print("----------");
    print("0 to exit");
    print("1 display owner");
    print("2 set owner");
    print("3 is broken");
    print("4 display balance");
    print("5 deposit money");
    print("6 smash piggy bank");
}

int getChoiceUntilValid()
{
    string choice;

    while (isEmptyString(choice) || isNotInteger(choice))
    {
        cout << "Please provide an integer choice: ";
        cin >> choice;
    }

    return stoi(choice);
}

bool isEmptyString(string s)
{
    if (s.length() == 0)
        return true;

    return false;
}

bool isNotInteger(string choiceAsString)
{
    for (int i = 0; i < choiceAsString.length(); i++)
    {
        if (!isdigit(choiceAsString[i]))
            return true;
    }

    return false;
}

void callAppropriateMethod(int choice, PiggyBank &piggyBank)
{
    string message;
    string owner;
    int balanceAmount;
    int balanceObtained;
    int amountToBeDeposited;
    int isSmashed;

    print();

    // All these procedures could have been used through a class called app or something.
    switch (choice)
    {
    case 1:
        owner = piggyBank.getOwnerName();
        message = "The piggy bank is owned by: ";

        if (isEmptyString(owner))
        {
            message += "no one yet";
        }

        message += owner;
        print(message.c_str());
        break;
    case 2:
        owner = getOwnerName();
        piggyBank.setOwnerName(owner);
        break;
    case 3:
        message = "Piggy bank is";

        if (!piggyBank.isBroken())
            message += " not";

        message += " broken";
        print(message.c_str());
        break;
    case 4:
        balanceObtained = piggyBank.getBalance(balanceAmount);

        if (balanceObtained == 0)
        {
            message = "Current balance: €" + to_string(balanceAmount);
        }
        else
        {
            message = "Piggy bank is broken!";
        }

        print(message.c_str());
        break;
    case 5:
        amountToBeDeposited = getDepositAmount();
        piggyBank.depositMoney(amountToBeDeposited);
        piggyBank.getBalance(balanceAmount);

        message = "Balance after deposit: €" + to_string(balanceAmount);
        print(message.c_str());
        break;
    case 6:
        isSmashed = piggyBank.smash();
        message = "Piggy bank is now broken";

        if (isSmashed < 0)
        {
            message = "Piggy bank is already broken";
        }

        print(message.c_str());
        break;
    default:
        message = "Your choice: " + to_string(choice) + " does not exist.";
        print(message.c_str());
        break;
    }

    print();
}

string getOwnerName()
{
    char name[50];
    string asString;
    // so, while IS integer (double negation)
    // This does however return for ex 1.23 as a name
    while (isEmptyString(asString) || !isNotInteger(asString))
    {
        cout << "Please enter a name for owner: ";
        cin.getline(name, sizeof(name));

        // Cast the character array to a string
        // to test it against the while's expression again for validation
        asString = name;
    }

    return name;
}

int getDepositAmount()
{
    string amount;

    while (isEmptyString(amount) || isNotInteger(amount))
    {
        cout << "Please give an amount to deposit as integer: ";
        cin >> amount;
    }

    return stoi(amount);
}
