#include <iostream>
#include <stack>
using namespace std;
/******************************************************************************
 * Node class declaration.
 * DO NOT modify.
******************************************************************************/
class Node {
public:
    int data;
    Node* next;
};
/******************************************************************************
* Functions you have to implement
******************************************************************************/
//Problem A: Remove part of a linked list.
void Remove(Node* &llist, unsigned startIndex, unsigned endIndex)
{
    if(llist == NULL)
        return;
    if(startIndex > endIndex)
        return;
    int index = 0;
    Node *p = llist, *prev = NULL;
    while(p != NULL && index < startIndex)
    {
        prev = p;
        p = p->next;
        index++;
    }
    if(p == NULL)
        return;
    Node *q = p, *tmp;
    while(q != NULL && index <= endIndex)
    {
        tmp = q;
        q = q->next;
        delete tmp;
        index++;
    }
    if(prev != NULL)
    {
        prev->next = q;
    }
    else
    {
        llist = q;
    }
}
//Problem B: Reversing a linked list.
void ReverseList(Node* &llist)
{
    Node *prev = NULL, *cur = llist, *next = NULL;
    while(cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    llist = prev;
}
//Problem C: Perform a right shift to a Linked List.
void RightShift(Node* &llist)
{
    if(llist == NULL)
        return;
    Node *p = llist;
    int length = 1;
    while(p->next != NULL)
    {
        p = p->next;
        length++;
    }
    p->next = llist;
    int shift = length/2;
    for(int i = 0; i < length-shift; i++)
    {
        p = p->next;
    }
    llist = p->next;
    p->next = NULL;
}
//Problem D: Test if a list is a palindrome.
bool IsPalindrome(Node* llist)
{
    if(llist == NULL)
        return false;
    stack<int> s;
    Node *p = llist;
    while(p != NULL)
    {
        s.push(p->data);
        p = p->next;
    }
    p = llist;
    while(p != NULL)
    {
        if(p->data != s.top())
            return false;
        s.pop();
        p = p->next;
    }
    return true;
}
/******************************************************************************
 * Functions that used by the driver.
 * DO NOT modify these functions.
******************************************************************************/
Node* CreateList(int* arr, int len) {
    if (len <= 0 || arr == NULL) {
        return NULL;
    }
    Node* head = new Node();
    head->data = arr[len - 1];
    head->next = NULL;
    for (int i = 1; i < len; i++) {
        Node* temp = new Node();
        temp->next = head;
        temp->data = arr[len - i - 1];
        head = temp;
    }
    return head;
}
void RemoveAll(Node*& first) {
    Node* cur = first;
    while (cur != NULL) {
        Node* del = cur;
        cur = cur->next;
        delete del;
    }
    first = NULL;
}
void ShowList(Node* llist) {
    Node* cur = llist;
    while (cur != NULL) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}
/******************************************************************************
 * Test driver main function.
 * DO NOT modify the main function.
 ******************************************************************************/
int main() {
    cout << "Problem A, test case 1, removing [2]-[4]:" << endl;
    int a[] = { 2, 5, 8, 10, 15 };
    Node* llistA = CreateList(a, 5);
    ShowList(llistA);
    cout << "Result List:" << endl;
    Remove(llistA, 2, 4);
    ShowList(llistA);
    cout << "Problem A, test case 2, removing [0]-[3]:" << endl;
    int b[] = { 1, 6, 8, 13, 15, 26, 30 };
    Node* llistB = CreateList(b, 7);
    ShowList(llistB);
    cout << "Result List:" << endl;
    Remove(llistB, 0, 3);
    ShowList(llistB);
    ///////////////////////////////////////////////////
    RemoveAll(llistA);
    RemoveAll(llistB);
    llistA = CreateList(a, 5);
    llistB = CreateList(b, 7);
    cout << "Problem B, test case 1, reversing list:" << endl;
    ShowList(llistA);
    cout << "Reversed List:" << endl;
    ReverseList(llistA);
    ShowList(llistA);
    cout << "Problem B, test case 2, reversing list:" << endl;
    ShowList(llistB);
    cout << "Reversed List:" << endl;
    ReverseList(llistB);
    ShowList(llistB);
    ///////////////////////////////////////////////////
    RemoveAll(llistA);
    RemoveAll(llistB);
    llistA = CreateList(a, 5);
    llistB = CreateList(b, 7);
    cout << "Problem C, test case 1, right shift:" << endl;
    ShowList(llistA);
    cout << "Resulting List:" << endl;
    RightShift(llistA);
    ShowList(llistA);
    cout << "Problem C, test case 2, right shift:" << endl;
    ShowList(llistB);
    cout << "Resulting List:" << endl;
    RightShift(llistB);
    ShowList(llistB);
    //////////////////////////////////////////////////
    cout << "Problem D, test case 1, test if palindrome:" << endl;
    int g[] = { 1, 4, 6, 7, 6, 4, 1 };
    Node* llistG = CreateList(g, 7);
    ShowList(llistG);
    cout << ((IsPalindrome(llistG)) ? "True" : "False") << endl;
    cout << "Problem D, test case 2, test if palindrome:" << endl;
    int h[] = { 1, 4, 6, 7, 6, 4 };
    Node* llistH = CreateList(g, 6);
    ShowList(llistH);
    cout << ((IsPalindrome(llistH)) ? "True" : "False") << endl;
}


/*
EXECUTION CODE:

Problem A, test case 1, removing [2]-[4]:
2 5 8 10 15
Result List:
2 5
Problem A, test case 2, removing [0]-[3]:
1 6 8 13 15 26 30
Result List:
15 26 30
Problem B, test case 1, reversing list:
2 5 8 10 15
Reversed List:
15 10 8 5 2
Problem B, test case 2, reversing list:
1 6 8 13 15 26 30
Reversed List:
30 26 15 13 8 6 1
Problem C, test case 1, right shift:
2 5 8 10 15
Resulting List:
10 15 2 5 8
Problem C, test case 2, right shift:
1 6 8 13 15 26 30
Resulting List:
15 26 30 1 6 8 13
Problem D, test case 1, test if palindrome:
1 4 6 7 6 4 1
True
Problem D, test case 2, test if palindrome:
1 4 6 7 6 4
False

 */
