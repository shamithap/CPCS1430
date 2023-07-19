// Shamitha Pichika
// p4.cpp
// 02/21/2023
// The following program uses a linked list to create a to-do list where the user can
// add, remove, check, or uncheck items from their list. They can also raise items

#include "list.h"
#include <iostream>
#include <string>
using namespace std;

char const QUIT = 'Q';

// desc: user enters command and the list is modified via the list.h methods
// pre: TodoList struct members must be initialized
// post: all dynamically allocated memeory SHOULD be freed
int main() {

    TodoList list;
    string   entry, response1;
    char     response = ' ';

    while (response != QUIT) {
        cout << "\n\n LIST: \n";
        list.show();

        cout << "\n\n";
        cout << "Enter command: ";
        // cin >> response;
        getline(cin, response1);
        response = response1[0];
        switch (response) {
        case '+':
            entry = response1.substr(2);
            list.add_entry(entry);
            break;
        case '-':
            entry = response1.substr(2);
            list.remove_entry(entry);
            break;
        case '>':
            entry = response1.substr(2);
            list.check(entry);
            break;
        case '<':
            entry = response1.substr(2);
            list.uncheck(entry);
            break;
        case '^':
            entry = response1.substr(2);
            list.raise(entry);
            break;
        /* case 'v':
            entry = response1.substr(2);
            list.lower(entry);
            break; */
        default:
            break;
        }
    }

    cout << "\n\n";
    return 0;
}