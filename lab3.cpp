//Shamitha Pichika
//lab3.cpp
//01/14/2023
//the program below reads non-negative integer values from a txt file and sorts them
//based on if they are divisible by two, three, or neither 

#include <iostream>
#include <fstream>
using namespace std;

const int MAX_SIZE = 30;
const string F_NAME = "/home/st/spichika/cs2/numbers.txt";

//desc: determines whether integer is divisible by two 
//pre: reads value from file
//post: returns true if value is divisible, returns false if not divisible
bool is_even(unsigned int value);

//desc: determines whether integer is divisible by three 
//pre: reads value from file
//post: returns true if value is divisible, returns false if not divisible
bool is_threeven(unsigned int value);

//desc: prints array with last value on a second line
//pre: nothing
//post: returns true if value if divisible, returns false if not divisible
void print_list(unsigned int list[], unsigned int count);


int main()
{
    ifstream infile;
    int num;
    unsigned int even_list[MAX_SIZE] = {0};
    unsigned int threeven_list[MAX_SIZE] = {0};
    unsigned int other_list[MAX_SIZE] = {0};
    int threeCount = 0;
    int evenCount = 0;
    int otherCount = 0;

    infile.open(F_NAME);
  if(infile.fail()) {
    cout << "File failure... exiting program... press enter";
    cin.get();
    return 0;
  }
  while(infile >> num) {
    if(is_even(num)) {
        even_list[evenCount] = num;
        evenCount++;
    } else if(is_threeven(num)) {
        threeven_list[threeCount] = num;
        threeCount++;
    } else {
        other_list[otherCount] = num;
        otherCount++;
    }
  }

cout << "\n\n" << "Even list: " << "\n";
print_list(even_list, evenCount);
cout << "\n\n";
cout << "\n" << "Threeven list: " << "\n";
print_list(threeven_list, threeCount);
cout << "\n\n";
cout << "\n" << "Other list: " << "\n";
print_list(other_list, otherCount);
cout << "\n\n";




    return 0;
}


bool is_even(unsigned int value)
{
    if(value % 2 == 0) {
        return true;
    } else {
        return false;
    }
}
// returns true if and only if the input value is divisible by 2

bool is_threeven(unsigned int value)
{
    if(value % 3 == 0) {
        return true;
    } else {
        return false; 
    }
}
//returns true if and only if the input value is divisible by 3

void print_list(unsigned int list[], unsigned int count)
{
    for(int unsigned i = 0; i < (count - 1); i++) {
        cout << list[i] << ", ";
    }
    cout << "\n" << list[count - 1] << "\n";

}
//prints the first count elements of list, in order, as a comma-separated list,
//with all numbers appearing on one line and the final number followed by a newline