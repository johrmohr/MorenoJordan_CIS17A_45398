/*
    Author: Jordan Moreno
    Date:   June 23, 2021 6:06 PM
    Purpose: Output number of days in a given month
 */

//System Libraries
#include <iostream>    //Input/Output Library
using namespace std;   //Library Name-space

//User Libraries

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    int month; //Month input
    int year; //Year input
    int days; //# of days output
    
    //Initialize variables
    cout << "Enter a month (1-12): ";
    cin >> month;
    cout << "Enter a year: ";
    cin >> year;
    
    //Process, map inputs to outputs
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        days = 31;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        days = 30;
    }
    else if (year%100 == 0 && year%400 == 0 && month == 2) {
        days = 29;
    }
    else if (!(year%100 == 0) && year%4 == 0 && month == 2) {
        days = 29;
    }
    else if (month == 2) {
        days = 28;
    }
    
    //Display your initial conditions as well as outputs.
    cout << days << " days";
        
    //Exit stage right
    return 0;
}

