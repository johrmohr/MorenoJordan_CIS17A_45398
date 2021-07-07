/*
    Author: Jordan Moreno
    Date:   June 26, 2021 2:57 PM
    Purpose: Binary search an array of strings
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <string>      //String Library
using namespace std;   //Library Name-space

//User Libraries

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes
void sort(string[]);
int search(string[], string);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    string names[20] = {"Collins, Bill", "Smith, Bart", "Allen, Jim", 
                             "Griffin, Jim", "Stamey, Marty", "Rose, Geri", 
                             "Taylor, Terri", "Johnson, Jill", "Allison, Jeff", 
                             "Looney, Joe", "Wolfe, Bill", "James, Jean", 
                             "Weaver, Jim", "Pore, Bob", "Rutherford, Greg", 
                             "Javens, Renee", "Harrison, Rose", "Setzer, Cathy", 
                             "Pike, Gordon", "Holland, Beth"};
    string namSea; //Input name to search
    int result;
    
    //Initialize variables
    sort(names);
    cout << "Example 'Last, First', Enter name:";
    cin >> namSea;
    result = search(names, namSea);
    
    //Process, map inputs to outputs
    if (result == 0) {
        cout << "Name was not found";
    }
    else {
    cout << "Name was found at number " << result << " in the array";
    }
    
    //Display your initial conditions as well as outputs.
    
    //Exit stage right
    return 0;
}

void sort(string names[]) {
    int index;
    string value;
    for (int i=0; i<19; i++) {
        index = i;
        value = names[i];
        for (int j=i+1; j<20; j++) {
            if (names[j] < value) {
                index = j;
                value = names[j];
            }
        }
        names[index] = names[i];
        names[i] = value;
    }
}

int search(string names[], string namSea) {
    int first = 1,
        last = 20,
        mid,
        position = 0;
    bool found = false;
    while (!found && first <= last) {
        mid = (first+last)/2;
        if (names[mid] == namSea) {
            found = true;
            position = mid;
        }
        else if (names[mid] > namSea) {
            last = mid-1;
        }
        else {
            first = mid+1;
        }
    }
    return mid;
}