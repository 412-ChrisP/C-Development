/*
 * Reverse.cpp
 *
 * Program prompts the user for an allocated integer array then reverses the input numbers and outputs them
 *
 * @author_ChrisPham
 */

#include <iostream>

using namespace std;

int* reverseArray(int* num_array, int array_size)
{
    int *reverse = new int[array_size];
    int k = 0;

    for (int i = array_size - 1; i >= 0; i--)
    {
        reverse[k++] = num_array[i];
    }
    return reverse;
}

int main()
{
    int array_size;

    do {
        cout << "Please enter the size of the array: ";
        cin >> array_size;
        if(array_size <= 0)
        {
            cout << " The array size must be greater than 0, try again." << endl;
        }
    }while(array_size <= 0)

    int* array = new int[array_size];

    for (int i = 0; i < array_size; i++)
    {
        cout << "Please enter number " << (i+1) << ": ";
        cin >> array[i];
    }

    int* reverse = reverseArray(array, array_size);
    cout << "The contents of the original array are: [";

    for (int i = 0; i < array_size; i++)
    {
        if (i != array_size - 1)
        {
            cout << array[i] << ",";
        }
        else
        {
            cout << array[i];
        }
    }
    cout << "]\n";
    cout << "The contents of the reversed array are: [";

    for (int i = 0; i < array_size; i++)
    {
        if (i != array_size - 1)
            cout << reverse[i] << ",";
        else
            cout << reverse[i];
    }
    cout << "]\n";

    delete[] array;
    delete[] reverse;
    return 0;
}


/*
EXECUTION CODE:
Please enter the size of the array: -2
The array size must be greater than 0, try again.
Please enter the size of the array: 5


Please enter number 1: 15
Please enter number 2: 36
Please enter number 3: 9
Please enter number 4: 90
Please enter number 5: 21
The contents of the original array are: [15, 36, 9, 90, 21]
The contents of the reversed array are: [21, 90, 9, 36, 15]
 */