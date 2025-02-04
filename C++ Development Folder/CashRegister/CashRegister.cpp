/*
 * CashRegister.cpp
 *
 * Program Prompts user for item and price then prints receipt
 *
 * @author Chris Pham
 */


#include <iostream>

#include <string>

using namespace std;



int main()

{

    string items[50];

    float prices[50];

    int i = 0,j = 0;

    float sum = 0, tax = 0,b;

    string a;

    cout << "What is the name of the item? ";

    getline(cin, a);

    while (a != "done")

    {

        items[i] = a;

        cout << "What is the price? ";

        cin >> b;

        prices[i] = b;

        sum += b;

        i++;

        cin.ignore();

        cout << "What is the name of the item? ";

        getline(cin, a);

    }

    while (j < i)

    {

        cout << "\n" << items[j] << " $" << prices[j];

        j++;

    }

    cout << "\n---------------";

    cout << "\n\nSubtotal $" << sum;

    tax = 0.06 * sum;

    cout << "\nTax (6%" << ") $" << tax;

    cout << "\nTotal" << " $" << sum + tax;

    return 0;

}
/*
EXECUTION CODE:
What is the name of the item? Hamburger
What is the price? 1.50
What is the name of the item? French Fries
What is the price? 2.00
What is the name of the item? Bread
What is the price? 1.50
What is the name of the item? done

Hamburger $1.50
French Fries $2.00
Bread $1.50
----------------------
Subtotal $5.00
Tax (6%) $0.30
Total $5.30
 */