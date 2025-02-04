#ifndef LABPROJ5_FRAC2_H
#define LABPROJ5_FRAC2_H

using namespace std;

class Fraction {
public:
    explicit Fraction(int = 0, int = 1); // default constructor

    Fraction operator+(const Fraction&) const;
    Fraction operator-(const Fraction&) const;
    Fraction operator*(const Fraction&) const;
    Fraction operator/(const Fraction&) const;

    bool operator>(const Fraction&) const;
    bool operator<(const Fraction&) const;

    void printFraction() const;
    void printFractionAsFloat() const;
private:
    int numerator;
    int denominator;
    void reduce(); // utility function, reduce to the lowest terms
};


#endif //LABPROJ5_FRAC2_H
