/*
    Author: Jordan Moreno
    Date:   June 23rd, 2021 5:24 PM
    Purpose: Convert Celsius to Fahrenheit
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
    float cel; //Celsius temperature input
    float Fah; //Fahrenheit temperature output
    
    //Initialize variables
    cout << "Celsius to Fahrenheit Converter" << endl;
    cout << "Enter Celsius temperature:" << endl;
    cin >> cel;
    
    //Process, map inputs to outputs
    Fah = 1.8*cel + 32;
    
    //Display your initial conditions as well as outputs.
    cout << "Conversion: " << Fah << " Degrees Fahrenheit";
    
    //Exit stage right
    return 0;
}

