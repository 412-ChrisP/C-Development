/*
 * Passport.cpp
 *
 * author@_ChrisPham
 */
#include "Pass.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string firstName, lastName, nationality, passportNumber, birthday;

    cout << "What is the person's first name: ";
    cin >> firstName;

    cout << "What is the person's last name: ";
    cin >> lastName;

    cout << "What is the passport number: ";
    cin >> passportNumber;

    cout << "What is the person's nationality: ";
    cin >> nationality;

    cout << "What is the person's birthdate: ";
    cin >> birthday;

    Pass Passport(passportNumber, firstName, lastName, nationality,birthday);

    cout << "\n" << Passport.getNationality() << " Passport: " << Passport.getpassportNumber() << endl;
    cout << Passport.getfirstName() << " " << Passport.getlastName() << endl;
    cout << "Born " << Passport.getBirthday() << endl;

    return 0;
}
/*
EXECUTION CODE:
What is the person’s first name: James
What is the person’s last name: Bond
What is the passport number: 28128555
What is the person’s nationality: UK
What is the person’s birthdate: 01/01/1970

UK Passport: 28128555
James Bond
Born 01/01/1970
 */