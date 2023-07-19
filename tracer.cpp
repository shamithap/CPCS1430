// Shamitha Pichika
// tracer.cpp
// 02/09/2023

#include "tracer.h"
#include <iostream>
using namespace std;

Tracer::Tracer() {
    name = "default";
    cout << "lifetime of '" << name << "' started \n";

} //(default constructor) - Sets name to "default" and announces the start of the instance's lifetime

Tracer::Tracer(Tracer const &other) {
    name = other.name + " copy";
    cout << "lifetime of '" << name << "' started, copied from '" << other.name << "' \n";

} //(copy constructor) - Sets name to other.name followed by " copy" and announces the start of the instance's lifetime

Tracer::Tracer(char const *name_str) {
    name = name_str;
    cout << "lifetime of '" << name << "' started \n";

} //(converting constructor) - Sets name to name_str and announces the start of the instance's lifetime

Tracer::~Tracer() {
    cout << "lifetime of '" << name << "' ended \n";

} //(destructor) - announces the end of the instance's lifetime

void Tracer::operator=(Tracer const &other) {

    cout << "tracer '" << other.name << "' assigned to tracer '" << name << "' \n";

} //(assignment operator for Tracer) - announces the assignment, but changes no values

void Tracer::operator=(char const *new_name) {
    cout << "tracer '" << name << "' renamed to '" << new_name << "' \n";
    name = new_name;

} //(assignment operator for char const*) - changes name to new_name and announces the rename
