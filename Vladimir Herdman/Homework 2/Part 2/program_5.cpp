// Program 5: Memory Leak Issue

#include <iostream>
using namespace std;

int main() {
 int *ptr = new int(10);

 cout << *ptr << endl;

 // delete allocated memory
 delete ptr;
 
 return 0;
}