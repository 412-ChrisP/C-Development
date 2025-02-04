/*
 * UniversalTicket.cpp
 *
 * Program prompt the user for
 * the number of days they want to go to Universal
 * also prompt them if they would like Express Pass or not
 * and output a receipt for the transaction
 *
 * @author Chris Pham
 */

#include <iostream>
#include <iomanip>

using namespace std; 

int main()
{
    double totalticketcost,daysattending,expresspasscost;
    char expresspass, premierResort;

    totalticketcost = 100;
    expresspasscost = 79;

    cout << fixed << setprecision(2);

    cout << "Welcome to Universal Studios! \n" << endl;

    cout << "How many days are you attending?" << endl;
    cin >> daysattending;

    cout << "Do you want Express Pass?" << endl;
    cin >> expresspass;

    if (expresspass == 'Y' || expresspass == 'Yes')
    {
        cout << "Are you staying at a Premier Resort?" << endl;
        cin >> premierResort;

        if (expresspass == 'Y' && premierResort == 'Y')
        {
            cout << "RECEIPT \n------------------------" << endl;

            cout << "Total Ticket Cost $" << totalticketcost * daysattending << endl;

            cout << "\nExpress Pass FREE " << endl;

            cout << "\nTOTAL COST $" << totalticketcost << endl;
        }
        else if (expresspass == 'Y' && premierResort == 'N')
        {
            cout << "RECEIPT \n------------------------" << endl;

            cout << "Total Ticket Cost $" << totalticketcost * daysattending << endl;

            cout << "\nExpress Pass $" << expresspasscost << endl;

            cout << "\nTOTAL COST $" << expresspasscost + (totalticketcost * daysattending) << endl;
        }
        else
        {
            cout << "\n" << endl;

            cout << "\nTOTAL COST $" << expresspasscost + (totalticketcost * daysattending) << endl;
        }



        return 0;
    }
    else
    {
        cout << "RECEIPT \n------------------------" << endl;

        cout << "Total Ticket Cost $" << totalticketcost * daysattending << endl;

        cout << "\nTOTAL COST $" << totalticketcost << endl;
        return 0;
    }

}

/*
EXECUTION CODE:

Output #1
Welcome to Universal Studios!

How many days are you attending?
1
Do you want Express Pass?
Y
Are you staying at a Premier Resort?
N
RECEIPT
------------------------
Total Ticket Cost $100.00

Express Pass $79.00

TOTAL COST $179.00


Output #2
Welcome to Universal Studios!

How many days are you attending?
1
Do you want Express Pass?
Y
Are you staying at a Premier Resort?
Y
RECEIPT
------------------------
Total Ticket Cost $100.00

Express Pass FREE

TOTAL COST $100.00


Output #3
Welcome to Universal Studios!

How many days are you attending?
1
Do you want Express Pass?
N
RECEIPT
------------------------
Total Ticket Cost $100.00

TOTAL COST $100.00
 */