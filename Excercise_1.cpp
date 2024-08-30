#include <iostream>
using namespace std;
const char FAHRENHEIT = 'F';
const char CELSIUS = 'C';
int main()
{
    double inputTemp;
    double convTemp;
    char tempScale;
    char convScale;

    // get the temperature to be converted
    cout << "Enter temperature - indicate scale with C or F: ";
    cin >> inputTemp >> tempScale;

    // check if scale was entered correctly and exit if the input is not valid
    if (tempScale != FAHRENHEIT and tempScale != CELSIUS)
    {
        cout << "Error - temperature scale should be either C or F" << endl;
        return 1;
    }
    // determine which conversion formula to use
    if (tempScale == FAHRENHEIT)
    {
        // input was in Fahrenheit – Convert to Celsius
        convTemp = (5 / 9.0) * (inputTemp - 32);
        convScale = CELSIUS;
    }
    else
    {
        // input was in Celsius – Convert to Fahrenheit
        convTemp = (9 / 5.0) * inputTemp + 32;
        convScale = FAHRENHEIT;
    }
    // display the result
    cout << convTemp << " " << convScale << endl;
    return 0;
}