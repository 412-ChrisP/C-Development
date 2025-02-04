/*
 * Point.cpp
 *
 * @author Chris_Pham
 */
#include <iostream>
using namespace std;
#include "Point.h" // defines Point class

int main()
{
    Point p0; // invokes default constructor
    Point p1(5, -2); // invokes constructor
    Point p2 = p1;
    p0 = p1; // invokes assignment operator
    cout << "p0.x() = " << p0.x() << "\n";
    cout << "p0.y() = " << p0.y() << "\n";

    //Modified Code:
    cout << "p0 magnitude = " << p0.magnitude() << "\n";
    p0.move(2, 3);
    cout << "p0 after move (2, 3): ";
    p0.print(cout);
    cout << endl;
}
/*
EXECUTION CODE:
p0.x() = 5
p0.y() = -2
p0 magnitude = 5.38516
p0 after move (2, 3): (7, 1)
 */