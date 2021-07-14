/* 
 * File:   main.cpp
 * Author: Jordan Moreno
 * Created on July 12, 2021 4:19pm
 * Purpose:  Filter sentences from files into proper lower and uppercase
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <fstream>
#include <string>
#include <cctype>
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Declare variables here
    ofstream out;
    ifstream in;
    char sentence[50];
    string filename1,
           filename2;
    
    //Initialize variables here
    cout << "Enter name of input file .txt: ";
    cin >> filename1;
    in.open(filename1);
    
    cout << "Enter name of output file .txt: ";
    cin >> filename2;
    out.open(filename2);
    if(out){
        cout<<"Opened succesfuly"<<endl;
    }
    
    char arr[50];
    while(in>>sentence){
        cout << sentence << endl;
        int i=0;
        char c;
        
        while(sentence[i]){
            c=sentence[i];
            arr[i] = (tolower(c));
            i++;
        }
        out << arr << endl;
    }
    
    out.close();
    in.close();
    
    
    //Map inputs to outputs here, i.e. the process
    
    //Display the results

    return 0;
}