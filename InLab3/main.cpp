// InLab3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int* append(int* arrayA, int sizeA, int* arrayB, int sizeB);
int* merge(int* arrayA, int sizeA, int* arrayB, int sizeB);
void print(int* array, int size, const char* message);

int main()

{
    int arrayA[] = { 11,33,55,77,99 };	// use other values for more tests 

    int arrayB[] = { 22,44,66,88 };

    print(arrayA, 5, "Sorted array A: ");

    print(arrayB, 4, "Sorted array B: ");

    int* arrayC = append(arrayA, 5, arrayB, 4); // arrayC points to the appended array 

    print(arrayC, 9, "Append B to A:  ");

    int* arrayD = merge(arrayA, 5, arrayB, 4);

    print(arrayD, 9, "Merge A to B:   ");

    delete[] arrayC;

    delete[] arrayD;

    return 0;

}

int* append(int* arrayA, int sizeA, int* arrayB, int sizeB)
{
    int* arrayC = new int[sizeA + sizeB];

    for (int i = 0; i < sizeA; i++)
        arrayC[i] = arrayA[i];

    for (int i = 0; i < sizeB; i++)
        arrayC[sizeA + i] = arrayB[i];

    return arrayC;
}

int* merge(int* arrayA, int sizeA, int* arrayB, int sizeB)
{
    int* arrayD = new int[sizeA + sizeB];

    int i = 0, j = 0, k = 0;

    while (i < sizeA && j < sizeB)
    {
        if (arrayA[i] < arrayB[j])
            arrayD[k++] = arrayA[i++];
        else
            arrayD[k++] = arrayB[j++];
    }


    while (i < sizeA)
        arrayD[k++] = arrayA[i++];

    while (j < sizeB)
        arrayD[k++] = arrayB[j++];

    return arrayD;
}

void print(int* array, int size, const char* message)
{
    cout << message;

    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }

    cout << endl;
}
