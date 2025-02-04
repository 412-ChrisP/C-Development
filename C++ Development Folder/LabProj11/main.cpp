#include <iostream>
#include "timer.h"

using namespace std;


int main()
{
    char ans;
    do{
        int north, east;
        cout << "How many points north of A is B? ";
        cin >> north;
        cout << "How many points east of A is B? ";
        cin >> east;

        Timer timer("Process Timer");
        timer.start();
        int numPaths = timer.countPaths(north, east);
        timer.stop();

        cout << "There are " << numPaths << " northeast paths between A and B." << endl;
        timer.show();

        cout << "Enter y or Y to continue the next example or any other letter to exit: ";
        cin >> ans;
    }while (ans == 'y' || ans == 'Y');

    return 0;
}
/*
EXECUTION CODE:
How many points north of A is B? 2
How many points east of A is B? 3
There are 10 northeast paths between A and B.
 Process Timer
 -------------------------------
 Elapsed Time: 0.001s
Enter y or Y to continue the next example or any other letter to exit: y
How many points north of A is B? 12
How many points east of A is B? 14
There are 9657700 northeast paths between A and B.
 Process Timer
 -------------------------------
 Elapsed Time: 0.039s
Enter y or Y to continue the next example or any other letter to exit: y
How many points north of A is B? 16
How many points east of A is B? 16
There are 601080390 northeast paths between A and B.
 Process Timer
 -------------------------------
 Elapsed Time: 2.317s
Enter y or Y to continue the next example or any other letter to exit: n
 */
