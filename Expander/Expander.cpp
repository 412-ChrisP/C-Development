/*
 *Expander.cpp
 *
 * Program accepts the integer array and creates a new array twice the size and outputs
 *
 * @author_ChrisPham
 */

#include <iostream>

using namespace std;

int* expandArray(const int* org_array, int array_size)
{
    int* new_array = new int[2 * array_size];

    for (int i = 0; i < array_size; i++)
    {
        new_array[i] = org_array[i];
    }

    for (int i = array_size; i < 2 * array_size; i++)
    {
        new_array[i] = 0;
    }
    return new_array;
}

int main()
{
    int array_size;
    cout << "Please enter the size of the array: ";
    cin >> array_size;

    while (array_size <= 1)
    {
        cout << "The number must be greater than 1, try again." << "\n";
        cout << "Please enter the size of the array: ";
        cin >> array_size;
    }
    cout << "\n";
    int* org_array = new
            int[array_size];

    for (int i = 0; i < array_size; i++)
    {
        cout << "Enter integer number " << (i + 1) << ": ";
        cin >> org_array[i];
    }
    int* new_array = expandArray(org_array, array_size);
    cout << "\n The contents of the original array are: " << "\n";

    for (int i = 0; i < array_size; i++)
    {
        cout << org_array[i] << "";
    }
    cout << "\n\nThe contents of the expanded array are: " << "\n";

    for (int i = 0; i < (2 * array_size); i++)
    {
        cout << new_array[i] << " ";
    }
    delete[] org_array;
    delete[] new_array;
    return 0;
}

/*
EXECUTION CODE:
Please enter the size of the array: 0
The number must be greater than 1, try again.
Please enter the size of the array: 5


Enter integer number 1: 10
Enter integer number 2: 20
Enter integer number 3: 30
Enter integer number 4: 40
Enter integer number 5: 50

The contents of the original array are:
10 20 30 40 50

The contents of the expanded array are:
10 20 30 40 50 0 0 0 0 0
 */





