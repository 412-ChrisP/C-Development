/*
 * Weather.cpp
 *
 * Program uses structures to follow weather data
 *
 * @author_ChrisPham
 */
#include <iostream>

using namespace std;

typedef struct WeatherInfo
{
    double highestTemp;
    double lowestTemp;
    double totalRainfall;
    double averageTemp;
}WeatherInfo;

void displayAverages(WeatherInfo year[], int nQuarter)
{
    double totalRain = 0, avgQuaRain = 0, avgQuaTemp = 0;
    double highest = -100, lowest = 140;
    int highestQuarter = 0, lowestQuarter = 0;

    for (int i = 0; i < nQuarter; i++)
    {
        totalRain += year[i].totalRainfall;
        avgQuaTemp += year[i].averageTemp;
    }
    avgQuaRain = totalRain / nQuarter;
    avgQuaTemp /= nQuarter;

    void computeMinMax(year, nQuarter, highest, lowest, highestQuarter, lowestQuarter);

    cout << "Total Rainfall: " << totalRain << endl;
    cout << "Average Quarterly Rain: " << avgQuaRain << endl;
    cout << "Average Quarterly Average Temperature: " << avgQuaTemp << endl;
    cout << "Highest Temperature: " << highest << " (Quarter " << highestQuarter << ")" << endl;
    cout << "Lowest Temperature: " << lowest << " (Quarter " << lowestQuarter << ")" << endl;
}

void computeMinMax(WeatherInfo year[], int nQuarter, double& highest, double& lowest, int& highQuarter, int& lowQuarter)
{
    for (int i = 0; i < nQuarter; i++)
    {
        if (year[i].highestTemp > highest)
        {
            highest = year[i].highestTemp;
            highQuarter = i + 1;
        }

        if (year[i].lowestTemp < lowest)
        {
            lowest = year[i].lowestTemp;
            lowQuarter = i + 1;
        }
    }
}

int main()
{
    WeatherInfo year[4];
    cout << "Enter the total rainfall, low & high temperatures: " << endl;

    for (int i = 0; i < 4; i++)
    {
        double highTemp, lowTemp, totalRain;
        printf("Quarter %d: ", i + 1);
        cin >> totalRain >> lowTemp >> highTemp;

        while (highTemp < lowTemp || highTemp > 140 || lowTemp > 140 || lowTemp < -100 || highTemp < -100)
        {
            cout << "Error: Temperature range: -100 through 140" << endl;
            cout << "\t Low Temperature <= high Temperature" << endl;
            cout << "\t Please enter low and high temperatures again: ";
            cin >> lowTemp;
            cin >> highTemp;
        }
        year[i].highestTemp = highTemp;
        year[i].lowestTemp = lowTemp;
        year[i].totalRainfall = totalRain;
        year[i].averageTemp = (highTemp + lowTemp) / 2;
    }
    displayAverages(year, 4);
}
/*
EXECUTION CODE:
Enter the total rainfall, low & high temperatures:
Quarter 1: 15 40 67
Quarter 2: 40 50 78
Quarter 3: 30 58 80
Quarter 4: 5 -110 85
ERROR: Temperature range: -100 through 140
    Low temperature <= high temperature.
    Please enter low and high temperatures again: 65 141
ERROR: Temperature range: -100 through 140
    Low temperature <= high temperature.
    Please enter low and high temperatures again: 140 65
ERROR: Temperature range: -100 through 140
    Low temperature <= high temperature.
    Please enter low and high temperatures again: 65 85
Total Rainfall: 90
Average Quarterly Rain: 22.5
Average Quarterly Average Temperature: 65.375
Highest Temperature: 85 (Quarter 4)
Lowest Temperature: 40 (Quarter 1)
 */