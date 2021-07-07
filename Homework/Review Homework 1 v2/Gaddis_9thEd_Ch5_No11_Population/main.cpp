/*
    Author: Jordan Moreno
    Date:   June 23rd, 2021 &:04 PM
    Purpose: Predict size of population
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
    int org; //Starting # of organisms input
    float popinc; //Average daily population increase input
    int days; //# of days to multiply by input
    int pop=0; //Population prediction output
    
    //Initialize variables
    while (1) {
        cout << "Enter starting number of organisms: ";
        cin >> org;
        if (org > 2) {
            break;
        } 
    }
    
    while (1) {
        cout << "Enter average daily population increase (%): ";
        cin >> popinc;
        if (popinc >= 0) {
            break;
        } 
    }

    while (1){
        cout << "Enter number of days to multiply: ";
        cin >> days;
        if (days >= 1) {
            break;
        } 
    }
    pop = org;
    
    //Process, map inputs to outputs
    for (int i=1; i<=days; i++) {
        float pop1 = static_cast<float>(pop);
        for (int j; j<i; j++) {
            pop1*=(0.01*popinc);
        } pop+=pop1;
        cout << "Day " << i << ", population: " << pop << endl;
    } 
    //Display your initial conditions as well as outputs.
    
    //Exit stage right
    return 0;
}

