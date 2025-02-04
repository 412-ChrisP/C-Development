// driver for project 5
#include <iostream>
#include "Frac2.h"

using namespace std;

int main()
{
    Fraction c(7, 3), d(3, 9), x;
//   c.printFraction();
    cout << c;
    cout << " + ";
//  d.printFraction();
    cout << d;
    cout << " = ";
    x = c + d;
//   x.printFraction();
    cout << x;
    cout << '\n';
//   c.printFraction();
    cout << c;
    cout << " - ";
//   d.printFraction();
    cout << d;
    cout << " = ";
    x = c - d;
//   x.printFraction();
    cout << x;
    cout << '\n';
//   c.printFraction();
    cout << c;
    cout << " * ";
//   d.printFraction();
    cout << d;
    cout << " = ";
    x = c * d;
//   x.printFraction();
    cout << x;
    cout << '\n';
//   c.printFraction();
    cout << c;
    cout << " / ";
//   d.printFraction();
    cout << d;
    cout << " = ";
    x = c / d;
//   x.printFraction();
    cout << x;
    cout << '\n';
//   c.printFraction();
    cout << c;
    cout << " is:\n";
    cout << ((c > d) ? "  > " : "  <= ");
//   d.printFraction();
    cout << d;
    cout << " according to the overloaded > operator\n";
    cout << ((c < d) ? "  < " : "  >= ");
//   d.printFraction();
    cout << d;
    cout << " according to the overloaded < operator\n";
/* uncomment this line for improved version
//   c.printFraction();
cout << c;
cout << " + ";
//   d.printFraction();
cout << c;
cout << " / ";
cout << d;
cout << " - ";
cout << d;
cout << " * ";
cout << c;
cout << " = ";
x = c + c / d - d * c; // cascading use of operators
//   x.printFraction();
cout << x;
cout << '\n';
*/  // uncomment this line for improve version
#ifdef _WIN32          // _WIN32 is used by visual C++
#if (_MSC_VER <= 1916)// check if it Visual Studio 2017 and earlier
    system("pause");
#endif
#endif
    return 0;
}

