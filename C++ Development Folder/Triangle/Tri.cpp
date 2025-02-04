//
// Created by czp5611 on 11/27/2022.
//

#include "Triangle.h"

Triangle::Triangle(double b, double h)
{
    setBase(b);
    setHeight(h);
}
double Triangle::getBase() const
{
    return base;
}
double Triangle::getHeight() const
{
    return height;
}
void Triangle::setBase(double b)
{
    base = b;
}
void Triangle::setHeight(double h)
{
    height = h;
}
double Triangle::computeArea() const
{
    return base * height * 0.5;
}