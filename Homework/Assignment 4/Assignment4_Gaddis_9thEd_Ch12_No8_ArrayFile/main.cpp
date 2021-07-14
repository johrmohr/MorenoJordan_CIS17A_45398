/* 
 * File:   main.cpp
 * Author: Jordan Moreno
 * Created on July 13, 2021 2:51 pm
 * Purpose:  Use files with functions
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <string>
#include <fstream>
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
const int SIZE = 10;

//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
void arrayToFile (string,int[],int);
void fileToArray (string,int[],int);

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Declare variables here
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int array2[SIZE];
    int *pointer = array;
    string name;
    
    //Initialize variables here
    cout << "Enter file name: ";
    cin >> name;
    
    //Functions
    arrayToFile(name,array,SIZE);
    fileToArray(name,array2,SIZE);
    
    //Display array contents
    for (int i=0; i<SIZE; i++) {
        cout << pointer[i] << endl;
    }
 
    return 0;
}
void arrayToFile (string name,int pointer[],int SIZE){
    fstream file;
    file.open(name, ios::in | ios::binary);
    for (int i=0; i<SIZE; i++) {
        file.write(reinterpret_cast<char *>(pointer), sizeof(pointer));
    }
    file.close();
}

void fileToArray (string name,int pointer[],int SIZE){
    fstream file;
    file.open(name, ios::out | ios::binary);
    for (int i=0; i<SIZE; i++) {
        file.read(reinterpret_cast<char *>(pointer), sizeof(pointer));
    }
    file.close();
}