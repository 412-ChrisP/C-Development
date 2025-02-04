#ifndef INLAB4RECT_RECT_H
#define INLAB4RECT_RECT_H

#include <iostream>

using namespace std;

class Rect{
public:
    Rect(int len, int wid);
    int GetArea();  // return the area of the rectangle
    // space for adding new member functions
    bool isItASquare();
    void display(ostream & out) const;
private:
    int length;
    int width;
};

#endif //INLAB4RECT_RECT_H
