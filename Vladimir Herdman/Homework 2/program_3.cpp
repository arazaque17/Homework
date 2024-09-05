/*
* Swapping Values Using Pointers
* Write a C++ program that swaps the values of two integer variables using pointers.
*/

#include <iostream>
using namespace std;

int main() {
    // initialize a and b with values
    int a = 2;
    int b = 24;

    // print values before changing
    cout << "Values before swap:  a=" << a << " b=" << b << endl;
    
    // swap method using pointers
    swap(a, b);

    // print out values to show change
    cout << "New values:  a=" << a << " b=" << b << endl;

    return 0;
}

void swap(int *ptr1, int *ptr2) {
    // create temp to hold value present in pointer 1
    int temp = *ptr1;
    // set value in pointer 1 to value in pointer 2
    *ptr1 = *ptr2;
    // set value in pointer 2 to temp value that saved what was originally in pointer 1
    *ptr2 = temp;
}