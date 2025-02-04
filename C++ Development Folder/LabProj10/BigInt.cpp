#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;
#include "BigInt.h"
const short int MAX_BLOCK = (short) pow(10.0, DIGITS_PER_BLOCK) - 1;
// for DIGITS_PER_BLOCK = 3, MAX_BLOCK = 999
//--- Definition of read()
void BigInt::read(istream & in)
{
    static bool instruct = true;
    if (instruct)
    {
        cout << "Enter " << DIGITS_PER_BLOCK << "-digit blocks, separated by spaces." << endl
                << "Enter a negative integer less than -999 (e.g. -9999) in last block to"
          " signal the end of input." << endl;
        instruct = false;
    }
    short int block;
    myList.clear(); // clear the list for fresh input
    for (;;)
    {
        in >> block;
// improvement to eliminate front padding zeros e.g. 000 000 456 875
        if (block <= -MODULUS) // end of line for BigInt with negative less than - 999
        {
            list<short int>::const_iterator it = myList.begin();
            while (it != myList.end())
            {
                if (*it > 0)
                    break;
                it++; // must do this before pop_front()
                myList.pop_front();
            }
            if (myList.size() == 0) // in case no block enter (e.g. user onlyenter -9999)
            myList.push_front(0); // initialize to 0
            return;
        }
        if (abs(block) >= MODULUS) // first block can be negative
            cerr << "Illegal block -- " << block << " -- ignoring\n";
        else
        {
            if (myList.size() == 0) // first block?
            {
                sign = (block >= 0) ? '+' : (block = -block, '-');
                myList.push_back(block);
            }
            else if (block >= 0)
                myList.push_back(block);
            else
                cerr << "Illegal negative block -- " << block << " -- ignoring\n";
        }
    }
}
//--- Definition of display()
// modified to use ostringstream to get better formatting outout
void BigInt::display(ostream & out) const
{
    int blockCount = 0;
    const int BLOCKS_PER_LINE = 20; // number of blocks per line
    ostringstream ss;
    for (list<short int>::const_iterator it = myList.begin(); ; )
    {
        if (it == myList.end())
            break;
        if (blockCount == 0)
            ss << ((sign == '-') ? -(*it) : *it); // remove leading space
        else
            ss << setfill('0') << setw(3) << *it;
        blockCount++;
        it++;
        if (it != myList.end())
        {
            ss << ',';
            if (blockCount > 0 && blockCount % BLOCKS_PER_LINE == 0)
                ss << endl;
        }
    }
    string bigInt = ss.str();
    cout << bigInt;
}
//-- Definition of constructor
BigInt::BigInt(int n)
{
// change n to positive if it is negative
    sign = (n >= 0)? '+' : (n = -n, '-');
    do
    {
        myList.push_front(n % MODULUS);
        n /= MODULUS;
    } while (n > 0);
}
//-- Default constructor
BigInt::BigInt()
{
    sign = '+';
    myList.push_front(0); // always initilized to 0
}
//--- Definition of operator+()
BigInt BigInt::operator+(BigInt int2)
{
    BigInt sum;
    if (sign == '-' && int2.sign == '-')
    {
        sign = int2.sign = '+';
        sum = int2 + *this;
        sign = int2.sign = '-'; // restore the signs
        sum.sign = '-';
        return sum;
    }
    if (sign == '+' && int2.sign == '-')
    {
        int2.sign = '+';
        sum = *this - int2;
        int2.sign = '-'; // restore sign of int2
        return sum;
    }
    if (sign == '-' && int2.sign == '+')
    {
        sign = '+';
        sum = int2 - (*this);
        sign = '-'; // restore sign of *this
        return sum;
    }
// at this point, both are positive
    short int first, // a block of this object
    second, // a block of int2
    result, // a block in their sum
    carry = 0; // the carry in adding two blocks
    list<short int>::reverse_iterator // to iterate right to left
    it1 = myList.rbegin(), // through 1st list, and
    it2 = int2.myList.rbegin(); // through 2nd list
// need to clear the list to prepare for the operation
    sum.myList.clear();
    while (it1 != myList.rend() || it2 != int2.myList.rend())
    {
        if (it1 != myList.rend())
        {
            first = *it1;
            it1++;
        }
        else
            first = 0;
        if (it2 != int2.myList.rend())
        {
            second = *it2;
            it2++;
        }
        else
            second = 0;
        short int temp = first + second + carry;
        result = temp % MODULUS;
        carry = temp / MODULUS;
        sum.myList.push_front(result);
    }
    if (carry > 0)
        sum.myList.push_front(carry);
    sum.sign = sign; // either negative or positive
    return sum;
}

// Write the other member functions here

bool BigInt::operator<(BigInt int2)
{
    if (sign == '+' && int2.sign == '-')
        return false;
    if (sign == '-' && int2.sign == '+')
        return true;
    if (myList.size() < int2.myList.size())
        return (sign == '+');
    if (myList.size() > int2.myList.size())
        return (sign == '-');
    list<short int>::const_iterator it1 = myList.begin();
    list<short int>::const_iterator it2 = int2.myList.begin();
    while (it1 != myList.end() && it2 != int2.myList.end())
    {
        if (*it1 < *it2)
            return (sign == '+');
        else if (*it1 > *it2)
            return (sign == '-');
        it1++;
        it2++;
    }
    return false;
}

bool BigInt::operator==(BigInt int2)
{
    if (sign != int2.sign)
        return false;
    if (myList.size() != int2.myList.size())
        return false;
    list<short int>::const_iterator it1 = myList.begin();
    list<short int>::const_iterator it2 = int2.myList.begin();
    while (it1 != myList.end() && it2 != int2.myList.end())
    {
        if (*it1 != *it2)
            return false;
        it1++;
        it2++;
    }
    return true;
}

BigInt BigInt::operator-(BigInt int2)
{
    BigInt diff;
    if (*this == int2)
        return diff;

    if (*this < int2)
    {
        diff = int2 - *this;
        diff.sign = '-';
        return diff;
    }

    short int first, second, result, borrow = 0;
    list<short int>::reverse_iterator
    it1 = myList.rbegin(),
    it2 = int2.myList.rbegin();
    while (it1 != myList.rend() || it2 != int2.myList.rend())
    {
        if (it1 != myList.rend())
        {
            first = *it1;
            it1++;
        }
        else
            first = 0;
        if (it2 != int2.myList.rend())
        {
            second = *it2;
            it2++;
        }
        else
            second = 0;
        short int temp = first - second - borrow;
        if (temp < 0)
        {
            result = temp + MODULUS;
            borrow = 1;
        }
        else
        {
            result = temp;
            borrow = 0;
        }
        diff.myList.push_front(result);
    }
    while (diff.myList.size() > 1 && diff.myList.front() == 0)
        diff.myList.pop_front();
    return diff;
}
