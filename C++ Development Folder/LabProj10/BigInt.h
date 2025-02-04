// Modified from textbook Larry Nyhoff, ADTs, Data Structures, and Problem
// Solving with C++, 2nd ed., Prentice-Hall,
/*-- BigInt.h -------------------------------------------------------------
This header file defines the data type BigInt for processing
nonnegative integers of any size.
Basic operations are:
Constructors
+: Addition operator
-: Subtraction operator
<: Less-than operator
==: Equal-to operator
read(): Read a BigInt object
display(): Display a BigInt object
<<, >> : Input and output operators
-------------------------------------------------------------------------*/
#include <iostream>
#include <iomanip> // setfill(), setw()
#include <list>
#include <cmath> // pow
#ifndef BIGINT
#define BIGINT
const int DIGITS_PER_BLOCK = 3;
const int MODULUS = (short int) pow(10.0, DIGITS_PER_BLOCK);
class BigInt
{
public:
/*-----------------------------------------------------------------------
Default Constructor
Precondition: None
Postcondition: list<short int>'s constructor was used to build
this BigInt object. Default value = 0, sign = '+'.
-----------------------------------------------------------------------*/
    BigInt();
/*-----------------------------------------------------------------------
Construct BigInt equivalent of n.
Precondition: None.
Postcondition: This BigInt is the equivalent of integer n.
-----------------------------------------------------------------------*/
    BigInt(int n);
// Let the list<short int> constructor take care of this.
/*-----------------------------------------------------------------------
Read a BigInt.
Precondition: istream in is open and contains blocks of integers having
at most DIGITS_PER_BLOCK digits per block.
Postcondition: Blocks have been removed from in and added to myList.
The sign = '-' if fisrt block is negative, all blocks will store as
positive number.
-----------------------------------------------------------------------*/
    void read(istream & in);
/*-----------------------------------------------------------------------
Display a BigInt.
Precondition: ostream out is open.
Postcondition: The large integer represented by this BigInt object
has been formatted with the usual comma separators and inserted
into ostream out. A negative sign will appear if sign = '-'
------------------------------------------------------------------------*/
    void display(ostream & out) const;
/*------------------------------------------------------------------------
Add two BigInts.
Precondition: int2 is the second addend.
Postcondition: The BigInt representing the sum of the large integer
represented by this BigInt object and addend2 is returned.
------------------------------------------------------------------------*/
    BigInt operator+(BigInt int2);
/*-----------------------------------------------------------------
Compare two BigInts with <.
Precondition: int2 is the second operand.
Postcondition: true if this BigInt object is < int2.
------------------------------------------------------------------*/
    bool operator<(BigInt int2);
/*-----------------------------------------------------------------
Compare two BigInts with ==.
Precondition: int2 is the second operand.
Postcondition: true if this BigInt object is equal to int2.
------------------------------------------------------------------*/
    bool operator==(BigInt int2);
/*-----------------------------------------------------------------
Subtract two BigInts.
Precondition: int2 is the second operand.
Postcondition: The BigInt representing the difference of the large
integer represented by this BigInt object and int2 is returned.
------------------------------------------------------------------*/
    BigInt operator-(BigInt int2);
private:
    list<short int> myList;
    char sign; // '+' => postive, '-' => negative. '?' => undefine
}; // end of BigInt class declaration
//------ Input and output operators
inline istream & operator>>(istream & in, BigInt & number)
{
    number.read(in);
    return in;
}
inline ostream & operator<<(ostream & out, const BigInt & number)
{
    number.display(out);
    return out;
}
// Note: To understand what is an inline function, read the following article
// https://www.cplusplus.com/articles/2LywvCM9/
#endif
