/*
 * Converter.cpp
 *
 * Program converts Fahrenheit to Celsius and outputs results
 *
 * @author_ChrisPham
 */

#include <iomanip>
#include <iostream>

using namespace std;

void getTemperature(double temp[], int size);
void convertTemperature(double temp[], int size);

int main()
{
    const int SIZE = 4;
    double temps [SIZE];

    cout << fixed << setprecision(2);

    getTemperature(temps, SIZE);

    return 0;
}

/**
 * gets temperature from user
 *
 * @param temp array to hold the temperatures
 * @param size the size of the array
 */

void getTemperature(double temp[], int size)
{
    for(int i = 0; i < size; i++)
    {
        do
        {
           cout << "Enter Celsius temperature " << i + 1 << ": ";
           cin >> temp[i];

           if (temp[i] <= -273.15)
            {
                cout << "The temperature must be greater than -273.15 " << endl;
            }
        }while (temp[i] <= -273.15);
    }

    convertTemperature(temp, size);
    return;
}

/**
 * converts the temperature in the array
 *
 * @param temp the array of temperature
 * @param size the size of the array
 */

void convertTemperature(double temp[], int size)
{
    const double RATIO = 9.0/5.0;

    for (int i = 0; i < size; i++)
    {
        cout << temp[i] << "degree Celsius is " << RATIO * temp[i] + 32 << "degrees Fahrenheit " << endl;
    }

    return;
}

/*
EXECUTION CODE:
Enter Celsius temperature 1: -274
 The temperature must be greater than -273.15
Enter Celsius temperature 1: -31
 Enter Celsius temperature 2: 0
 Enter Celsius temperature 3: 13.25
 Enter Celsius temperature 4: 100
 -31.00 degree Celsius is -23.80degrees Fahrenheit
0.00 degree Celsius is 32.00degrees Fahrenheit
13.25 degree Celsius is 55.85degrees Fahrenheit
100.00 degree Celsius is 212.00degrees Fahrenheit
 */
