// Shamitha Pichika
// lab8.cpp
// 02/17/2022
// The following program prints a shorter and longer list of the alphabet using linked
// lists and then frees the memory of the pointers

#include <iostream>
#include <list>
#include <string>
using namespace std;

// desc: A unit of a linked list of strings. Stores a string,
//        with a pointer to the next node (if any)
//  inv: `next` always either points to a valid `Node`
//       instance, or is null

struct Node {
    string name; // you can remove the "std::", if you want
    Node  *next;
};

void print_list(Node *n) {
    while (n != nullptr) {
        cout << n->name << " ";
        n = n->next;
    }
}

// desc: prints letters from linked lists
// pre: Node struct members should be declared
// post: memory hould be freed
int main() {

    string alpha[26] = {"z", "y", "x", "w", "v", "u", "t", "s", "r", "q", "p", "o", "n",
                        "m", "l", "k", "j", "i", "h", "g", "f", "e", "d", "c", "b", "a"};

    // Create a linked list of 4 nodes in stack storage, containing the string sequence {"a","b","c","d"}.
    Node *head   = new Node();
    Node *second = new Node();
    Node *third  = new Node();
    Node *fourth = new Node();
    head->name   = "a";
    head->next   = second;
    second->name = "b";
    second->next = third;
    third->name  = "c";
    third->next  = fourth;
    fourth->name = "d";
    fourth->next = nullptr;

    // Using a for loop, create a linked list of 26 nodes in dynamic storage, which together contain the
    // full lower-case alphabet ("a" to "z").
    cout << "\n\n";
    Node *temp = nullptr;
    Node *result;
    for (int i = 0; i < 26; i++) {
        result       = new Node;
        result->name = alpha[i];
        result->next = temp;
        temp         = result;
    }

    // Using a pointer, iterate through each list and print its contents.
    while (head != nullptr) {
        cout << head->name << " ";
        head = head->next;
    }
    cout << "\n\n";

    while (result != nullptr) {
        cout << result->name << " ";
        result = result->next;
    }

    // Using a for loop, delete all nodes that were dynamically allocated:
    delete head;
    delete second;
    delete third;
    delete fourth;

    for (int i = 0; i < 4; i++) {
        delete result;
    }

    cout << "\n\n";
    return 0;
}
