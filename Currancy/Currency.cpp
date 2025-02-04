/*
 * Currency.cpp
 *
 * Program ask the user for an amount of money
 * in US dollars and then convert the amount to either
 * Canadian Dollars or Mexican Pesos
 *
 * @Author Chris Pham
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double canada, mexico, money;
    char choice;
    canada = 1.31;
    mexico = 19.97;

    cout << fixed << setprecision(2);

    cout << "How much money do you want to convert?" << endl;
    cin >> money;

    cout << "Are you going to Canada (C) or Mexico (M)?" << endl;
    cin >> choice;

    if (choice == 'C')
    {
        cout << "Your " << money << " US dollars are worth " << (money * canada) << " Canadian dollars" << endl;
    }
    else
    {
        cout << "Your " << money << " US dollars are worth " << (money * mexico) << " Mexican Pesos" << endl;
    }

    return 0;
}

/*
EXECUTION CODE:
How much money do you want to convert?
2
Are you going to Canada (C) or Mexico (M)?
M
Your 2.00 US dollars are worth 39.94 Mexican Pesos
*/