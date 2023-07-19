// Shamitha Pichika
// p3.cpp
// 02/14/2023
// The following program uses classes and a 2d array pointer to create
// a tic-tac-toe baord game that can be played on any size the users wish

#include "board.h"
#include "player.h"
#include <iostream>
using namespace std;

char const YES = 'y';

// desc: both users take turns playing
// pre:player and board classes must be intialized
// post: memeory of char board is free
int main() {
    int    size, row, col;
    char   answer  = YES;
    bool   p1turn  = true;
    Player player1 = Player('x');
    Player player2 = Player('O');
    cout << "\nWelcome to Tic-Tac-Toe with Classes!\n";
    while (tolower(answer) == YES) {
        cout << "\n\n";
        cout << "Enter in the desired dimensions of your board: ";
        cin >> size;
        Board board1 = Board(size);
        cout << "\n";
        board1.display();
        cout << "\n";
        while (!board1.is_winner(player1) && !board1.is_winner(player2) && !board1.is_full()) {
            if (p1turn) {
                cout << "\nPlayer (" << player1.get_symbol()
                     << "), enter the row and column to mark your box, then press enter: ";
            } else {
                cout << "\nPlayer (" << player2.get_symbol()
                     << "), enter the row and column to mark your box, then press enter: ";
            }
            cin >> row >> col;
            while (!board1.is_valid(row, col)) {
                cin >> row >> col;
            }
            if (p1turn) {
                board1.add_symbol(row, col, player1.get_symbol());
                p1turn = false;
            } else {
                board1.add_symbol(row, col, player2.get_symbol());
                p1turn = true;
            }
            board1.display();
        }
        if (board1.is_winner(player1)) {
            cout << "\n Player 1 wins! \n";
            player1.award_point();
        } else if (board1.is_winner(player2)) {
            cout << "\n Player 2 wins! \n";
            player2.award_point();
        } else {
            cout << "\n Nobody won! \n";
        }
        cout << "\n\n";
        cout << "Want to play again? (y/n): ";
        cin >> answer;
        cout << "\n";
    }

    if (player1.get_points() > player2.get_points()) {
        cout << "Player 1 won " << player1.get_points() << " point(s)!";
    } else {
        cout << "Player 2 won " << player2.get_points() << " point(s)!";
    }

    cout << "\n\nHave a nice day!\n\n";

    return 0;
}
