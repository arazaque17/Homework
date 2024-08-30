#include <iostream>
using namespace std;
int main()
{
    int number;
    int digits = 0;
    // get the input ‐ convert if it is negative
    cout << "Please enter an integer: ";
    cin >> number;
    if ( number < 0 ) number = -number;
    // count the number of digits present in the integer
    do
    {
        number /= 10;
        ++digits;
    } while ( number > 0 );

        // present the result as grammatically correct
        cout << "The number has " << digits << " digit";
        if ( digits > 1 ) cout << "s";
        cout << ".\n";
    return 0;
}