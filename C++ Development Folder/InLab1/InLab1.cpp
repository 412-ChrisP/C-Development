#include <iostream>

using namespace std;

void makeChange(int cents, int &dollars, int &quarters, int &dimes, int &nickels, int &pennies);

int main()
{
    int cents, dollars, quarters, dimes, nickels, pennies;
    cout << "How much change to make (in cents): ";
    cin >> cents;
    makeChange(cents, dollars, quarters, dimes, nickels, pennies);
    cout << "\nYour change is:" << endl
         << dollars << " dollar(s)" << endl
         << quarters << " quarter(s)" << endl
         << dimes << " dime(s)" << endl
         << nickels << " nickel(s)" << endl
         << pennies << " pennie(s)" << endl;
    return 0;
}

void makeChange(int cents, int &dollars, int &quarters, int &dimes, int &nickels, int &pennies)
{
    if (cents < 100)
    {
        dollars = 0;
        quarters = 0;
        dimes = 0;
        nickels = 0;
        pennies = cents;
    }
    else
    {
        dollars = cents / 100;
        quarters = (cents - (dollars * 100)) / 25;
        dimes = (cents - ((dollars * 100) + (quarters * 25))) / 10;
        nickels = (cents - ((dollars * 100) + (quarters * 25) + (dimes * 10))) / 5;
        pennies = (cents - ((dollars * 100) + (quarters * 25) + (dimes * 10) + (nickels * 5)));
    }
}
/* 
EXECUTION CODE: 
How much change to make (in cents): 1292 
Your change is: 
12 dollar(s) 
3 quarter(s) 
1 dime(s) 
1 nickel(s) 
2 pennies 
*/