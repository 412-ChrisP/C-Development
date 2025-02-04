/*
 * BallotBox.cpp
 *
 * Tallies vote for selected person and determine who the winner is
 *
 * @author Chris Pham
 */

#include <iostream>
#include <cstdlib>

using namespace std;

const int TIM = 0;
const int SATYA = 0;
const int SUNDAR = 0;
const int ELON = 0;

int Vote;

void getVote();
bool determineWinner(int userVote);

int main()
{


    srand(time(NULL));

    return 0;
}

void getVote()
{
    do
    {
        cout << "Who do you want to vote for (Tim, Satya, Sundar, or Elon)? " << endl;
        cin >> Vote;

        if (Vote != 'Tim' && 'Satya' && 'Sundar' && 'Elon')
        {
            cout << "That is an Invalid choice. " << endl;
        }

        else if (Vote == 'Quit')
        {
            bool determineWinner(int userVote);
        }
    }while(Vote != 'Tim' && 'Satya' && 'Sundar' && 'Elon');

    bool determineWinner(int userVote);
    return;
}

bool determineWinner(int userVote)
{

}