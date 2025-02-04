#include <iostream>

using namespace std;

int main()
{
    double *fPtr = nullptr;
    double number1 = 7.3;
    double object = 0;
    *fPtr = object;
    &number1 = *fPtr;

    cout << object << endl;
    cout << number1 << endl;

    double number2;
    number2 = *fPtr;

    cout << number2 << endl;
    cout << &number1 << endl;
    cout << &fPtr << endl;

    return 0;
}
