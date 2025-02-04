/*
 * BallotBox.cpp
 *
 * Tallies vote for selected person and determine who the winner is
 *
 * @author Chris Pham
 */

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<pair<int, string> >getVote(string str, vector<pair<int, string> >& v)
{
    char c;
    if (str == "Tim")
    {
        c = 'T';
    }
    else if (str == "Satya")
    {
        c = 'S';
    }
    else if (str == "Sunder")
    {
        c = 'N';
    }
    else if (str == "Elon")
    {
        c = 'E';
    }
    else if (str == "quit")
    {
        c = 'q';
    }
    switch (c)
    {
        case 'T':
            v[0].first++;
            break;

        case 'S':
            v[1].first++;
            break;

        case 'N':
            v[2].first++;
            break;

        case 'E':
            v[3].first++;
            break;

        case 'q':
            break;
        default:
            cout << "That is a invalid choice" << endl;
            break;
    }
    return v;
}

void printResult(vector<pair<int, string> >vec)
{
    sort(vec.begin(), vec.end());
    int n = vec.size();
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            cout << left << setw(15) << vec[i].second << setw(5) << vec[i].first << setw(10) << "Winner" << endl;
        }
        else
        {
            cout << left << setw(15) << vec[i].second << setw(5) << vec[i].first << setw(10) << endl;
        }
    }
    cout << endl;
}
int main()
{
    string str;
    vector<pair<int, string> > vec = { {0,"Tim"},{0,"Satya"},{0,"Sunder"},{0,"Elon"} };
    do
    {
        cout << endl;
        cout << "Who do you want to vote for (Tim, Satya, Sunder, or Elon) quit for exit: ";
        cin >> str;
        vec = getVote(str, vec);
    }
    while (str != "quit");
    printResult(vec);
    return 0;

/*
EXECUTION CODE:
Who do you want to vote for (Tim, Satya, Sunder, or Elon) quit for exit: Bill
That is a invalid choice
Who do you want to vote for (Tim, Satya, Sunder, or Elon) quit for exit: Tim
Who do you want to vote for (Tim, Satya, Sunder, or Elon) quit for exit: Elon
Who do you want to vote for (Tim, Satya, Sunder, or Elon) quit for exit: Tim
Who do you want to vote for (Tim, Satya, Sunder, or Elon) quit for exit: quit

Satya          0
Sunder         0
Elon           1
Tim            2    Winner
*/
}