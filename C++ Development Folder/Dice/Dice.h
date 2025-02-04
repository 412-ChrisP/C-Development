#ifndef DICE_DICE_H
#define DICE_DICE_H


class Dice
{
public:
    int diceSize;
private:
    static int rollDice() ;
    explicit Dice(int N);
};


#endif //DICE_DICE_H
