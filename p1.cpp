//Shamitha Pichika
//p1.cpp
//01/21/2022
//The program below is a version of tic-tac-toe coded in C++ using functions 
//Each payer takes their turn and the winner is displayed as soon as they win 
//The User(s) also have the option to play again 
//Note: To write the GetWon function and parts of the TakeTurn function, I referenced the textbook
//as well as a few sites on w3 schools to review loops, breaks, and integer functions and analyzed
//a few examples of these concepts online

#include <iostream>
using namespace std;

const int ROW_COL = 3; //numbers of rows and columns
const char YES = 'y'; //char for user to choose to play again
const char PLAYER_1_CHAR = 'X'; //tic-tac-toe char for player one
const char PLAYER_2_CHAR = 'O'; //tic-tac-toe char for player two 

//descr: display welcome message
//pre: nothing
//post: nothing
void welcome();

//descr: display goodbye message
//pre: nothing
//post: nothing
void goodbye();

//descr: creates a 3 X 3 char game board
//pre: nothing
//post: nothing
void CreateBoard(char board [ROW_COL][ROW_COL]);

//descr: displays board to the screen using the CreateBoard function
//pre: board must have been intialized from the CreateBoard function first 
//post: nothing
void DisplayBoard(char board [ROW_COL][ROW_COL]);

//descr: determines the winner
//pre: game board must been updated with player turns 
//post: none, only one winner determined per game 
int GameWon(char board [ROW_COL][ROW_COL], char player);

//descr: runs for both players to take their turns 
//pre: board needs to be intiialized and displayed
//post: function loops as long as no no winner is detected 
void TakeTurn(char board[ROW_COL][ROW_COL], char p1, char p2);

//descr: checks that board is full 
//pre: none
//post: none
int FillBoard(char board[ROW_COL][ROW_COL]);

//descr: determines if the winner is player one, player two, or is a tie 
//pre: must be able to compare results from the GameWon function
//post: none
int FindWinner(char board[3][3], char play1, char play2);

//descr: creates and displays bord from declared char array and calls other game functions
//pre: after first time playing, user must ask to play again to repeat game
//post: none 
int main() {
char answer = YES;
char p1_char ='X';
char p2_char ='O';
char board[ROW_COL][ROW_COL];

welcome();

while(tolower(answer) == YES)
{

CreateBoard(board);

DisplayBoard(board);

TakeTurn(board, PLAYER_1_CHAR, PLAYER_2_CHAR);

cout << "Do you want to play again? (y/n): ";
cin >> answer;
}

cout << "\n\n";
goodbye();
cout << "\n\n";

return 0;
}



void CreateBoard(char board [ROW_COL][ROW_COL]) {
for(int i = 0; i < ROW_COL; i++){
    for(int j = 0; j < ROW_COL; j++){
    board[i][j] = '*';
    }
}

}

void DisplayBoard(char board [ROW_COL][ROW_COL]) {
cout << "\n\n";
cout << "Behold, the Game Board: \n";
cout << "\n";
cout << "    ";
for(int i = 0; i < 3; i++) {
    cout << i << "   ";
}
cout << "\n";
for(int i = 0; i < ROW_COL; i++) {
    cout << i;
    for(int j = 0; j < ROW_COL; j++) {
    cout << " | " << board[i][j];
    }
    cout << " |";
    cout << "\n  \n";
}
cout << "\n\n";
}



int FillBoard(char board[ROW_COL][ROW_COL]){
for(int i = 0; i < ROW_COL; i++) {
    for(int j = 0; j < ROW_COL; j++) {
        if(board[i][j] == '*') {
        return 0;
        }
    }
}
return 1;
}

int GameWon(char board [ROW_COL][ROW_COL], char player){
    return (board[0][0] == player && board[0][1] == player && board[0][2] == player) ||
     (board[1][0] == player && board[1][1] == player && board[1][2] == player) ||
     (board[2][0] == player && board[2][1] == player && board[2][2] == player) ||
     (board[0][0] == player && board[1][0] == player && board[2][0] == player) ||
     (board[0][1] == player && board[1][1] == player && board[2][1] == player) ||
     (board[0][2] == player && board[1][2] == player && board[2][2] == player) ||
     (board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
     (board[0][2] == player && board[1][1] == player && board[2][0] == player);
}


void TakeTurn(char board[ROW_COL][ROW_COL], char p1, char p2){
    int r;
    int c;
    int won;
while(FillBoard(board) != 1) {//Player turn
    while(1) { //Reading positions from user
    cout << "Player 1 (X), enter the row (0-2), press ENTER, then enter the column (0-2) to mark your box: ";
    cin >> r >> c;
//Checking for empty position
    if(board[r][c] == '*') {
    break;
    } else {
    cout << "Sorry, that option is not available. Try again: \n";
    }
    }
//Storing in array
board[r][c] = p1;
//Printing board
DisplayBoard(board);
//Finding winner
won = FindWinner(board, p1, p2);
//If either of winner is found
if(won >= 0 && won <= 2) {//Printing winner
switch(won) {
case 0: 
cout << "Player 1 has won! \n"; 
break;
case 1: cout << "Player 2 has won! \n";
break;
case 2: cout << "It's a tie! \n"; 
break;
}
return;
}
//Player turn
while(1)
{//Reading positions from user
cout << "Player 2 (O), enter the row (0-2), press ENTER, then enter the column (0-2) to mark your box: ";
cin >> r >> c;
//Checking for empty position
if(board[r][c] == '*') {
break;
} else {
cout << "Sorry, that option is not available. Try again: \n";
}
}
//Storing in array
board[r][c] = p2;

//Printing board
DisplayBoard(board);

//Finding winner
won = FindWinner(board, p1, p2);

//If either of winner is found
if(won >= 0 && won <= 2) {//Printing winner
switch(won) {
case 0: 
cout << "Player 1 has won! \n"; 
break;
case 1: cout << "Player 2 has won! \n";
break;
case 2: cout << "It's a draw/tie! \n"; 
break;
}
return; 

}
}
}

int FindWinner(char board[3][3], char play1, char play2){
if(GameWon(board, PLAYER_1_CHAR) == 1 && GameWon(board, PLAYER_2_CHAR) == 1) {
    return 2;
}
else if(GameWon(board, PLAYER_1_CHAR) == 1) {
    return 0;
}
else if(GameWon(board, PLAYER_2_CHAR) == 1) {
        return 1;
    
} else {
            
return -1;
}
}



void welcome() {
    cout << "\n\n";
    cout << "Welcome to tic tac toe!";
    cout << "\n\n";
}

void goodbye() {
    cout << "\n\n";
    cout << "Thanks for playing! Goodbye!";
    cout << "\n\n";
}