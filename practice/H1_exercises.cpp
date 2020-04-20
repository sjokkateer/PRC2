#include <iostream>
using namespace std;

void convertCelciusToFahrenheit();
double celciusToFahrenheit(double celcius);
void convertMetersToEnglishDistance();
void metersToEnglishDistance(double meters);
void calculateSumOfNIntegerSequence();
int sumOfNIntegerSequence(int n);
void calculateSumOfFirstNOddIntegers();
int sumOfFirstNOddIntegers(int n);
bool isOdd(int number);
void findLargestIntegerInAList();
void findLargestTwoIntegersInAList();
void displayDigitsInReverse();
void reverseDigits(int n);

const double INCH_IN_METERS = 0.0254;
const int FOOT_IN_INCHES = 12;

int main()
{
    displayDigitsInReverse();
    return 0;
}

void displayDigitsInReverse()
{
    cout << "This program reverses the digits in an integer." << endl;
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    while (n < 0)
    {
        cout << "Enter a positive integer: ";
    }

    reverseDigits(n);
}

void reverseDigits(int n)
{
    // Print remained, integer divide the number by 10
    // for as long as the number > 0
    cout << "The reversed integer is ";

    while (n > 0)
    {
        cout << n % 10;
        n /= 10;
    }

    cout << endl;
}

void findLargestTwoIntegersInAList()
{
    cout << "This program finds the two largest integer in a list." << endl;
    cout << "Enter 0 to signal the end of the list." << endl;

    const int SENTINEL_VALUE = 0;

    int MAXIMA[] = {0, 0};
    int number;

    while (true)
    {
        cout << "? ";
        cin >> number;

        if (number == SENTINEL_VALUE)
            break;

        if (number >= MAXIMA[0])
        {
            MAXIMA[1] = MAXIMA[0];
            MAXIMA[0] = number;
        }
        else if (number > MAXIMA[1])
        {
            MAXIMA[1] = number;
        }
    }

    cout << "The largest value was " << MAXIMA[0] << endl;
    cout << "The second largest value was " << MAXIMA[1] << endl;
}

void findLargestIntegerInAList()
{
    cout << "This program finds the largest integer in a list." << endl;
    cout << "Enter 0 to signal the end of the list." << endl;

    const int SENTINEL_VALUE = 0;

    int number;
    int max = 0;

    while (true)
    {
        cout << "? ";
        cin >> number;

        if (number == SENTINEL_VALUE)
            break;

        if (number > max)
        {
            max = number;
        }
    }

    cout << "The largest value was " << max << endl;
}

void calculateSumOfFirstNOddIntegers()
{
    cout << "Enter a positive integer: ";
    int n;
    cin >> n;

    while (n <= 0)
    {
        cout << "Enter a positive integer: ";
        cin >> n;
    }

    cout << "The sum of the first " << n << " odd numbers = " << sumOfFirstNOddIntegers(n) << endl;
}

int sumOfFirstNOddIntegers(int n)
{
    int sum = 0;
    int currentNumber = 1;

    while (true)
    {
        if (n < 1)
            break;

        if (isOdd(currentNumber))
        {
            sum += currentNumber;
            n--;
        }

        currentNumber++;
    }

    return sum;
}

bool isOdd(int number)
{
    return number % 2 == 1;
}

void calculateSumOfNIntegerSequence()
{
    cout << "Enter an integer: ";
    int n;
    cin >> n;

    cout << "The sum of 1 to " << n << " = " << sumOfNIntegerSequence(n) << endl;
}

int sumOfNIntegerSequence(int n)
{
    int result = 0;

    for (int i = 1; i <= n; i++)
    {
        result += i;
    }

    // (1 + n) * n / 2
    return result;
}

void convertMetersToEnglishDistance()
{
    double meters;
    cout << "Meters as double: ";
    cin >> meters;
    metersToEnglishDistance(meters);
}

void metersToEnglishDistance(double meters)
{
    double numberOfInches = meters / INCH_IN_METERS;
    int leftOverInches = (int)numberOfInches % FOOT_IN_INCHES;
    int numberOfFeet = numberOfInches / FOOT_IN_INCHES;

    cout << meters << " is " << numberOfFeet << " feet and " << leftOverInches << " inches " << endl;
}

void convertCelciusToFahrenheit()
{
    double celcius;
    cout << "Degrees ceclius as double: ";
    cin >> celcius;
    cout << "Fahrenheit: " << celciusToFahrenheit(celcius) << endl;
}

double celciusToFahrenheit(double celcius)
{
    return 9 / 5.0 * celcius + 32;
}
