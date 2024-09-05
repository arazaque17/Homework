// Program 1: Pointer Arithmetic

#include <iostream>
using namespace std;

int main() {
    int arr[3] = {10, 20, 30};
    int *ptr = arr;

    cout << *ptr++ << endl;
    cout << *ptr++ << endl;
    cout << *ptr++ << endl;

    return 0;
}

// no errors, nothing changed