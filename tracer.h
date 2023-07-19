// Shamitha Pichika
// tracer.h
// 02/09/2023

#include <iostream>
using namespace std;
#ifndef TRACER_H
#define TRACER_H
class Tracer {
    private:
    string name;

    public:
    Tracer();
    //(default constructor) - Sets name to "default" and announces the start of the instance's lifetime

    Tracer(Tracer const &other);
    //(copy constructor) - Sets name to other.name followed by " copy" and announces the start of the instance's
    //lifetime

    Tracer(char const *name_str);
    //(converting constructor) - Sets name to name_str and announces the start of the instance's lifetime

    ~Tracer();
    //(destructor) - announces the end of the instance's lifetime

    void operator=(Tracer const &other);
    //(assignment operator for Tracer) - announces the assignment, but changes no values

    void operator=(char const *new_name);
    //(assignment operator for char const*) - changes name to new_name and announces the rename
};
#endif