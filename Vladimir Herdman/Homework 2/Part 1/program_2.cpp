/*
* Pointer to an Array
* Write a C++ program that uses a pointer to iterate through an array of integers and print each
* element.
*/

#include <iostream>
using namespace std;

int main() {
    // initialize array a of size 5, and pointer to a
    int a[5] = {10, 20, 30, 40, 50};
    int *ptr = a;

    // for loop to show pointer iterating through array and printing value present
    for (int i = 0; i < 5; i++) {
        ptr = (a + i);
        cout << "Value pointer is pointing at:  " << *ptr << endl;
    }

    return 0;
}