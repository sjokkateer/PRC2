#include <iostream>
using namespace std;

void print(string message)
{
    cout << message << endl;
}

void print()
{
    print("");
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

int getIntegerInput(string promptMessage)
{
    string choice;

    while (isEmptyString(choice) || isNotInteger(choice))
    {
        cout << promptMessage;
        cin >> choice;
    }

    return stoi(choice);
}
