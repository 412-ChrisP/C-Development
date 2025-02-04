#include <iostream>
#include "Rect.h"
using namespace std;

int main()
{
    Rect r1(5, 3);
    Rect r2(4, 4);

    cout << "Rectangle 1: ";
    r1.display(cout);
    cout << endl;

    cout << "Rectangle 2: ";
    r2.display(cout);
    cout << endl;

    cout << "Area of rectangle 1: " << r1.GetArea() << endl;
    cout << "Area of rectangle 2: " << r2.GetArea() << endl;

    cout << "Is rectangle 1 a square? " << (r1.isItASquare() ? "Yes" : "No") << endl;
    cout << "Is rectangle 2 a square? " << (r2.isItASquare() ? "Yes" : "No") << endl;

    return 0;
}
/*
EXECUTION CODE:
Rectangle 1: [5, 3]
Rectangle 2: [4, 4]
Area of rectangle 1: 15
Area of rectangle 2: 16
Is rectangle 1 a square? No
Is rectangle 2 a square? Yes
 */