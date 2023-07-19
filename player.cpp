// Shamitha Pichika
// player.cpp
// 02/14/2023

#include "player.h"
#include "board.h"
#include <iostream>
using namespace std;

// desc: sets symbol to symbol that user uses to makr their square
// pre: symbol must be declared in player.h
// post: points must be added in main towards the winning player
Player::Player(char symbol1) {
    symbol = symbol1;
    points = 0;
}

// desc: returns user's symbol
// pre: symbol must be declared in player.h
// post: nothing
char Player::get_symbol() {
    return symbol;
}

// desc: increments points towards winning player
// pre: points must be declared in player.h
// post: nothing
void Player::award_point() {
    points++;
}

// desc: return's value of points, displays in main
// pre: user must state they they do not wish to continue game
// post: nothing
int Player::get_points() {

    return points;
}