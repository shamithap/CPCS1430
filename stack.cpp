// Shamitha Pichika
// stack.cpp
// 02/03/2022
// the program below has the function bodies of the class Stack

#include "stack.h"
#include <iostream>
using namespace std;

// desc: (default constructor) - Initializes the constructing instance to have no elements
// pre: class Stack is declared in stack.h
// post: head is later used as beginning of the stack
Stack::Stack() {
    head = nullptr;
}

// desc: (copy constructor) - Initializes the constructing instance with an independent copy of the input's elements
// pre: other is declared and part of a separate stack
// post: the copy of the stack is stored in other
Stack::Stack(Stack const &other) {
    head = nullptr;
    if (other.head == nullptr) {
        head = nullptr;
    } else {
        copy(other);
    }
}
// desc: (destructor) - Frees all dynamic memory used by the destructing instance
// pre: nothing
// post: memeory that was alloacted is freed
Stack::~Stack() {
    del();
}

// desc: (assignment operator for Stack)
// pre: nothing
// post: nothing
void Stack::operator=(Stack const &other) {
    del();
    if (other.head == nullptr) {
        head = nullptr;
    } else {
        copy(other);
    }
}

// desc: Adds the input value to the instance's collection of elements
// pre: data exists as a member in class stack
// post: nothing
void Stack::push(int data) {
    NodeStack *newnode = new NodeStack;
    newnode->next      = nullptr;
    newnode->data      = data;
    if (head == nullptr) {
        head = newnode;
    } else {
        NodeStack *temp = head;
        head            = newnode;
        head->next      = temp;
    }
}

// desc: Removes and returns whichever element in the instance's collection which was most recently added
// pre: data exists as a member in class stack
// post: nothing
// pre: data exists as a member in class stack
// post: nothing
int Stack::pop() {
    if (head != nullptr) {
        NodeStack *node_ptr = head;
        int        temp     = head->data;
        head                = head->next;
        delete node_ptr;
        return temp;
    }
    return 0;
}

// desc: (assignment operator for Stack) - Overwrites the contents of the
//  instance with an independent copy of the input's elements
// pre: nothing
// post: nothing
void Stack::copy(Stack const &other) {
    NodeStack *node_ptr = other.head;
    while (node_ptr) {
        NodeStack *newnode = new NodeStack;
        newnode->next      = nullptr;
        newnode->data      = node_ptr->data;

        if (this->head == nullptr) {
            this->head = newnode;
        } else {
            NodeStack *temp = this->head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
        node_ptr = node_ptr->next;
    }
}

// desc: deletes a stack list (created as to not cause code repetition in the destructor and operator methods)
// pre: nothing
// post: dynamically allocatted memeory is freed
void Stack::del() {
    NodeStack *entryptr = head;
    while (entryptr != nullptr) {
        NodeStack *temp = entryptr->next;
        delete entryptr;
        entryptr = temp;
    }
    head = nullptr;
}

// desc: dispaly stack
// pre: nothing
// post: nothing
void Stack::show() {
    NodeStack *newnode = head;
    while (newnode != nullptr) {
        cout << newnode->data << " ";
        newnode = newnode->next;
    }
}
