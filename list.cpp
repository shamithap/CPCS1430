// Shamitha Pichika
// list.cpp
// 02/28/2023

#include "list.h"
#include <iostream>
using namespace std;

// desc: (default constructor) initializes the constructing instance so that the head member represents an empty linked
// list pre: nothing
// post: nothing
TodoList::TodoList() {

    head = nullptr;
}

// desc: //(copy constructor) initializes the constructing instance to match the input, with the head member pointing to
// a
// linked list that contains the same sequence of entries as the input instance, but which uses an entirely independent
// set of EntryNode instances to compose this list.
// list
// pre: other is declared in another list
// post: nothing
TodoList::TodoList(TodoList const &other) {
    if (other.head == nullptr) {
        head = nullptr;
    } else {
        EntryNode *node_ptr = other.head;
        while (node_ptr) {
            EntryNode *newnode = new EntryNode;
            newnode->next      = nullptr;
            newnode->text      = node_ptr->text;
            newnode->checked   = node_ptr->checked;

            if (this->head == nullptr) {
                this->head = newnode;
            } else {
                EntryNode *temp = this->head;
                while (temp->next) {
                    temp = temp->next;
                }
                temp->next = newnode;
            }
            node_ptr = node_ptr->next;
        }
    }
}

// desc: (destructor) : Frees all outstanding memory allocations used by the destructing instance
// pre: nothing
// post: all dynamically allocated memory is freed
TodoList::~TodoList() {
    EntryNode *entryptr = head;
    while (entryptr != nullptr) {
        EntryNode *temp = entryptr->next;
        delete entryptr;
        entryptr = temp;
    }
    // delete head;
}

// desc: Accepts a string entry and adds an entry containing the string's text to the list.
// pre: nothing
// post: nothing
void TodoList::add_entry(string text) {
    EntryNode *newnode = new EntryNode;
    newnode->next      = nullptr;
    newnode->checked   = false;
    newnode->text      = text;
    if (head == nullptr) {
        head = newnode;
    } else {
        EntryNode *temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

// desc: Accepts a string entry and removes all entries from the list that exactly contain that string.
// pre: nothing
// post: nothing
void TodoList::remove_entry(string text) {
    EntryNode *node_ptr = head;
    EntryNode *previous = nullptr;

    if (!head) {
        return;
    }
    if (head->text == text) {
        node_ptr = head->next;
        delete head;
        head = node_ptr;
    } else {
        node_ptr = head;
        while (node_ptr != nullptr && node_ptr->text != text) {
            previous = node_ptr;
            node_ptr = node_ptr->next;
        }
        if (node_ptr) {
            previous->next = node_ptr->next;
            delete node_ptr;
        }
    }
}

// desc: Accepts a string entry and moves all entries in the list that exactly contain that string up by one entry.
// pre: if the first entry in the list matches entry, then none of the matching elements are raised.
// post: nothing
void TodoList::raise(string text) {
    EntryNode *current  = this->head;
    EntryNode *previous = nullptr;
    while (current != nullptr && current->text != text) {
        previous = current;
        current  = current->next;
    }

    if (current == nullptr || previous == nullptr) {
        return;
    }
    EntryNode *before = nullptr;
    if (previous != this->head) {
        before = this->head;
        while (before->next != previous) {
            before = before->next;
        }
    }
    if (before == nullptr) {
        this->head = current;
    } else {
        before->next = current;
    }

    previous->next = current->next;
    current->next  = previous;
}

/*

//I attempted the following lower function but was unsuccessful:

void TodoList::lower(string text) {

    EntryNode* current = head;
    EntryNode* previous = nullptr;

    if(!head) {
        return;
    }

    while(current != nullptr && current -> text != text) {
                previous = current;
                current = current -> next;
            }

        if(!current) {
            return;
        }

        if(!previous) {
            head = current -> next;
        } else {
            previous -> next = current -> next;
        }

        current -> next = current -> next -> next;
        current -> next -> next = current;

        //check if head, then lower it
        //if last node, dont do anything
        //

} *///Accepts a string entry and moves all entries in the list that exactly contain that string down by one entry.
// However, if the last entry in the list matches entry, then none of the matching elements are raised.

// desc: Accepts a string entry and marks all entries in the list that exactly contain that string as "checked".
// pre: nothing
// post: nothing
void TodoList::check(string text) {
    EntryNode *node = head;
    while (node != nullptr) {
        if (node->text == text) {
            node->checked = true;
        }
        node = node->next;
    }
}

// desc: Accepts a string entry and marks all entries in the list that exactly contain that string as "unchecked".
// pre: nothing
// post: nothing
void TodoList::uncheck(string text) {
    EntryNode *node = head;
    while (node != nullptr) {
        if (node->text == text) {
            node->checked = false;
        }
        node = node->next;
    }
}

// desc: // Displays the entries of the instance (both their text and whether they were checked) in order,
// from the head of the linked list to the tail.
// pre: nothing
// post: nothing
void TodoList::show() {
    EntryNode *newnode = head;
    while (newnode != nullptr) {
        cout << newnode->text << " ";
        if (newnode->checked) {
            cout << "(Checked) \n";
        } else {
            cout << "(Unchecked) \n";
        }
        newnode = newnode->next;
    }
}