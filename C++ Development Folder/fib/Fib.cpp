/*
 * Fib.cpp
 *
 * Program executes functions to return a string as indicated in the examples above from the word it gets as an argument
 *
 * @author_Chris Pham
 */

#include <iostream>

using namespace std;

void FibonacciNumber(int n, int& fib_no)

{

    if (n == 1)

    {

        fib_no = 0;

        cout << 0 << ", ";

    }

    else if (n == 2)

    {

        fib_no = 1;

        cout << 0 << "," << 1 << ", ";

    }

    else

    {

        int t[n];

        t[0] = 0;

        t[1] = 1;



        for (int i = 2; i < n; i++)

        {

            t[i] = t[i - 1] + t[i - 2];

        }

        for (int i = 0; i < n; i++)

        {

            cout << t[i] << ", ";

        }

        fib_no = t[n - 1];

    }

    cout << endl;

}

int main()
{
    int n;

    cout << "Please enter the nth. term Fibonacci number to compute: ";

    cin >> n;


    while (n <= 0) {

        cout << "Please enter a number greater than 0!" << endl;

        cout << "Please enter the nth. term Fibonacci number to compute: ";

        cin >> n;

    }


    cout << "The Fibonacci series is: ";

    int number;

    FibonacciNumber(n, number);

    cout << "The " << n << "th. term is: " << number << endl;

    return 0;
}
/*
 * EXECUTION CODE:
Please enter the nth. term Fibonacci number to compute: -1
 Please enter a number greater than 0!
Please enter the nth. term Fibonacci number to compute:0
 Please enter a number greater than 0!
Please enter the nth. term Fibonacci number to compute:12
 The Fibonacci series is: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89
The 12th. term is: 89
 */