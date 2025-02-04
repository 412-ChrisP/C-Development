/*
 * ProjLab2.cpp
 *
 * Program calulates the highest profit ratio from inputted stock prices then calculates maximum profit obtainable
 *
 * @author ChrisPham
 */
#include <iostream>
using namespace std;

int main()
{
    double prices[10];
    double buy, sell, ratio, maxRatio = 0;

    cout << "Please type the 10-day price history of the stock: " << endl;

    for (int i = 0; i < 10; i++)
    {
        cin >> prices[i];
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = i + 2; j < 10; j++)
        {
            ratio = (prices[j] - prices[i]) / prices[i];
            if (ratio > maxRatio)
            {
                maxRatio = ratio;
                buy = i;
                sell = j;
            }
        }
    }

    if (maxRatio == 0 || maxRatio < 0)
    {
        cout << "Max Profit: " << maxRatio << endl;
    }
    else
    {
        cout << "Max Profit: " << maxRatio * 100 << endl;
        cout << "Best Strategy: buy on day " << buy + 1 << ", sell on day " << sell + 1 << endl;
    }
    return 0;
}
/*
EXECUTION CODE:

 Case 1:
Please type the 10-day price history of the stock:
50 200 100 30 20 25 40 10 5 35
Max Profit: 250
Best Strategy: buy on day 8, sell on day 10

 Case 2:
Please type the 10-day price history of the stock:
50 100 50 40 40 40 40 40 40 40
Max Profit: 0
 */