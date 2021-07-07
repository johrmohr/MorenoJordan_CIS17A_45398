/*
    Author: Jordan Moreno
    Date:   June 23, 2021 5:55 PM
    Purpose: Convert US Dollars to Japanese Yen and Euros
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <iomanip>
using namespace std;   //Library Name-space

//User Libraries

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    float dol; //US Dollar input
    float yen; //Japanese Yen output
    float euro; //Euro output
    
    //Initialize variables
    cout << "US Dollar conversion to Japanese Yen and Euros" << endl;
    cout << "Enter US Dollar amount: " << endl;
    cin >> dol;
    
    //Process, map inputs to outputs
    yen = (1/98.93)*dol;
    euro = (1/0.74)*dol;
    
    //Display your initial conditions as well as outputs.
    cout << "Amount in Yen: " << setprecision(2) << fixed << yen << endl;
    cout << "Amount in Euros: " << euro;
    
    //Exit stage right
    return 0;
}

