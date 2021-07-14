/* 
 * File:   main.cpp
 * Author: Jordan Moreno
 * Created on July 13, 2021 11:19pm
 * Purpose:  Display a file 24 lines at a time
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <string>
#include <fstream>
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
    cout << "Enter file name :";
    cin >>name;
    in.open(name);
    
    string words;
    int lines=0;
    while(!in.eof()) {
        lines++;
        getline(in,words);
        if(lines<=24) {
            cout << words << flush << endl;
        }
        else {
            cout << "Press 1 to view next 24 lines: ";
            int num = cin.get();
            while (num!='1') {
                num = cin.get();
            }
            lines=0;
            cout << words << flush << endl;
        }
        
    }
    in.close();
    
    return 0;
}