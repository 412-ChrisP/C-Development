#include "Point.h"
#include <cmath>
Point::Point()
{
    _x = 0;
    _y = 0;
}

Point::Point(double x, double y)
{
    _x = x;
    _y = y;
}

double Point::x() const
{
    return _x;
}

double Point::y() const
{
    return _y;
}

double Point::magnitude() const
{
    return sqrt(_x * _x + _y * _y);
}

void Point::move(double dx, double dy)
{
    _x += dx;
    _y += dy;
}

void Point::print(ostream & out) const
{
    out << "(" << _x << ", " << _y << ")";
}