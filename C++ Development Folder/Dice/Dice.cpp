#include "Dice.h"
#include <cstdlib>

Dice::Dice(int N)
{
//set dieSize to the value of int N
    this->diceSize = N;
}

int Dice::rollDice()
{
    int roll;
    int min = 1; // the min number a die can roll is 1
    int max = 6; // this->dieSize; // the max value is the die size

    roll = rand() % (max - min + 1) + min;

    return roll;
}

