//Shamitha Pichika
//lab2.cpp
//01/11/2023
//The program belows requests the user for two strings
//and displays them in a swapped format 

#include <iostream>
using namespace std;

//desc: receives two strings from the user
//pre: nothing
//post: stores the two strings inputted by the user
void input(string &first, string &second); 

//desc: swaps the first and second parameter together
//pre: the first and second parameters must be strings 
//post: the first and seconds strings are swapped
void swap_strings(string &first, string &second);

//desc: displays the two strings
//pre: nothing
//post: the first and second strings are displayed to the user
void output(string &first, string &second);

int main() {
    string one, two;
    cout << "\n\n";
    cout << "Welcome to Lab 2! \n\n";
    input(one, two);
    cout << "Before swap: \n";
    output(one, two);
    cout << "\n\n";
    cout << "After swap: \n";
    swap_strings(one, two);
    output(one, two);
    cout << "\n\n";
    cout << "Original order: \n";
    swap_strings(one, two);
    output(one, two);
    cout << "\n\n";

    return 0;
}

void input(string &first, string &second) {
    cout << "Enter in two words (strings): \n";
    cout << "First: ";
    cin >> first;
    cout << "Second: ";
    cin >> second;
    cout << "\n";
}

void swap_strings(string &first, string &second) {
    string temp = first;
    first = second;
    second = temp;
}

void output(string &first, string &second) {
    cout << first << " " << second;
}



