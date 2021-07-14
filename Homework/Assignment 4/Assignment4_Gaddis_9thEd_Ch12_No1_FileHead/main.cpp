/* 
 * File:   main.cpp
 * Author: Jordan Moreno
 * Created on July 13, 2021 10:56pm
 * Purpose:  Read file and output first ten lines
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <fstream>
#include <string>
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Declare variables here
    ifstream in;
    string name;
    cout << "Enter file name: ";
    cin >> name;
    in.open(name);
    
    string words;
    int lines=0;
    
    //Loop until the end of the file
    while(!in.eof()) {
        getline(in,words);
        lines++;
        
        if (lines<10) {
            cout << words << endl;
        }
        if(in.eof() && lines<10) {
            cout << endl << "Entire file displayed";
        }
    }
    in.close();
    return 0;
}