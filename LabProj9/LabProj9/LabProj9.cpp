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
Queue::Queue(const Queue& original)
{
    myFront = myBack = nullptr;
    Node* temp = original.myFront;
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
const Queue& Queue::operator=(const Queue& original)
{
    if (this != &original)
    {
        while (!empty())
        {
            dequeue();
        }
        Node* temp = original.myFront;
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
void Queue::enqueue(const QueueElement& data)
{
    Node* newNode = new Node;
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
        cerr << "Error: Queue is empty! cannot remove from queue." << endl;
    else
    {
        Node* temp = myFront;
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
void Queue::display(ostream& out) const
{
    for (Node* np = myFront; np != nullptr; np = np->next)
    {
        out << np->data << " ";
    }
    out << endl;
}


/*---------------------------------------------------------------------
Driver program to test the (Linked List) Queue class.
----------------------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include <vector>
#include <limits.h>
using namespace std;
#include "LQueue.h"
int main()
{
    Queue q1, q3;
    cout << "Queue created. Empty? " << (q1.empty() ? "Yes" : "No") << endl;
    cout << "How many elements to add to the queue? ";
    int numItems;
    cin >> numItems;
#ifdef QUEUE_ELEMENT_STRING
    ifstream inFile("wordlist.txt");
    if (!inFile)
    {
        cerr << "Fatal Error: Failed to open wordlist.txt file!" << endl;
        exit(1);
    }
    QueueElement word;
    vector <QueueElement> wordList;
    while (inFile >> word)
        wordList.push_back(word);
    size_t listSize = wordList.size();
    for (int i = 1; i <= numItems; i++)
        q1.enqueue(wordList[rand() % listSize]);
    srand(100); // setup a larger queue q3
    for (int i = 1; i <= numItems * 1.5; i++)
        q3.enqueue(wordList[rand() % listSize]);
    inFile.close();
#else
    for (int i = 1; i <= numItems; i++)
        q1.enqueue((QueueElement)500 * i / 3);
    // setup a larger queue q3
    for (int i = 1; i <= numItems * 1.5; i++)
        q3.enqueue((QueueElement)371 * i / 3);
#endif
    cout << "Contents of queue q1 (via print):" << endl;
    q1.display(cout);
    cout << endl;
    Queue q2;
    q2 = q1; // test for assignment operator
    cout << "Contents of queue q2 after q2 = q1 (via print):" << endl;
    q2.display(cout);
    cout << endl;
    cout << "Queue q2 empty? " << (q2.empty() ? "Yes" : "No") << endl;
    cout << "Front value in q2: " << " " << q2.front() << endl;
    while (!q2.empty())
    {
        cout << "Remove front -- Queue contents: ";
        q2.dequeue();
        q2.display(cout);
    }
    cout << "Queue q2 empty? " << (q2.empty() ? "Yes" : "No") << endl << endl;
    cout << "Attempt to read front value of q2:" << endl;
    cout << "Front value in q2: " << q2.front() << endl << endl;
    cout << "Trying to remove front of q2: " << endl;
    q2.dequeue();
    cout << endl;
    cout << "Contents of queue q3 (via print):" << endl;
    q3.display(cout);
    cout << endl;
    q3 = q1; // test for assignment operator where q1 is smaller in length
    cout << "Contents of queue q3 after q3 = q1 (via print):" << endl;
    q3.display(cout);
    cout << endl;
}