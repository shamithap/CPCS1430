// Shamitha Pichika
// stack.h

#include <iostream>
using namespace std;
#ifndef STACK_H
#define STACK_H

class Stack {

    private:
    struct NodeStack {
        int        data;
        NodeStack *next;
    };

    NodeStack *head;

    void       del();

    void       copy(Stack const &other);

    public:
    Stack(); //(default constructor) - Initializes the constructing instance to have no elements

    Stack(Stack const &other); //(copy constructor) - Initializes the constructing instance with an
    // independent copy of the input's elements

    ~Stack(); //(destructor) -Frees all dynamic memory used by the destructing instance

    void operator=(Stack const &other); // (assignment operator for Stack)
    //- Overwrites the contents of the instance with an independent copy of the input's elements

    void push(int value); //- Adds the input value to the instance's collection of elements

    int  pop(); //- Removes and returns whichever element in the instance's collection which was most
    // recently added. If the instance evaluating the method is empty,it should throw an instance of
    // std::runtime_error containing an appropriate error message.

    void show();
};
#endif
