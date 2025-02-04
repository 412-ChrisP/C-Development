#ifndef LIST_LIST_H
#define LIST_LIST_H
#include <iostream>
using namespace std;
typedef int ElementType; // Now is
//can change int to double,char,...
#include <iostream>
using namespace std;
typedef int ElementType; // Now is
//can change int to double,char,...
class List {
public:
    List(int maxSize = 1024);  //constructor
    //Big Three:
    ~List(); // Destructor
    List(const List & orig); // Copy Constructor
    List & operator= (const List & orig); // Assignment operator

    List(ElementType * array, int arraySize, int capacity); // Constructor from array

    unsigned size() const;
    bool empty() const; //check if empty
    void insert(ElementType item, int pos); //insertion
    void erase(int pos); //deletion
    void display(ostream & out) const; //display every item
    ElementType get(unsigned pos) const;
    int getCapacity();

    void ChangeCapacity(int newCapacity); //function to change capacity
private:
    int mySize;       // current # of items in list
    int myCapacity;
    ElementType * myArrayPtr; //pointer to dynamic array
};

#endif //LIST_LIST_H
