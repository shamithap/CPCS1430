// Shamitha Pichika
// list.h
// 02/21/2023

#include <iostream>
using namespace std;
#ifndef LIST_H
#define LIST_H

class TodoList {

    private:
    struct EntryNode {
        bool       checked; // represents whether or not the entry is checked
        string     text;    // represents the text of the entry
        EntryNode *next;    // identifies the node that follows the containing EntryNode instance
    };
    EntryNode *head;

    public:
    TodoList(); //(default constructor) initializes the constructing instance so that the head member represents an
                // empty linked list
    TodoList(TodoList const &other
    ); //(copy constructor) initializes the constructing instance to match the input, with the head
    // member pointing to a linked list that contains the same sequence of entries as the input instance, but which uses
    // an entirely independent set of EntryNode instances to compose this list.
    ~TodoList(); //(destructor): Frees all outstanding memory allocations used by the destructing instance
    void add_entry(string text
    ); // Performs the action corresponding to the add command, given text as the entry text input.
    void remove_entry(string text
    ); // Performs the action corresponding to the remove command, given text as the entry text input.
    void raise(string text
    ); // Performs the action corresponding to the raise command, given text as the entry text input.
    // void lower(string text
    // ); // Performs the action corresponding to the lower command, given text as the entry text input.
    void check(string text
    ); // Performs the action corresponding to the check command, given text as the entry text input.
    void uncheck(string text
    );           // Performs the action corresponding to the uncheck command, given text as the entry text input.
    void show(); // Displays the entries of the instance (both their text and whether they were checked) in order,
    // from the head of the linked list to the tail.
};
#endif