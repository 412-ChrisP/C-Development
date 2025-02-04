// CMPSC122
// Please do not modify this file!
// --- Program to test BigInt class.
// Modified from textbook Larry Nyhoff, ADTs, Data Structures, and Problem
// Solving with C++, 2nd ed., Prentice-Hall
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;
#include "BigInt.h"
void displayResult(BigInt bigInt1, BigInt bigInt2, BigInt bigInt3,
                   char op, BigInt answer)
{
    const int WIDTH = 18;
    string ul(WIDTH + 1, '-'), dul(WIDTH + 1, '=');
    cout << " " << setw(WIDTH) << bigInt1 << endl
         << op << setw(WIDTH) << bigInt2 << endl
         << ul << endl
         << " " << setw(WIDTH) << bigInt3 << endl
         << dul << endl << endl;
    if (bigInt3 == answer)
        return;
    cerr << "Incorrect result: " << bigInt3 << endl;
    cerr << "Correct answer: " << answer << endl << endl;
}
int main()
{
    BigInt zeroBigInt;
    cout << "Test for default constructor: " << endl;
    cout << "zeroBigInt = " << zeroBigInt << endl << endl;
    cout << "Test combination of BigInt's arithmetics: " << endl;
    BigInt bigInt1(874632288);
    BigInt bigInt2(49833212);
    BigInt bigInt3 = bigInt1 + bigInt2;
    displayResult(bigInt1, bigInt2, bigInt3, '+', BigInt(924465500));
    displayResult(bigInt1, bigInt2, bigInt1 - bigInt2, '-', BigInt(824799076));
    displayResult(bigInt2, bigInt1, bigInt2 - bigInt1, '-', BigInt(-824799076));
    bigInt1 = 683993;
    bigInt2 = -4383773;
    displayResult(bigInt1, bigInt2, bigInt1 + bigInt2, '+', BigInt(-3699780));
    displayResult(bigInt1, bigInt2, bigInt1 - bigInt2, '-', BigInt(5067766));
    displayResult(bigInt2, bigInt1, bigInt2 - bigInt1, '-', BigInt(-5067766));
    bigInt1 = -973683993;
    bigInt2 = -43768489;
    displayResult(bigInt1, bigInt2, bigInt1 + bigInt2, '+', BigInt(-1017452482));
    displayResult(bigInt1, bigInt2, bigInt1 - bigInt2, '-', BigInt(-929915504));
    displayResult(bigInt2, bigInt1, bigInt2 - bigInt1, '-', BigInt(929915504));
    cout << "Test for manual input for BigInt: " << endl;
    char response;
    do
    {
        BigInt number1, number2;
        cout << "Enter a big integer: " << endl;
        cin >> number1;
        cout << "number1 = " << number1 << endl;
        cout << "Enter another big integer: " << endl;
        cin >> number2;
        cout << "number2 = " << number2 << endl;
// original one: test the addition operation +
        cout << "The sum of " << number1 << " + " << number2
             << " = " << number1 + number2 << endl << endl;
// 1. test the less than operation <
        cout << "The bigger number of " << number1 << " and " << number2
             << " is " << ((number1 < number2) ? number2 : number1) << endl <<
             endl;
// 2. test the subtract operation -
        cout << "The subtraction of " << number1 << " - " << number2
             << " = " << number1 - number2 << endl << endl;
        cout << "Add more integers (Y or N)? ";
        cin >> response;
    } while (response == 'y' || response == 'Y');
    stringstream ss("181 446 744 073 709 551 615 847 393 398 391 3 455 0 777 202 111 99 182 892 12 299 393 827 0 0 0 237 393 123 393 -9999");
    BigInt bigInt;
    ss >> bigInt;
    cout << endl << endl;
    cout << "Test and display a very large BigInt number (number will wrap after 20 blocks): " << endl;
    cout << bigInt << endl;
    return 0;
}
