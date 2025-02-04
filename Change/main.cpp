/*
 * Change.cpp
 * Program computes sales tax, total change, and total price
 * @author Chris Pham
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
    double b,c;
    string a;

    cout << "What is the item? \n";
    getline(cin, a);
    cout << "How much did it cost? \n";
    cin >> b;
    cout << "How much was paid? \n" ;
    cin >> c;

    cout << "\nReceipt" << endl;
    cout << a << " $" << b << endl;
    cout << "Tax " << "$" << (b * 0.06) << endl;
    cout << "Total Cost " << "$" << (b + (b * 0.06)) << endl;
    cout << "Amount Given " << "$" << c << endl;
    cout << "Change " << "$" << (c - (b + (b * 0.06))) << endl;

    return 0;
}

/*
EXECUTION CODE :

What is the item?
Glasses
How much did it cost?
52.50
How much was paid?
100

Receipt
Glasses $52.5
Tax $3.15
Total Cost $55.65
Amount Given $100
Change $44.35
 */