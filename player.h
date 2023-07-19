// Shamitha Pichika
// player.h
// 02/14/2023

#include <iostream>
using namespace std;
#ifndef PLAYER_H
#define PLAYER_H
class Player {

    private:
    char symbol; // represents the symbol (eg 'X' or 'O') the player uses in Tic-Tac-Toe

    int  points; // represents the number of rounds they have won Tic-Tac-Toe during program execution

    public:
    char get_symbol(); // returns the value of symbol.

    void award_point(); // increments the value of points .

    int  get_points(); // returns the value of points.

    Player(char symbol1);
};
#endif