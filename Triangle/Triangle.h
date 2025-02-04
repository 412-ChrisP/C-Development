/*
 * Triangle.h:
 * class to represent a triangle in c++
 *
 * @author Chris Pham
 */
#ifndef TRIANGLELAB_TRIANGLE_H
#define TRIANGLELAB_TRIANGLE_H


class Triangle
{
private:
    double base = 0.0, height = 0.0;
public:
    Triangle(double b, double h);
    double getBase() const;
    double getHeight() const;
    void setBase(double b);
    void setHeight(double h);
    double computeArea() const;
};


#endif //TRIANGLELAB_TRIANGLE_H
