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

    computeMinMax(year, nQuarter, highest, lowest, highestQuarter, lowestQuarter);
    cout << "Total Rainfall: " << totalRain << endl;
    cout << "Average Quarterly Rain: " << avgQuaRain << endl;
    cout << "Average Quarterly Average Tempature: " << avgQuaTemp << endl;
    cout << "Highest Tempature: " << highest << " (Quarter " << highestQuarter << ")" << endl;
    cout << "Lowest Tempature: " << lowest << " (Quarter " << lowestQuarter << ")" << endl;
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
    cout << "Enter the total rainfall, low & high tempatures: " << endl;

    for (int i = 0; i < 4; i++)
    {
        double highTemp, lowTemp, totalRain;
        printf("Quarter %d: ", i + 1);
        cin >> totalRain >> lowTemp >> highTemp;

        while (highTemp < lowTemp || highTemp > 140 || lowTemp > 140 || lowTemp < -100 || highTemp < -100)
        {
            cout << "Error: " << "Tempature range: -100 through 140" << endl;
            cout << "\t Low Tempature <= high Tempature" << endl;
            cout << "Please enter low and high tempatures again: ";
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


*/