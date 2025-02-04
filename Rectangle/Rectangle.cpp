/*
 * Rectangle.cpp
 *
 * Program P/R for length and width then compounds until >= 500 and outputs results
 *
 * @author_ChrisPham
 */

#include <iostream>
#include <iomanip>
using namespace std;

int getLength();
int getWidth();
int calculateArea(int length, int width);
int doubleLength(int length);
int doubleWidth(int width);


struct Rectangle
{
    int length;
    int width;
};



int main()
{
    Rectangle rect;
    rect.length = getLength();
    rect.width = getWidth();

    int area = 0;
    area = calculateArea(rect.length, rect.width);
    cout << rect.length << " * " << rect.width << " = " << area << endl;
    while (area <= 500)
    {
        rect.length = doubleLength(rect.length);
        rect.width = doubleWidth(rect.width);
        area = calculateArea(rect.length, rect.width);
        cout << rect.length << " * " << rect.width << " = " << area << endl;
    }

    return 0;
}

int getLength()
{
    int length;
    cout << "Enter the starting length: ";
    cin >> length;
    while(length <= 0)
    {
        cout << "Please enter a length greater than zero!" << endl;
        cout << "Enter the starting length: ";
        cin >> length;
    }
    return length;
}

int getWidth()
{
    int width;
    cout << "Enter the starting width: ";
    cin >> width;
    while(width <= 0)
    {
        cout << "Please enter a width greater than zero!" << endl;
        cout << "Enter the starting width: ";
        cin >> width;
    }
    return width;
}

int calculateArea(int length, int width)
{
    return(length * width);
}

int doubleLength(int length)
{
    return(2 * length);
}

int doubleWidth(int width)
{
    return(2 * width);
}

/*
EXECUTION CODE:
Enter the starting length:-30
Please enter a length greater than zero!
Enter the starting length:50
Enter the starting width:0
Please enter a width greater than zero!
Enter the starting width:2
50 * 2 = 100
100 * 4 = 400
200 * 8 = 1600
 */
