#include <iostream>
#include "List.h"
#pragma warning(disable:6386) // disable the buffer overrun warning message
using namespace std;
void List::insert(ElementType item, int pos)
{
    if (mySize == myCapacity)  exit(1);
    if (pos < 0 || pos > mySize)  return;
    // shift array elements right to make room for item
    for(int i = mySize; i > pos; i--)
        myArrayPtr[i] = myArrayPtr[i - 1];
    // insert item at pos and increase list size
    myArrayPtr[pos] = item;
    mySize++;
}
List::List(int maxSize)
{
    mySize = 0;
    myCapacity = maxSize;
    myArrayPtr = new ElementType[maxSize];
}
List::~List()
{ delete [] myArrayPtr;}

List::List(const List & origList)
{
    mySize = origList.mySize;
    myCapacity = origList.myCapacity;
    myArrayPtr = new ElementType[myCapacity];
    for(int i = 0; i < mySize; i++)
        myArrayPtr[i] = origList.myArrayPtr[i];
}
List & List::operator=(const List & origList)
{
    if (this != & origList)    // check for list = list
    {
        delete[] myArrayPtr;
        mySize = origList.mySize;
        myCapacity = origList.myCapacity;
        myArrayPtr = new ElementType[myCapacity];
        //--- Copy origList's array into this new array
        for(int i = 0; i < myCapacity; i++)
            myArrayPtr[i] = origList.myArrayPtr[i];
    }
    return *this;
}
bool List::empty() const
{
    return (mySize == 0);
}
unsigned List::size() const
{
    return mySize;
}
ElementType List::get(unsigned pos) const
{
    if(pos >= mySize){
        cerr << "Invalid Index." << endl;
        exit(1);
    }
    return myArrayPtr[pos];
}
void List::display(ostream & out) const
{
    for(int i = 0; i < mySize; i++){
        out << myArrayPtr[i] << " ";
    }
}
int List::getCapacity()
{
    return myCapacity;
}

List::List(ElementType * array, int arraySize, int capacity)
{
    mySize = arraySize;
    myCapacity = capacity;
    myArrayPtr = new ElementType[capacity];

    for (int i = 0; i < arraySize; i++)
    {
        myArrayPtr[i] = array[i];
    }
}

void List::ChangeCapacity(int newCapacity)
{
    if (newCapacity <= myCapacity) return; // no need to change capacity
    ElementType *newArrayPtr = new ElementType[newCapacity];

    for (int i = 0; i < mySize; i++)
    {
        newArrayPtr[i] = myArrayPtr[i];
    }
    delete[] myArrayPtr;
    myArrayPtr = newArrayPtr;
    myCapacity = newCapacity;
}


