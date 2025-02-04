/* 
 * RPS.cpp 
 * 
 * Program game is rock paper scissor 
 * 
 * @author Chris Pham 
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int userChoice, computerChoice;

const int ROCK     = 1;
const int PAPER    = 2;
const int SCISSORS = 3;
const int QUIT     = -1;

int getUserSelection();
int getComputerSelection();
bool determineWinner(int userChoice, int computerChoice);

int main()
{
    int userChoice,computerChoice;
    bool continuePlaying = true;
    userChoice = 0;

    srand(time(NULL));

    do
    {
        userChoice = getUserSelection();
        computerChoice = getComputerSelection();
        continuePlaying = determineWinner(userChoice,computerChoice);
    } while (continuePlaying);

    return 0;
}

int getUserSelection()
{
    int input = 0;

    do
    {
        cout << "Make your choice (1: rock, 2: paper, 3: scissors, -1: quit): ";
        cin >> input;

        if (input != QUIT && input != ROCK && input != PAPER && input != SCISSORS)
        {
            cout << "The choice is invalid" << endl;
        }
    }while (input != QUIT && input != ROCK && input != PAPER && input != SCISSORS);

    return input;
}

int getComputerSelection()
{
    return 1 + rand() % 3;
}

bool determineWinner(int userChoice, int computerChoice)
{
    static int userScore = 0;
    static int computerScore = 0;

    if (userChoice == QUIT)
    {
        cout << "GAME OVER" << endl;

        if (userScore > computerScore)
        {
            cout << "The user wins with a score of " << userScore << " to " << computerScore << endl;
        }
        else if (userScore < computerScore)
        {
            cout << "The computer wins with a score of " << computerScore << " to " << userScore << endl;
        }
        else
        {
            cout << "The game is a tie with user score of 0 and computer score of 0" << endl;
        }
        return false;
    }
    cout << "User chooses ";
    switch (userChoice) 
    {
    case ROCK:
        cout << "rock";
        break;
    case PAPER:
        cout << "paper";
        break;
    case SCISSORS:
        cout << "scissors";
        break;
    default:
        break;
    }
        cout << ", Computer chooses ";
        switch (computerChoice) 
        {
        case ROCK:
            cout << "rock";
            break;
        case PAPER:
            cout << "paper";
            break;
        case SCISSORS:
            cout << "scissors";
            break;
        default:
            break;
        }
        cout << endl;

        if (userChoice == computerChoice)
        {
            cout << "Tie, no winner" << endl;
        }
        else if (userChoice == ROCK && computerChoice == SCISSORS)
        {
            cout << "The user wins!" << endl;
            userScore++;
        }
        else if (userChoice == SCISSORS && computerChoice == PAPER)
        {
            cout << "The user wins!" << endl;
            userScore++;
        }
        else if (userChoice == PAPER && computerChoice == ROCK)
        {
            cout << "The user wins!" << endl;
            userScore++;
        }
        else
        {
            cout << "The computer wins!" << endl;
            computerScore++;
        }
        return true;
    }
}


/* 
 * EXECUTION CODE: 
 * 
 * Sample Output #1 
 * Make your choice (1: rock, 2: paper, 3: scissors, -1: quit): -1 
 * GAME OVER 
 * The game is a tie with user score of 0 and computer score of 0 
 * 
 * Sample Output #2 
 * Make your choice (1: rock, 2: paper, 3: scissors, -1: quit): 1 
 * The user wins! 
 * Make your choice (1: rock, 2: paper, 3: scissors, -1: quit): 1 
 * The computer wins! 
 * Make your choice (1: rock, 2: paper, 3: scissors, -1: quit): 2 
 * The computer wins! 
 * Make your choice (1: rock, 2: paper, 3: scissors, -1: quit): 2 
 * The computer wins! 
 * Make your choice (1: rock, 2: paper, 3: scissors, -1: quit): 3 
 * Tie, no winner 
 * Make your choice (1: rock, 2: paper, 3: scissors, -1: quit): 3 
 * The user wins! 
 * Make your choice (1: rock, 2: paper, 3: scissors, -1: quit): -1 
 * GAME OVER 
 * The computer wins with a score of 3 to 2 
 * 
 * Sample Output #3 
 * Make your choice (1: rock, 2: paper, 3: scissors, -1: quit): 4 
 * The choice is invalid 
 * Make your choice (1: rock, 2: paper, 3: scissors, -1: quit): 0 
 * The choice is invalid 
 * Make your choice (1: rock, 2: paper, 3: scissors, -1: quit): 1 
 * Tie, no winner 
 * Make your choice (1: rock, 2: paper, 3: scissors, -1: quit): -1 
 * GAME OVER 
 * The game is a tie with user score of 0 and computer score of 0 
 */ 