/*
 * Scores.cpp
 *
 * Program prompts user for input then sorts using bubble sort
 *
 * @author_ChrisPham
 */
#include <iostream> 

#include <ios> 

#include <iomanip> 



using namespace std;

void getScores(double* scores, int size)

{

    for (int i = 1; i <= size; i++)

    {

        cout << "Enter test score " << i << ": ";

        cin >> scores[i - 1];

        while (scores[i - 1] < 0)

        {

            cout << "Not allowed to enter a negative value, try again.";

            cout << "\nEnter test score " << i << ": ";

            cin >> scores[i - 1];

        }

    }

}

void sortScore(double* scores, int size)

{

    int i, j;

    for (i = 0; i < size - 1; i++)

    {

        for (j = 0; j < size - i - 1; j++)

        {

            if (scores[j] > scores[j + 1])

            {

                swap(scores[j], scores[j + 1]);

            }



        }

    }



}

double computeAverage(double* scores, int size)

{

    double average = 0;

    for (int i = 0; i < size; i++)

    {

        average = average / size;

        return average;

    }

}

int main()

{

    int size = 5;

    double scores[size];

    getScores(scores, size);

    cout << "\n\nThe test scores in ascending order: ";

    sortScore(scores, size);

    for (int i = 0; i < size; i++)

    {

        cout << fixed << setprecision(2) << scores[i] << endl;

    }

    cout << fixed << setprecision(2) << "\n\nThe average score is " << computeAverage(scores, size);

    return 0;
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