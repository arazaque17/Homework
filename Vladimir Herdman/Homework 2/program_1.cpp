/*
* Pointer Basics
* Write a C++ program that declares an integer variable and a pointer to that integer. Use the
* pointer to modify the value of the integer variable and then print the modified value.
*/

#include <iostream>
using namespace std;

int main() {
    // initialize a and pointer to a
    int a;
    int *ptr = &a;

    // change value of pointer, and therefore a
    *ptr = 12;

    // output value of a to show change
    cout << "Value of variable \'a\':  " << a;

    return 0;
}