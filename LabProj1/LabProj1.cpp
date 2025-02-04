#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

void playAsUser();
void playAsComputer();

int main()
{
    srand(time(0));
    string choice;

    while (true)
    {
        cout << "Would you like to (p)lay, watch the (c)omputer play, or (q)uit?" << endl;
        cin >> choice;

        if (choice == "p")
        {
            playAsUser();
        }
        else if (choice == "c")
        {
            playAsComputer();
        }
        else if (choice == "q")
        {
            break;
        }
        else
        {
            cout << "Please enter (p), (c), or (q)" << endl;
        }
    }
    return 0;
}

void playAsUser()
{
    int target = rand() % 101 + 100;
    int guess;

    while (true)
    {
        cout << "Enter your guess between 100 and 200." << endl;
        cin >> guess;

        if (guess == target)
        {
            cout << "Congrats, you guessed the correct number, " << target << endl;
            break;
        }
        else if (guess < target)
        {
            cout << "Sorry, your guess is too low, try again." << endl;
        }
        else if (guess > target)
        {
            cout << "Sorry, your guess is too high, try again." << endl;
        }
    }
}

void playAsComputer()
{
    int target = rand() % 101 + 100;
    int guess;
    int min = 100;
    int max = 200;

    while (true)
    {
        guess = rand() % (max - min + 1) + min;
        cout << "The computer's guess is " << guess << endl;

        if (guess == target)
        {
            cout << "Congrats, you guessed the correct number, " << target << endl;
            break;
        }
        else if (guess < target)
        {
            cout << "Sorry, your guess is too low, try again." << endl;
            min = guess;
        }
        else if (guess > target)
        {
            cout << "Sorry, your guess is too low, try again." << endl;
            max = guess;
        }
    }
}
/*
EXECUTION CODE
Would you like to (p)play or watch the (c)computer play?
p
Enter your guess between 100 and 200.
150
Sorry, your guess is too low, try again.
Enter your guess between 100 and 200.
175
Sorry, your guess is too low, try again.
Enter your guess between 100 and 200.
188
Sorry, your guess is too high, try again.
Enter your guess between 100 and 200.
181
Congrats, you guessed the correct number, 181.
Would you like to (p)play or watch the (c)computer play or (q)quit?
c
The computer's guess is 150
Sorry, your guess is too low, try again.
The computer's guess is 175
Sorry, your guess is too low, try again.
The computer's guess is 187
Sorry, your guess is too low, try again.
The computer's guess is 193
2
Sorry, your guess is too high, try again.
The computer's guess is 190
Sorry, your guess is too low, try again.
The computer's guess is 191
Sorry, your guess is too low, try again.
The computer's guess is 192
Congrats, you guessed the correct number, 192.
Would you like to (p)play or watch the (c)computer play or (q)quit?
q
 */