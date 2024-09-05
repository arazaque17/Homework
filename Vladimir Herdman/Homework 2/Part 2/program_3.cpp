// Program 3: Incorrect Pointer Dereferencing

#include <iostream>
using namespace std;

int main() {
 int var = 50;
 int *ptr = &var;

 cout << *ptr << endl;
 cout << ptr << endl; // Should print the address

 return 0;
}

// no errors, nothing changed