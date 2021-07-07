/*
    Author: Jordan Moreno
    Date:   June 24, 2021 9:12 PM
    Purpose: Celsius conversion table
 */

//System Libraries
#include <iostream>    //Input/Output Library
using namespace std;   //Library Name-space

//User Libraries

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes
void celsius(float, float);

//Execution Begins Here
int main(int argc, char** argv) {
    float Fah; //Fahrenheit temperature input
    float cel; //Celsius temperature output
    
    //Initialize variables
    
    //Process, map inputs to outputs
    cout << "Fahrenheit temperatures 0-20: " << endl;
    for (int i=0; i<=20; i++) {
        Fah = static_cast<float>(i);
        cout << Fah << " Degrees Fahrenheit = ";
        celsius(Fah, cel);
    }
    
    cout << "Fahrenheit to Celsius Converter" << endl;
    cout << "Enter Fahrenheit temperature: ";
    cin >> Fah;
    cout << Fah << " Degrees Fahrenheit = ";
    celsius(Fah, cel);
    
    //Display your initial conditions as well as outputs.
    
    //Exit stage right
    return 0;
}

void celsius (float Fah, float cel) {
    cel = (Fah-32)/1.8;
    cout << cel << " Degrees Celsius" << endl;
}