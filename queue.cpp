// Shamitha Pichika
// queue.cpp
// the program below has the function bodies of the class Queue

#include "queue.h"
#include <iostream>

// desc: (default constructor) - Initializes the constructing instance to have no elements
// pre: class Queue must be declared, head pointer must exist
// post: nothing
Queue::Queue() {
    head = nullptr;
}

// desc: (copy constructor) - Initializes the constructing instance with an
// independent copy of the input's elements
// pre: other must exist in another class
// post: unused memeory is deallocated
Queue::Queue(Queue const &other) {
    head = nullptr;
    if (other.head == nullptr) {
        head = nullptr;
    } else {
        copy(other);
    }
}

// desc: Frees all dynamic memory used by the destructing instance
// pre: nothing
// post: unused memeory is deallocated
Queue::~Queue() {
    del();
}

// desc: //(assignment operator) - Overwrites
//  the contents of the instance with an independent copy of the input's elements
// pre: other must exist in another class
// post: unused memeory is deallocated
void Queue::operator=(Queue const &other) {
    del();
    if (other.head == nullptr) {
        head = nullptr;
    } else {
        copy(other);
    }
}

// desc: Adds the input value to the instance's collection of elements
// pre: value exists as a member in class stack
// post: nothing
void Queue::enqueue(int value) {
    NodeQueue *newnode = new NodeQueue;
    newnode->next      = nullptr;
    newnode->value     = value;
    if (head == nullptr) {
        head = newnode;
    } else {
        NodeQueue *temp = head;
        head            = newnode;
        head->next      = temp;
    }
}

// desc: Removes and returns whichever element in the instance's collection which was most recently added
// pre: the queue must not be empty (returns 0 if it is)
// post: returns the value to be queued
int Queue::dequeue() {
    if (head == nullptr) {
        return 0;
    } else if (head->next == nullptr) {
        int temp = head->value;
        head     = nullptr;
        return temp;
    } else {
        NodeQueue *iter     = head;
        NodeQueue *previous = nullptr;
        while (iter->next != nullptr) {
            previous = iter;
            iter     = iter->next;
        }
        int temp = iter->value;
        delete iter;
        previous->next = nullptr;

        return temp;
    }
}

// desc: deletes the queue
// pre: nothing
// post: unused memeory is deallocated, head points to nullptr
void Queue::del() {
    NodeQueue *entryptr = head;
    while (entryptr != nullptr) {
        NodeQueue *temp = entryptr->next;
        delete entryptr;
        entryptr = temp;
    }
    head = nullptr;
}

// desc: copies over the queue to other
// pre: other msut exsist in a separate class
// post: nothing
void Queue::copy(Queue const &other) {
    NodeQueue *node_ptr = other.head;
    while (node_ptr) {
        NodeQueue *newnode = new NodeQueue;
        newnode->next      = nullptr;
        newnode->value     = node_ptr->value;

        if (this->head == nullptr) {
            this->head = newnode;
        } else {
            NodeQueue *temp = this->head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
        node_ptr = node_ptr->next;
    }
}

// desc: prints the queue
// pre: nothing
// post: nothing
void Queue::show() {
    NodeQueue *newnode = head;
    while (newnode != nullptr) {
        cout << newnode->value << " ";
        newnode = newnode->next;
    }
}
