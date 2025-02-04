#include "Rect.h"
#include <iostream>

Rect::Rect(int len, int wid)
{
    length = len;
    width = wid;
}

int Rect::GetArea()
{
    return length * width;
}

bool Rect::isItASquare()
{
    return length == width;
}

void Rect::display(ostream & out) const
{
    out << "[" << length << ", " << width << "]";
}