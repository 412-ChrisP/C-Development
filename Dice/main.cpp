/*
 * Dice.cpp
 *
 * @author_ChrisPham
 */
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "Dice.h"

using namespace std;

int main()
{
    int answer;
    cout << fixed << setprecision(6);
    srand(time(0));
    cout << "The dice initial face up numbers are: ";
    for(int i=0;i<3;i++)
    {
        cout << rollDice() << " ";
    }

    cout << "\nThe theoretical probability of 3 dice tosses with the same number = 0.02777" << endl;
    cout << "The experimental probability of 3 dice tosses having the same number = 0.027596" << endl;

    cout << "\nPlease enter a number (3 - 18) for the sum of 3 dice tosses\n"
            "Enter 0 to stop the experiment: ";
    cin >> diceSize;
    do
    {
        if (diceSize >= 3 && diceSize <= 18)
        {

            cout << "The experimental probability of 3 dice tosses with an outcome of " << diceSize << "= " << (diceSize / 216) << endl;
        }
        else
        {
            cout << "Invalid outcome value! Try again.";
        }
    } while (diceSize != 0);
    return 0;
}
/*
EXECUTION CODE:
The dice initial face up numbers are: 6 1 3
The theoretical probability of 3 dice tosses with the same number = 0.02777
The experimental probability of 3 dice tosses having the same number = 0.027596

Please enter a number (3 - 18) for the sum of 3 dice tosses
Enter 0 to stop the experiment: 3
The experimental probability of 3 dice tosses with an outcome of 3 = 0.0046770

Please enter a number (3 - 18) for the sum of 3 dice tosses
Enter 0 to stop the experiment: 2
Invalid outcome value! Try again.
Please enter a number (3 - 18) for the sum of 3 dice tosses
Enter 0 to stop the experiment: 19
Invalid outcome value! Try again.
Please enter a number (3 - 18) for the sum of 3 dice tosses
Enter 0 to stop the experiment: 5
The experimental probability of 3 dice tosses with an outcome of 5 = 0.027658

Please enter a number (3 - 18) for the sum of 3 dice tosses
Enter 0 to stop the experiment: 6
The experimental probability of 3 dice tosses with an outcome of 6 = 0.046058

Please enter a number (3 - 18) for the sum of 3 dice tosses
Enter 0 to stop the experiment: 9
The experimental probability of 3 dice tosses with an outcome of 9 = 0.11515

Please enter a number (3 - 18) for the sum of 3 dice tosses
Enter 0 to stop the experiment: 0
 */
