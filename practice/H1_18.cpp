#include <iostream>
using namespace std;

int calculateA();
int calculateB();
int calculateC();
int calculateD();
void outputAnswerTo(char subQuestion);

// const double CENTIMETER_PER_INCH = 2.54;
const int NUMBER_OF_SUB_QUESTIONS = 4;
const char SUB_QUESTION[NUMBER_OF_SUB_QUESTIONS] = {'A', 'B', 'C', 'D'};

int main()
{
    for (int i = 0; i < NUMBER_OF_SUB_QUESTIONS; i++)
    {
        outputAnswerTo(SUB_QUESTION[i]);
    }

    return 0;
}

void outputAnswerTo(char subQuestion)
{
    cout << "The answer to " << subQuestion << " = ";

    switch (subQuestion)
    {
    case 'A':
        cout << calculateA();
        break;
    case 'B':
        cout << calculateB();
        break;
    case 'C':
        cout << calculateC();
        break;
    case 'D':
        cout << calculateD();
        break;
    default:
        break;
    }

    cout << endl;
}

int calculateA()
{
    // Should return 6 + (5 / 4) - 3
    // 6 + 1 - 3 = 4
    return 6 + 5 / 4 - 3;
}

int calculateB()
{
    // 2 + 2 * 2 % 2 / 2
    // 2 + 4 % 2 / 2
    // 2
    return 2 + 2 * (2 * 2 - 2) % 2 / 2;
}

int calculateC()
{
    // 10 + 9 * (15 % 6) + 5 * 4 % 3 * 2 + 1
    // 10 + 9 * 3 + 5 * 4 % 3 * 2 + 1
    // 10 + 27 + 5 * 4 % 3 * 2 + 1
    // 10 + 27 + 20 % 3 * 2 + 1
    // 10 + 27 + 2 * 2 + 1
    // 10 + 27 + 4 + 1
    // 42
    return 10 + 9 * ((8 + 7) % 6) + 5 * 4 % 3 * 2 + 1;
}

int calculateD()
{
    // 1 + 2 + 7 * 7 - 10
    // 1 + 2 + 49 - 10
    // 42
    return 1 + 2 + (3 + 4) * ((5 * 6 % 7 * 8) - 9) - 10;
}
