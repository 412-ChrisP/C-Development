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
    cout << "Queue created. Empty? " << (q1.empty()? "Yes" : "No") << endl;
    cout << "How many elements to add to the queue? ";
    int numItems;
    cin >> numItems;
#ifdef QUEUE_ELEMENT_STRING
    ifstream inFile("WordList.txt");
if (! inFile)
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
    cout << "Queue q2 empty? " << (q2.empty()? "Yes" : "No") << endl;
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
/*Sample runs:
For typedef string QueueElement;
================================
Queue created. Empty? Yes
How many elements to add to the queue? 8
Contents of queue q1 (via print):
border Tibetan black collie terrier silky Labrador saluki
Contents of queue q2 after q2 = q1 (via print):
border Tibetan black collie terrier silky Labrador saluki
Queue q2 empty? No
Front value in q2: border
Remove front -- Queue contents: Tibetan black collie terrier silky Labrador saluki
Remove front -- Queue contents: black collie terrier silky Labrador saluki
Remove front -- Queue contents: collie terrier silky Labrador saluki
Remove front -- Queue contents: terrier silky Labrador saluki
Remove front -- Queue contents: silky Labrador saluki
Remove front -- Queue contents: Labrador saluki
Remove front -- Queue contents: saluki
Remove front -- Queue contents:
Queue q2 empty? Yes
Attempt to read front value of q2:
Error: Queue is empty! nothing to retrieve.
Front value in q2: <nullptr>
Trying to remove front of q2:
Error: Queue is empty! cannot remove from queue.
Contents of queue q3 (via print):
otterhound Saint Rottweiler retriever Maltese spaniel Russell basset pointer
Samoyed fox Rottweiler
Contents of queue q3 after q3 = q1 (via print):
border Tibetan black collie terrier silky Labrador saluki
For typedef long QueueElement;
==============================
Queue created. Empty? Yes
How many elements to add to the queue? 10
Contents of queue q1 (via print):
166 333 500 666 833 1000 1166 1333 1500 1666
Contents of queue q2 after q2 = q1 (via print):
166 333 500 666 833 1000 1166 1333 1500 1666
Queue q2 empty? No
Front value in q2: 166
Remove front -- Queue contents: 333 500 666 833 1000 1166 1333 1500 1666
Remove front -- Queue contents: 500 666 833 1000 1166 1333 1500 1666
Remove front -- Queue contents: 666 833 1000 1166 1333 1500 1666
Remove front -- Queue contents: 833 1000 1166 1333 1500 1666
Remove front -- Queue contents: 1000 1166 1333 1500 1666
Remove front -- Queue contents: 1166 1333 1500 1666
Remove front -- Queue contents: 1333 1500 1666
Remove front -- Queue contents: 1500 1666
Remove front -- Queue contents: 1666
Remove front -- Queue contents:
Queue q2 empty? Yes
Attempt to read front value of q2:
Error: Queue is empty! nothing to retrieve.
Front value in q2: -2147483648
Trying to remove front of q2:
Error: Queue is empty! cannot remove from queue.
Contents of queue q3 (via print):
123 247 371 494 618 742 865 989 1113 1236 1360 1484 1607 1731 1855
Contents of queue q3 after q3 = q1 (via print):
166 333 500 666 833 1000 1166 1333 1500 1666
*/