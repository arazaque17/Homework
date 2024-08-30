#include <iostream>
using namespace std;
int main()
{
    int score; // student's final score; assumed within [0, 100]
    char grade; // student's letter grade
    // get the student's score
    cout << "Enter score: ";
    cin >> score;
    // check score between 0-100
    if (score < 0 or score > 100) {
        cout << "Individual can not get a score below 0 or above 100" << endl;
        return 1;
    }
    // determine the student's letter grade
    if ( score >= 90 )
    grade = 'A';
    else  // bracket wrong placement, as switch only in else, so A's not printed
    {
            if ( score >= 80 )
            grade = 'B';
        else
        {
            if ( score >= 70 )
            grade = 'C';
            else
            {
                if ( score >= 60 )
                grade = 'D';
                else
                grade = 'F';
            }
        }
    }
    // display results
    switch ( grade )
    {
        case 'A':
            cout << "grade is A\n";
            break;
        case 'B':
            cout << "grade is B\n";  // error here, no break
            break;
        case 'C':
            cout << "grade is C\n";
            break;
        case 'D':
            cout << "grade is D\n";
            break;
        case 'F':
            cout << "grade is F\n";
            break;
    }
}