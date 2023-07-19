//Shamitha Pichika
//lab4.cpp
//01/21/2022
//The following program uses functions and pointers to request a certain number
//of integers from the user and printing the order of integers in reverse, omitting
//the first integer 

#include <iostream>
#include <string>
using namespace std;

//desc: returns a pointer of type int with count elements
//pre: function must be assigned to a decalred int pointer when called 
//post: nothing
int* new_int_array(int count);

//desc: de-allocates the pointer, freeing memory
//pre: pointer must have been initially declared 
//post: pointer must not be used again 
void delete_int_array(int* array_ptr);

//desc: places count number of integers into the array via user input
//pre: pointer must have been initially declared 
//post: pointer must not be used again 
void read_ints(int* array_ptr, int count);

//desc: reverses the order of ints in the array, removing the first integer
//pre: all values of the array must be known 
//post: ints are printed in reverse displayed to the user
void reverse(int array_ptr[], int count);

//desc: initializes size of array, calls functions, displays reversed array to user
//pre: Max size of array and pointer must be declared 
//post: pointed is dis-allocated, so cannot be called again 
int main() {   

unsigned int N;
int* arr_ptr = nullptr;

cout << "\n\n";
cout << "Enter a non-negative integer: ";
cin >> N;

arr_ptr = new_int_array(N);

cout << "Enter " << N <<  " integers: \n";
    
read_ints(arr_ptr, N);

cout << "\n\n";
cout << "\n The numbers in reverse (w/o the first integer) are: \n\n";

reverse(arr_ptr, N);

delete_int_array(arr_ptr);

cout << "\n\n";

return 0;

} //end main

int* new_int_array(int count) {
    int *arr_ptr = nullptr;
    arr_ptr = new int[count];

 return arr_ptr;
}
//returns a pointer to an int array with count elements, allocated with new[]


void delete_int_array(int* array_ptr) 
{
    delete [] array_ptr;
    array_ptr = nullptr;
}
//de-allocates the int pointed by ptr with delete[]

void read_ints(int* array_ptr, int count) {
    for(int i = 0; i < count; i++) {
        cin >> (*(array_ptr + i));
    }
}
//takes exactly count integers from the user as input,
//placing the integers into the array identified by array_ptr in the order they were received

void reverse(int array_ptr[], int count) {
   int* start = &array_ptr[0];      
    int* finish = &array_ptr[count - 1];

    while(start <= finish)
    {
        int* temp = start;
        start = finish;
        finish = temp;
        start++; 
        finish--; 
    }
    for (int i = (count - 1); i > 0; i--)
    {
        cout << array_ptr[i] << ' ';
    }
 
}
//reverses the array of integers, skipping over the first integer before the reverse 

