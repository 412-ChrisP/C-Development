/*
 * Triangle.cpp
 *
 * author@ ChrisPham
 */
#include <iomanip>
#include <iostream>
#include "Triangle.h"

using namespace std;

int main()
{
    double tempHeight, tempBase;
    tempBase = tempHeight = 0.0;

    do
    {
        cout << "Please enter the base: ";
        cin >> tempBase;

        if (tempBase <= 0)
        {
            cout << "This is an invalid base." << endl;
        }
    }while ( tempBase <= 0);

    do
    {
        cout << "Please enter the height: ";
        cin >> tempHeight;

        if (tempHeight <= 0)
        {
            cout << "This is an invalid height." << endl;
        }
    }while (tempHeight <= 0);

    Triangle triangle(tempBase, tempHeight);

    cout << "The area of the triangle with base " << triangle.getBase() << " and height " << triangle.getHeight() << " is " << triangle.computeArea() << endl;

    return 0;
}
/*
EXECUTION CODE:
Please enter the base: -1
This is an invalid base.
Please enter the base: 1
Please enter the height: -1
This is an invalid height.
Please enter the height: 1
The area of the triangle with base 1 and height 1 is 0.5
 */