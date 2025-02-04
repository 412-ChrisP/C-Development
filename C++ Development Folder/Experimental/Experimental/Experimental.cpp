// Experimental.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
    int array[6];

    for (int i = 0; i <= 5; i++)
    {
        cout << "Enter Amount For Array " << i + 1 << ": ";
        cin >> array[i];
    }

    int total = array[0] + array[1] + array[2] + array[3] + array[4] + array[5];
    int average = total / 6;
    int two = average * 24;

    cout << "Total = " << total << endl;
    cout << "Average = " << average << endl;
    cout << "Two Years = " << two << endl;

    return 0;
}
