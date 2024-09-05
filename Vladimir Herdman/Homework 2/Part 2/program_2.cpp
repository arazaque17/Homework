// Program 2: Array of Pointers:

#include <iostream>
using namespace std;

int main() {
    int arr[3] = {1, 2, 3};
    int *ptr[3];

    for(int i = 0; i < 3; i++) {
        ptr[i] = &arr[i];
    }

    for(int i = 0; i < 3; i++) {
        cout << *ptr[i] << endl;
    }

    return 0;
}

// no errors, nothing changed