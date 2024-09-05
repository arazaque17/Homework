// Program 4: Pointer and Const

#include <iostream>
using namespace std;

int main() {
 const int var = 100;  // constant so unchangeable value
 const int *ptr = &var;

 const int different_value = 200; // different constant

 ptr = &different_value; // change 200 into a variable so pointer can point to it's memory address

 cout << *ptr << endl;  // instructions unclear for program end-purpose, so made ptr point to different constant

 return 0;
}