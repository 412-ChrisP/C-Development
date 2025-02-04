

#include <iostream> 

#include <string> 

using namespace std;



int main()

{

    string items[50];

    float prices[50];

    int i = 0, j = 0;

    float sum = 0, tax = 0, b;

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