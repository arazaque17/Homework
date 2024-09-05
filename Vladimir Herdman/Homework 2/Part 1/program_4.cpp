/*
* Pointer to Pointer
* Write a C++ program that demonstrates the use of a pointer to a pointer by modifying the
* value of an integer through the pointer to pointer.
*/

#include <iostream>
using namespace std;

int main() {
    // initialize a, pointer to a, and pointer to the pointer
    int a = 4;
    int *ptr = &a;
    int **ptr_ptr = &ptr;

    // print value of a before change
    cout << "Value before changing:  a=" << a << endl;

    // change value of teh pointer that pointes to a pointer
    **ptr_ptr = 25;

    // print out value of a to show change
    cout << "New value:  a=" << a << endl;

    return 0;
}