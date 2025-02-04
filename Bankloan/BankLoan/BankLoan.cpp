#include <iostream>
#include <string>

using namespace std;

double askAmount() {
    double loan;
    cout << "How much would you like to borrow? ";
    cin >> loan;
    if (loan < 0) {
        cout << "Please enter a positive number" << endl;
        return askAmount();
    }
    return loan;
}

bool decideLoan(double income, double loan) {
    if (income <= 10000)
        return false;
    else if (income > 10000 && income < 100000) {
        if (income * 5 >= loan)
            return true;
        else
            return false;
    }
    else if (income >= 100000)
        return true;
}

double askIncome() {
    double income;
    cout << "What is your yearly income? ";
    cin >> income;
    if (income < 0) {
        cout << "Please enter a positive number" << endl;
        return askIncome();
    }
    return income;
}

bool askLoan() {
    string choice;
    cout << "Would you like to take out a loan? ";
    cin >> choice;
    if (choice == "Yes" || choice == "y" || choice == "Y" || choice == "yes") {
        double loan = askAmount();
        double income = askIncome();
        if (decideLoan(income, loan)) {
            cout << "ACCEPT" << endl;
        }
        else {
            cout << "REJECT" << endl;
        }
        return true;
    }
    else if (choice == "No" || choice == "n" || choice == "N" || choice == "no") {
        cout << "Thanks for visiting the bank!" << endl;
        return false;
    }
    else {
        cout << "Invalid choice" << endl;
        cout << "Please enter Yes or No" << endl;
        return askLoan();
    }
}

int main() {
    askLoan();
    return 0;
}
