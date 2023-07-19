//Shamitha Pichika
//lab1.cpp
//01/10/2023

#include <iostream>
using namespace std;

const char YES = 'y';
const int MAX_SIZE = 100;

//display welcome message
void welcome();

//recieves user input values
int input(int num);

//displays largest, smallest, and sum value of the array
void print_statistics(int values[], int count);

//display goodbye message
void goodbye();

int main()
{   
    char answer = YES;
    int inputNum = 0;
    int numElements = 0;
    int counter = 0;
    int arr[MAX_SIZE];
    cout << "\n\n";

    welcome();

    while(tolower(answer) == YES && counter < MAX_SIZE) {
        numElements++;
        arr[counter] = input(inputNum);
        counter++;

        cout << "Another another number (y/n)? \n";
        cin >> answer;
    }

    print_statistics(arr, numElements);

    cout << "\n";
    goodbye();
    cout << "\n\n";
    return 0;
}


 void welcome()
 {
    cout << "Welcome to Lab 1! \n";
 }

 int input(int num)
 {
    cout << "Enter an integer between -100 and 100: ";
    cin >> num;

    while(num < -100 || num > 100) {
        cout << "Oops, number not in range. Try again: ";
        cin >> num;
    }

    return num;
 }

void print_statistics(int values[], int count)
{
    int sum = 0; 
    int min = values[0];
    int max = values[0];

    for(int i = 0; i < count; i++) {
        if(values[i] < values[0]) {
            min = values[i];
        }
        if(values[i] > values[0]) {
            max = values[i];
        }
        sum = sum + values[i];
    }

    cout << "Smallest value: " << min << "\n";
    cout << "Largest value: " << max << "\n";
    cout << "Sum: " << sum << "\n";

}

void goodbye()
 {
    cout << "Now leaving Lab 1...goodbye!";
 }

