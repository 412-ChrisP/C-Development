#include "Pass.h"

using namespace std;

Pass::Pass(string passportNumber, string firstName, string lastName, string nationality, string birthday)
{
    this->passportNumber = passportNumber;
    this->firstName = firstName;
    this->lastName = lastName;
    this->nationality = nationality;
    this->birthday = birthday;
}

string Pass::getpassportNumber()
{
    return passportNumber;
}

void Pass::setpassportNumber(string passportNumber)
{
    this->passportNumber = passportNumber;
}

string Pass::getfirstName()
{
    return firstName;
}

void Pass::setfirstName(string firstName)
{
    this->firstName = firstName;
}

string Pass::getlastName()
{
    return lastName;
}

void Pass::setlastName(string lastName)
{
    this->lastName = lastName;
}

string Pass::getNationality()
{
    return nationality;
}

void Pass::setNationality(string nationality)
{
    this->nationality = nationality;
}

string Pass::getBirthday()
{
    return birthday;
}

void Pass::setBirthday(string birthday)
{
    this->birthday = birthday;
}


