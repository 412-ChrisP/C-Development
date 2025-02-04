// File: LQueue.h
// ================
/*
Queue Implementation using Linked List
========================================
Basic operations:
constructor: Constructs an empty queue
explicit constructor: Constructs a queue from an array
copy constructor: Constructs a copy of a queue
=: Assignment operator
destructor: Destroys a queue
empty: Checks if a queue is empty
enqueue: Modifies a queue by adding a value at the back
front: Accesses the top stack value; leaves queue unchanged
dequeue: Modifies queue by removing the value at the front
display: Displays all the queue elements
-------------------------------------------------------------------
*/
#ifndef LQUEUE_H
#define LQUEUE_H
#include <iostream>
#include <limits.h>
using namespace std;
// IMPORTANT!!!
// Your test outputs should include the following 2 difference data types:
// Compile and run with long type (comment out the #define QUEUE_ELEMENT "STRING"),
// copy and paste the output at the end of this header file
// Compile and run with string type (comment out the #define QUEUE_ELEMENT "LONG"),
// copy and paste the output at the end of this header file
// select one of the options below:
// #define QUEUE_ELEMENT_LONG
#define QUEUE_ELEMENT_STRING
#ifdef QUEUE_ELEMENT_LONG
typedef long QueueElement;
const QueueElement GARBAGE_VALUE = LONG_MIN; // -2147483648
#else
#ifdef QUEUE_ELEMENT_STRING
typedef string QueueElement;
const QueueElement GARBAGE_VALUE = "<nullptr>";
#else
// default typedef
typedef int QueueElement;
const QueueElement GARBAGE_VALUE = INT_MIN; // -2147483648
#endif
#endif
class Queue
{
public:
    Queue(); // Constructor
    Queue(QueueElement array[], int array_size); // Explicit Constructor
    Queue(const Queue & original); // Copy Constructor
    ~Queue(); // Destructor
    const Queue & operator= (const Queue & original); // Assignment Operator
    bool empty() const;
    void enqueue(const QueueElement & data);
    void display(ostream & out) const;
    QueueElement front() const;
    void dequeue();
private:
// The linked list is hidden from the user,
// achieving a higher degree of data hiding
    struct Node {
        QueueElement data;
        Node* next;
    };
    Node * myFront; // front and
    Node * myBack; // back of queue
};
// end of class declaration
#endif