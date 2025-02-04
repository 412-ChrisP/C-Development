/* 
 * Scores.cpp 
 * 
 * Program prompts user for input then sorts using bubble sort
 * 
 * @author_ChrisPham 
 */

#include <iostream>
#include <iomanip>

using namespace std;

void getScores(double *scores, int size);
void sortScores(double *scores, int size);
double computeAverage(const double *scores, int size);

int main()
{
    const int SIZE = 5;
    auto * scores = new double [SIZE];
    double avg;

    cout << fixed << setprecision(2) << endl;

    getScores(scores, SIZE);
    sortScores(scores, SIZE);

    for (int i = 0; i < SIZE; i++)
    {
        cout << *(scores + i) << endl;
    }
    computeAverage(scores,SIZE);
    delete [] scores;

    return 0;
}

void getScores(double *scores, int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        do
        {
            cout << "Enter test score: " << i + 1 << endl;
            cin >> *(scores + i);

            if( *(scores + 1) < 0 )
            {
                cout << "Not allowed to enter a negative value, try again. " << endl;
            }

        } while ( *(scores + 1) < 0 );
    }
    sortScores(scores, SIZE);
}

void sortScores(double *scores, int size)
{
    bool sorted = false;

    while (!sorted)
    {
    sorted = true;

        for (int i = 0; i < size - 1; i++)
        {
            if( *(scores + i) > *(scores + i + 1) )
            {
                double temp = *(scores + i);
                *(scores + i) = *(scores + i + 1);
                *(scores + i + 1) = temp;
                sorted = false;
            }
        }
    }
}

double computeAverage(const double *scores, int size)
{
    double sum = 0, average;
    for(int i = 0; i < size; ++i)
    {
        sum += *(scores + i);
    }
    average = sum / size;
    cout << "The test scores are in ascending order: " << endl;
    cout << "The average score is " << average << endl;
    return 0;
}
/* 
EXECUTION CODE:
Enter test score 1: 85.5
Enter test score 2: -20
Not allowed to enter a negative value, try again.
Enter test score 2: 99
Enter test score 3: 53.8
Enter test score 4: 78.2
Enter test score 5: 89
The test scores are in ascending order:
53.80
78.20
85.50
89.00
99.00
The average score is 81.10
 */