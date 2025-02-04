// File: LQueue.cpp
// ================
// Implementation file for Queue class using Linked List
#include <iostream>
#include "LQueue.h"
using namespace std;
//--- Definition of Queue constructor
Queue::Queue()
{
    myFront = myBack = nullptr;
}
//--- Definition of Queue explicit constructor
//--- Refer to LabProj7.cpp might be helpful
Queue::Queue(QueueElement array[], int array_size)
{
    myFront = myBack = nullptr;
    for (int i = 0; i < array_size; i++)
    {
        enqueue(array[i]);
    }
}

//--- Definition of Queue copy constructor
Queue::Queue(const Queue & original)
{
    myFront = myBack = nullptr;
    Node *temp = original.myFront;
    while (temp != nullptr)
    {
        enqueue(temp->data);
        temp = temp->next;
    }
}

//--- Definition of Queue destructor
Queue::~Queue()
{
    while (!empty())
    {
        dequeue();
    }
}

//--- Definition of assignment operator
const Queue & Queue::operator=(const Queue & original)
{
    if (this != &original)
    {
        while (!empty())
        {
            dequeue();
        }
        Node *temp = original.myFront;
        while (temp != nullptr)
        {
            enqueue(temp->data);
            temp = temp->next;
        }
    }
    return *this;
}

bool Queue::empty() const
{
    return (myFront == nullptr && myBack == nullptr);
}

//--- Definition of enqueue()
void Queue::enqueue(const QueueElement & data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    if (empty())
    {
        myFront = myBack = newNode;
    }
    else
    {
        myBack->next = newNode;
        myBack = newNode;
    }
}

//--- Definition of dequeue()
void Queue::dequeue()
{
    if (empty())
        cerr <<"Error: Queue is empty! cannot remove from queue." << endl;
    else
    {
        Node *temp = myFront;
        myFront = myFront->next;
        if (myFront == nullptr)
        {
            myBack = nullptr;
        }
        delete temp;
    }
}
//--- Definition of front()
QueueElement Queue::front() const
{
    if (empty())
    {
        cerr << "Error: Queue is empty! nothing to retrieve." << endl;
        return GARBAGE_VALUE;
    }
    else
        return myFront->data;
}
void Queue::display(ostream & out) const
{
    for (Node * np = myFront; np != nullptr; np = np->next)
    {
        out << np->data << " ";
    }
    out << endl;
}
