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
#define BACKUP "piggy_banks_backup.txt"
#define EXIT 0

// Can not be defaulted in the header file
// since there can only be one such value (class wide variable)
int PiggyBank::pbId = loadLastId();

int main()
{
    int choice;
    // Start with a new empty piggy bank object, the id will
    // be 1 larger than largest id that could be found in the file.
    PiggyBank piggyBank = PiggyBank::create();

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

    fstream in;
    ofstream out;
    ofstream backup;

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
        // Quite a long procedure though.
        backup.open(BACKUP, ios_base::app);
        in.open(STORAGE);

        // Assume file is not open because it did not exist
        if (!in.is_open())
        {
            // Thus create the file.
            out.open(STORAGE);
            out.close();

            // re-open as input.
            in.open(STORAGE);
        }

        // If both the backup file and the original storage file are open.
        if (backup.is_open() && in.is_open())
        {
            // Flag to test if the piggy bank already exists in original storage
            // Originally we assume it does not yet exist.
            bool alreadyExists = false;

            // Load in an object
            while (in >> storedPiggies)
            {
                // Check ids for equal piggy banks.
                if (storedPiggies.getNumber() == piggyBank.getNumber())
                {
                    // Write the new piggy to backup instead of the old
                    // object in storage.
                    backup << piggyBank;
                    // Indicate it already existed.
                    alreadyExists = true;
                }
                else
                {
                    backup << storedPiggies;
                }
            }

            // Meaning it did not exist inside the old storage file
            // and thus we can safely assume this is the newest
            // object and append it to the backup file.
            if (alreadyExists == false)
            {
                backup << piggyBank;
            }
        }

        in.close();
        out.close();
        // Finally, override the old storage file with our newly generated 'backup' file
        rename(BACKUP, STORAGE);

        break;
    case 6:
        in.open(STORAGE);
        // Write to backup first, then check the original file.
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
        // Lets give the user the option
        // to choose 1, 2, 3, any other int to exit
        // to create from name, or from name and initial amount.
        piggyBank = PiggyBank::create();
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
        piggyId = temp.getNumber();
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
