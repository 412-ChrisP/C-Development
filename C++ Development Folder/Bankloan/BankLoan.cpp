/*
 * BankLoan.cpp
 *
 * program that uses a function a bank would use (flowchart) to determine whether a
 * customer is eligible for a loan
 *
 * @author Chris Pham
 */

#include <iostream>
#include <string>

using namespace std;

class Bank

{

public:

    double loan;

    double income;

    string choice;

    double askAmount()

    {

        cout << "How much would you like to borrow?";

        cin >> loan;

        if (loan < 0)

        {

            cout << "Please enter postitive number";

            askAmount();

        }

        else

            askIncome();

        return 0.0;

    }



    bool askLoan()

    {

        cout << "Would you like to take out a loan?";

        cin >> choice;

        if (choice == "Yes" || choice == "y" || choice == "Y" || choice == "yes")

            return askAmount();

        else if (choice == "No" || choice == "n" || choice == "N" || choice == "no")

            cout << "Thanks for visiting the bank!" << endl;

        else

        {

            cout << "Invalid choice" << endl;

            cout << "Please enter Yes or No" << endl;

            askLoan();

        }

    }

    bool decideLoad(double income, double loan)

    {

        if (income <= 10000)

            return false;

        else if (income > 10000 && income < 100000)

        {

            if (income * 5 >= loan)

                return true;

            if (income * 5 < loan)

                return false;

        }

        else if (income >= 100000)

            return true;

    }



    double askIncome()

    {

        cout << "What is your yearly income?";

        cin >> income;

        if (income < 0)

        {

            cout << "Please enter positive number";

            askIncome();

        }

        else

        {

            if (decideLoad(income, loan))

                cout << "ACCEPT" << endl;

            else

                cout << "REJECT" << endl;

        }



        return 0.0;

    }

};

int main()

{

    Bank b;

    b.askLoan();

}

/*
EXECUTION CODE:

Sample Output #1
Would you like to take out a loan? maybe
Invalid choice
Please enter Yes or No
Would you like to take out a loan? yes
How much would you like to borrow? 45000
What is your yearly income? 15000
ACCEPT

Sample Output #2
Would you like to take out a loan? y
How much would you like to borrow? 5000000
What is your yearly income? 45000
REJECT
 */