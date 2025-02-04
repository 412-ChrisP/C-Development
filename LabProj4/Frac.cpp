//
// Name: Chris Pham
//
// a Fraction object holds one Fraction number, one fraction
#include "Frac.h"
//------------------------------ Fraction ------------------------------------
// default constructor:  parameters are numerator and denominator respectively
// if the number is negative, the negative is always stored in the numerator
Fraction::Fraction(int n, int d) {
    numerator = (d < 0 ? -n : n);
    denominator = (d < 0 ? -d : d);
    reduce();
}
//(a)--------------------------------- add --------------------------------------
// addition of 2 Fractions, current object and parameter
Fraction Fraction::add(const Fraction& a)
{
    Fraction t;
    t.numerator = a.numerator * denominator + a.denominator * numerator;
    t.denominator = a.denominator * denominator;
    t.reduce();
    return t;
}
//(b)------------------------------ subtract ------------------------------------
// subtraction of 2 Fractions, current object and parameter
Fraction Fraction::subtract(const Fraction& a)
{
    Fraction t;
    t.numerator = numerator * a.denominator - a.numerator * denominator;
    t.denominator = a.denominator * denominator;
    t.reduce();
    return t;
}
//(c)------------------------------ multiply ------------------------------------
// multiplication of 2 Fractions, current object and parameter
Fraction Fraction::multiply(const Fraction& a)
{
    Fraction t;
    t.numerator = a.numerator * numerator;
    t.denominator = a.denominator * denominator;
    t.reduce();
    return t;
}
//(d)-------------------------------- divide ------------------------------------
// division of 2 Fractions, current object and parameter,
// division by zero crashes
Fraction Fraction::divide(const Fraction& a)
{
    if (a.numerator == 0)
    {
        cout << "DIVIDE BY ZERO ERROR!!!" << endl;
        return Fraction();
    }
    else
    {
        Fraction t;
        t.numerator = numerator * a.denominator;
        t.denominator = denominator * a.numerator;
        t.reduce();
        return t;
    }
}
//(e)---------------------------- printFraction ---------------------------------
void Fraction::printFraction()
{
    cout << numerator << "/" << denominator;
}
//(f)------------------------ printFractionAsFloat ------------------------------
void Fraction::printFractionAsFloat()
{
    if (denominator == 0)
        cout << endl << "DIVIDE BY ZERO ERROR!!!" << endl;
    else
        cout << float(numerator) / float(denominator);
}
//-------------------------------- reduce ------------------------------------
// reduce fraction to the lowest terms
void Fraction::reduce()
{
    int n = numerator < 0 ? -numerator : numerator;
    int d = denominator;
    int largest = n > d ? n : d;
    int gcd = 0; // greatest common divisor
    for (int loop = largest; loop >= 2; loop--)
        if (numerator % loop == 0 && denominator % loop == 0)
        {
            gcd = loop;
            break;
        }
    if (gcd != 0)
    {
        numerator /= gcd;
        denominator /= gcd;
    }
}

