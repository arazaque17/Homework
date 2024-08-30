#include <iostream>
using namespace std;
int main()
{
    int value, digit;
    cout << "Enter a non-zero, positive integer: ";
    cin >> value;
    while ( value != 0 )
    {
        digit = value % 10;
        value /= 10;
        cout << digit << endl;
    }
    return 0;
}