// Shamitha Pichika
// tracer.h
// 02/14/2023

#include "player.h"
#include <iostream>
using namespace std;
#ifndef BOARD_H
#define BOARD_H
class Board {
    private:
    char **squares; // stores the state of the board through a dynamic 2D array

    int    size; // size of board

    public:
    void display(); // displays the board state through std::cout

    bool is_full(); // returns true if the board is full of player symbols

    bool is_winner(Player player1); // returns whether or not player won the game based off of the board state.

    Board(int size);
    //(constructor) - handles allocation of the memory used by the instance, creating a board
    // which is size squares wide and size squares high.

    ~Board(); //(destructor) - handles deallocation of the memory used by the instance

    void add_symbol(int row, int col, char symbol);

    bool is_valid(int row, int col);
};
#endif