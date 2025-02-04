/*
 * Pass.h:
 * class to represent passport objects in c++
 *
 * @author Chris Pham
 */

#ifndef PASSPORT_PASS_H
#define PASSPORT_PASS_H
#include <string>

using namespace std;

class Pass
{
private:
    string passportNumber;
    string firstName;
    string lastName;
    string nationality;
    string birthday;
public:
    Pass(string passportNumber, string firstName, string lastName, string nationality, string birthday);

    string getpassportNumber();
    void setpassportNumber(string passportNumber);
    string getfirstName();
    void setfirstName(string firstName);
    string getlastName();
    void setlastName(string lastName);
    string getNationality();
    void setNationality(string nationality);
    string getBirthday();
    void setBirthday(string birthday);
};

#endif //PASSPORT_PASS_H
