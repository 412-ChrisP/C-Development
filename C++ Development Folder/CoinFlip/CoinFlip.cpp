#include <iostream>

#include <cmath>



using namespace std;



bool coinflip()

{

    int min = 1, max = 2, coin;

    coin = (rand() % (max - min + 1)) + min;



    if (coin == min)

        return true;

    else

        return false;

}

float playGame(float balance)

{

    int n = 0;

    float winnings, newBalance, cost = 5.50;

    cout << "Game Results: ";

    bool face = coinflip();

    if (face == true)

    {

        cout << "H\n";

        n = 1;

    }

    else

    {

        while (face == false)

        {

            cout << "T";

            face = coinflip();

            n++;

        }

        cout << "H\n";

        n++;

    }

    cout << "Prev. Balance: " << balance << "\n";

    cout << "Game cost: 5.50 \n";

    winnings = pow(2, (n - 2));

    cout << "Winnings: " << winnings << "\n";

    newBalance = balance - cost + winnings;

    cout << "New Balance: " << newBalance << "\n";

    return newBalance;

}



int main()

{

    int coutH = 0, coutT = 0;

    float prevBalance = 0, wins;

    string choice;

    cout << "Welcome to the Coin Flip Game! \n";

    cout << "Here's a 100-Flip Example (T=Tails, H= Heads): ";

    for (int i = 0; i < 100; i++)

    {

        int n = 0;

        bool side = coinflip();

        if (side == true)

        {

            cout << "H";

            coutH++;

        }

        else

        {

            cout << "T";

            coutT++;

        }

    }

    cout << "\n There were " << coutH << " heads and " << coutT << " tails";

    cout << "Each game costs $5.50. We'll flip a coin until the first Head appears, on the nth flip \n";

    cout << "Your winnings will be $2^(n-2). Would you like to play a game?";

    cin >> choice;

    while (choice == "y" || choice == "Y")

    {

        prevBalance = playGame(prevBalance);

        cout << "\n WOuld you like to play another game for $5.50?";

        cin >> choice;

    }

    cout << "Thanks for playing! Congratulations on your winnings of $" << prevBalance;

    return 0;

} 

 