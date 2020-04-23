#include <iostream>
#include <fstream>
#include "PiggyBank.h"
using namespace std;

void print(string message);
void print();
void printGreeting();
void displayMenu();
int getChoiceUntilValid();
bool isEmptyString(string s);
bool isNotInteger(string choiceAsString);
void callAppropriateMethod(int choice, PiggyBank &piggyBank);
string getOwnerName();
int getDepositAmount();
int loadLastId();
int getMaxId(ifstream &in);
void getPiggyBankById(PiggyBank &piggyBank);
int getId();
void getPiggyBankFromFile(int id, PiggyBank &piggyBank);

#define STORAGE "piggy_banks.txt"
#define EXIT 0

// Can not be defaulted in the header file
// since there can only be one such value (class wide variable)
int PiggyBank::pbId;

int main()
{
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

void print(string message)
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
    print("1 display details");
    print("2 set owner");
    print("3 deposit money");
    print("4 smash piggy bank");
    print("5 store current piggy bank");
    print("6 display stored piggy banks");
    print("7 create new piggy bank");
    print("8 select piggy bank by id");
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
    PiggyBank storedPiggies;

    string message;
    string owner;
    int balanceAmount;
    int balanceObtained;
    int amountToBeDeposited;
    int isSmashed;

    ifstream in;
    ofstream out;

    print();

    switch (choice)
    {
    case 1:
        print("Details:");
        print(piggyBank.toString());
        break;
    case 2:
        owner = getOwnerName();
        piggyBank.setOwnerName(owner);
        break;
    case 3:
        amountToBeDeposited = getDepositAmount();
        piggyBank.depositMoney(amountToBeDeposited);
        piggyBank.getBalance(balanceAmount);

        message = "Balance after deposit: €" + to_string(balanceAmount);
        print(message);
        break;
    case 4:
        isSmashed = piggyBank.smash();
        message = "Piggy bank is now broken";

        if (isSmashed < 0)
        {
            message = "Piggy bank is already broken";
        }

        print(message);
        break;
    case 5:

        out.open(STORAGE, ios_base::app);

        if (out.is_open())
        {
            out << piggyBank;
            out.close();
        }

        break;
    case 6:
        in.open(STORAGE);

        if (in.is_open())
        {
            while (in >> storedPiggies)
            {
                print(storedPiggies.toString());
            }

            in.close();
        }

        break;
    case 7:
        piggyBank = PiggyBank();
        cout << piggyBank << endl;
        break;
    case 8:
        getPiggyBankById(piggyBank);
        break;
    default:
        message = "Your choice: " + to_string(choice) + " does not exist.";
        print(message);
        break;
    }

    print();
}

string getOwnerName()
{
    string name;
    // This does however return for ex 1.23 as a name
    while (isEmptyString(name) || !isNotInteger(name))
    {
        cout << "Please enter a name for owner: ";
        getline(cin, name);
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

int loadLastId()
{
    ifstream in(STORAGE);

    if (in.is_open())
    {
        return getMaxId(in);
    }

    return 0;
}

int getMaxId(ifstream &in)
{
    int maxId = 0;
    int piggyId;
    PiggyBank temp;

    while (in >> temp)
    {
        // piggyId = temp.getId();
        if (piggyId > maxId)
        {
            maxId = piggyId;
        }
    }

    in.close();
    return maxId;
}

void getPiggyBankById(PiggyBank &piggyBank)
{
    int id = getId();

    getPiggyBankFromFile(id, piggyBank);
}

int getId()
{
    string id;

    while (isEmptyString(id) || isNotInteger(id))
    {
        cout << "Please provide a piggy bank id: ";
        cin >> id;
    }

    return stoi(id);
}

void getPiggyBankFromFile(int id, PiggyBank &piggyBank)
{
    ifstream in(STORAGE);

    if (in.is_open())
    {
        PiggyBank temp;
        while (in >> temp)
        {
            if (temp.belongsTo(id))
            {
                piggyBank = temp;
                break;
            }
        }

        in.close();
    }
}
