/* 
 * File: main.cpp
 * Author: Jordan Moreno
 * Date: June
 * Purpose: Question 4 Code-E more output
 */

//System Libraries - Post Here
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries - Post Here

//Global Constants - Post Here
//Only Universal Physics/Math/Conversions found here
//No Global Variables
//Higher Dimension arrays requiring definition prior to prototype only.

//Function Prototypes - Post Here

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    int intval1, intval2, intval3, intval4;
    
    //Retrieve information
    cin>>intval1>>intval2>>intval3>>intval4;
    
    //Display initial conditions, headings here
    
    //Process inputs  - map to outputs here
    
    //Format and display outputs here
    
    //set widths, precision and print
    cout<<setw(9)<<intval1<<setw(10)<<setprecision(1)<<showpoint<<fixed<<static_cast<float>(intval1)
        <<setw(10)                  <<setprecision(2)<<showpoint<<fixed<<static_cast<float>(intval1)<<endl;
    cout<<setw(9)<<intval2<<setw(10)<<setprecision(1)<<showpoint<<fixed<<static_cast<float>(intval2)
        <<setw(10)                  <<setprecision(2)<<showpoint<<fixed<<static_cast<float>(intval2)<<endl;
    cout<<setw(9)<<intval3<<setw(10)<<setprecision(1)<<showpoint<<fixed<<static_cast<float>(intval3)
        <<setw(10)                  <<setprecision(2)<<showpoint<<fixed<<static_cast<float>(intval3)<<endl;
    cout<<setw(9)<<intval4<<setw(10)<<setprecision(1)<<showpoint<<fixed<<static_cast<float>(intval4)
        <<setw(10)                  <<setprecision(2)<<showpoint<<fixed<<static_cast<float>(intval4);
    
    //Exit stage left
    return 0;
}