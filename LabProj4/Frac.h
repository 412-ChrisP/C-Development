//
// Name: Chris Pham
//
// a Fraction object holds one Fraction number, one fraction
#ifndef FRAC_H
#define FRAC_H
#include <iostream>

using namespace std;

class Fraction {
public:
    explicit Fraction(int = 0, int = 1); // default constructor
    Fraction add(const Fraction &);
    // New Constructors
    Fraction subtract(const Fraction &);
    Fraction multiply(const Fraction &);
    Fraction divide(const Fraction &);
    void printFraction();

    void printFractionAsFloat();

private:
    int numerator;
    int denominator;
    void reduce(); // utility function, reduce to the lowest terms
};

#endif
