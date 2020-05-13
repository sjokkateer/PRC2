#ifndef HELPERS_H
#define HELPERS_H

#include <iostream>
using namespace std;

void print(string message);
void print();
int getIntegerInput(string promptMessage = "Please provide an integer choice: ");
bool isEmptyString(string s);
bool isNotInteger(string choiceAsString);

#endif
