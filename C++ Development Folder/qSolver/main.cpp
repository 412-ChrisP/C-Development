/*
 * qSolver.cpp
 * Program is a quadratic solver
 * @author Chris Pham
 */

#include <iostream>
#include <tgmath.h>
using namespace std;

int main()
{
    double a,b,c,x,y;

    cout << "What is the a term";
    cin >> a;
    cout << "What is the b term";
    cin >> b;
    cout << "What is the c term";
    cin >> c;
    cout << "What is value of x";
    cin >> x;

    y = a*pow(x,2.0)+b*x+c;

    cout << "For the equation " << a << "x^2 + " << b << "x + " << c << ", when x is " << x << ", y is " << y;

    return 0;
}

/*
 * EXECUTION PROGRAM
 * What is the a term1
 *What is the b term2
 *What is the c term3
 *What is value of x1
 *For the equation 1x^2 + 2x + 3, when x is 1, y is 6
 */
