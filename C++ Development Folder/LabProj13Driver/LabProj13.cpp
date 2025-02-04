/******************************************************************************
CMPSC122 LabProj13: Project Algorithm Analysis -- sample driver
******************************************************************************/
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include "timer.h"
#include "MaxSubList.h"
const int FROM_SIZE = 500;
const int MUL = 2;
using namespace std;
void Output_CSV_File(string filename, Timer* T, int loop);

int main()
{
    int* Result_Blue, * Result_Green, * Result_Red, * Vec;
    Timer* T_Blue, * T_Green, * T_Red, Prepare;
    int loop;
    cout << "Please enter the number of loops: ";
    cin >> loop;
    Prepare.start();
    int Size = FROM_SIZE; // the integers sequence array size
    T_Blue = new Timer[loop];
    T_Green = new Timer[loop];
    T_Red = new Timer[loop];
    Result_Blue = new int[loop];
    Result_Green = new int[loop];
    Result_Red = new int[loop];
    cout << setprecision(4) << fixed << endl;

    for (int i = 0; i < loop; i++)
    {
        Vec = new int[Size];
        srand((unsigned)time(NULL));
        for (int j = 0; j < Size; j++)
            Vec[j] = rand() % 101 - 50;
        Result_Blue[i] = 0;
        Result_Green[i] = 0;
        Result_Red[i] = 0;
        Prepare.stop();
        cout << "Preparation Time: " << Prepare.get_elapsedtime() << "s" << endl;
        T_Blue[i].start();
        Result_Blue[i] = MaxSublistSum_Blue(Vec, Size);
        T_Blue[i].stop();
        cout << '[' << setw(2) << i << ']' << setw(50) << "Maximum contiguous subsequence sum (array size = " << setw(9) << Size << "): " << setw(6) << Result_Blue[i] << endl;
        cout << "Elapsed Time for Algorithm Blue: " << T_Blue[i].get_elapsedtime() << 's' << endl;
        cout << string(72, '-') << endl;

        T_Green[i].start();
        Result_Green[i] = MaxSublistSum_Green(Vec, Size);
        T_Green[i].stop();
        cout << '[' << setw(2) << i << ']' << setw(50) << "Maximum contiguous subsequence sum (array size = " << setw(9) << Size << "): " << setw(6) << Result_Green[i] << endl;
        cout << "Elapsed Time for Algorithm Green: " << T_Green[i].get_elapsedtime() << 's' << endl;
        cout << string(72, '-') << endl;

        T_Red[i].start();
        Result_Red[i] = MaxSublistSum_Red(Vec, Size);
        T_Red[i].stop();
        cout << '[' << setw(2) << i << ']' << setw(50) << "Maximum contiguous subsequence sum (array size = " << setw(9) << Size << "): " << setw(6) << Result_Red[i] << endl;
        cout << "Elapsed Time for Algorithm Red: " << T_Red[i].get_elapsedtime() << 's' << endl;
        cout << string(72, '-') << endl;

        Size = MUL * Size;
        delete[] Vec;
    }
    cout << endl << endl;
    Output_CSV_File("Result(Blue).csv", T_Blue, loop);
    Output_CSV_File("Result(Green).csv", T_Green, loop);
    Output_CSV_File("Result(Red).csv", T_Red, loop);
}
void Output_CSV_File(string filename, Timer* T, int loop)
{
    ofstream csvOutFile(filename);
    if (!csvOutFile)
    {
        cerr << "Failed to open output file: " << filename << endl;
        exit(EXIT_FAILURE);
    }
    int Size = FROM_SIZE;
    csvOutFile << "\"Array Size\",\"Run Time (s)\"" << endl;
    for (int i = 0; i < loop; i++)
    {
        csvOutFile << Size << "," << T[i].get_elapsedtime() << endl;
        Size = MUL * Size;
    }
    csvOutFile.close();
}
