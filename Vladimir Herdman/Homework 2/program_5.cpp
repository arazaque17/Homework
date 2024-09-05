/*
* Dynamic Memory Allocation
* Write a C++ program that uses a pointer to dynamically allocate memory for an integer array 
* of size 5, assigns values to the array, and prints them.
*/

#include <iostream>
using namespace std;

int main() {
    // initialize dynamic pointer array (array of pointers)
    int *ptr = new int[5];

    // for loop to set what each pointer in array points to and then print the value in that pointer
    for (int i = 0; i < 5; i++) {
        ptr[i] = (i * 20);
        cout << "Value at location " << i << " of dynamicly allocated array:  " << ptr[i] << endl;
    }
    
    // free up / deallocate memory
    delete[] ptr;
    return 0;
}