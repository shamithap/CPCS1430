// Shamitha Pichika
// board.cpp
// 02/14/2023

#include "board.h"
#include "player.h"
#include <iostream>
using namespace std;

// desc: displays board
// pre: size must be a non-negative integer
// post: nothing
void Board::display() {
    for (int i = 0; i < size; i++) {
        cout << "|";
        for (int j = 0; j < size; j++) {
            cout << squares[i][j];
            cout << "|";
        }
        cout << "\n";
    }
}

// desc: returns true if the board is full of player symbols
// pre: size must be a non-negative integer
// post: players can no longer take turns once baord is full
bool Board::is_full() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (squares[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// desc: returns whether or not player won the game based off of the board state.
// pre: board must be displayed, players must be taking turns
// post: used to increment points in main
bool Board::is_winner(Player player1) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        char row = squares[i][0];
        count    = 0;
        for (int j = 0; j < size; j++) {
            if (squares[i][j] == row && squares[i][j] == player1.get_symbol()) {
                count++;
            }
            if (count == size) {
                return true;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        count    = 0;
        char col = squares[0][i];
        for (int j = 0; j < size; j++) {
            if (squares[j][i] == col && squares[j][i] == player1.get_symbol()) {
                count++;
            }
            if (count == size) {
                return true;
            }
        }
    }

    count = 0;
    for (int i = 0; i < size; i++) {
        char left_diag = squares[0][0];
        if (squares[i][i] == left_diag && squares[i][i] == player1.get_symbol()) {
            count++;
        }
        if (count == size) {
            return true;
        }
    }
    int counter = size - 1;
    count       = 0;
    for (int i = 0; i < size; i++) {
        char right_diag = squares[size - 1][0];
        if (squares[counter][i] == right_diag && squares[counter][i] == player1.get_symbol()) {
            count++;
        }
        counter--;
    }
    if (count == size) {
        return true;
    } else {
        return false;
    }
}

// desc:(constructor) - handles allocation of the memory used by the instance, creating a board
// pre: size must be a non-negative integer
// post: nothing
Board::Board(int size1) {
    size    = size1;
    squares = new char *[size];
    for (int i = 0; i < size; i++) {
        squares[i] = new char[size];
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            squares[i][j] = ' ';
        }
    }
}

// desc: (destructor) - handles deallocation of the memory used by the instance
// pre: squares must have been declared and initialized
// post: squares point to nullptr, cannot be accessed again
Board::~Board() {
    for (int i = 0; i < size; i++) {
        delete[] squares[i];
    }
    delete[] squares;
    squares = nullptr;
}

// desc: adds symbol to board
// pre: square must be avilable for symbol to be added,
// otherwise prints error message and reprompts user
// post: nothing
void Board::add_symbol(int row, int col, char symbol) {
    squares[row - 1][col - 1] = symbol;
}

// desc: checks if board coordinates entered are valid
// pre: inputted coordinates must be integers
// post: the following coordiantes the user enters must be valid,
// otherwise the error messages are reprinted
bool Board::is_valid(int row, int col) {
    if (row < 0 || col < 0 || row > size || col > size) {
        cout << "Out of bounds, please try again: ";
        return false;
    }
    if (squares[row - 1][col - 1] == 'X' || squares[row - 1][col - 1] == 'O') {
        cout << "Not available, try again: ";
        return false;
    }
    return true;
}
