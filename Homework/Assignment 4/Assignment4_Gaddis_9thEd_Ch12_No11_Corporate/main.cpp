/* 
 * File:   main.cpp
 * Author: Jordan Moreno
 * Created on July 13, 2021 9:39 pm
 * Purpose:  
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
struct company{
    string name;
    int quarter[4];
    float sales[4];
};

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Declare variables here
    company a;
    fstream out("sale.txt", ios::out | ios::binary);
    if(out) {
        cout << "Opened successfully";
    }
    
    for (int i=0; i<4; i++) {
        cout << "Enter the Division Name: ";
        cin >> a.name;
        for (int j=0; j<4; j++) {
                cout << "Enter Quarter: ";
                cin >> a.quarter[i];
                cout << "Enter Quarter Sales: ";
                cin >> a.sales[i];
        }
        out.write(reinterpret_cast<char *>(&a),sizeof(a));
    }
    
    out.close();
    
    return 0;
}