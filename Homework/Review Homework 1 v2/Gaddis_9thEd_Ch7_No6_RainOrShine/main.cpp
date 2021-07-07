/*
    Author: Jordan Moreno
    Date:   June 24, 2021 10:12 PM
    Purpose: Find weather condition frequency in 2d Array from file input
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <fstream>     //File input/output Library
using namespace std;   //Library Name-space

//User Libraries

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    int mon = 3, //Months
	day = 30; //Days
    char weaCons[mon][day]; //Weather conditions
    int Sun, //Sunny days
	Rain, //Rainy days
	Cloudy, //Cloudy days
	totalS = 0, //Total sunny days in 3 months
	totalR = 0, //Total rainy days in 3 months
	totalC = 0, //Total cloudy days in 3 months
        large0 = 0, //Largest number of rainy days in June
        large1 = 0, //Largest number of rainy days in July
        large2 = 0, //Largest number of rainy days in August
        large = 0; //Month with most rainy days
    ifstream File; //File input
        
	File.open("RainOrShine.txt"); //Open file
	for (int i=0; i<mon; i++) {
		for (int j=0; j<day; j++) {
			File >> weaCons[i][j];
		}
	}
	File.close(); //Close file

	cout << endl << "           3 Month Totals " << endl;
	cout << "---------------------------------------------" << endl;
	for (int i = 0; i < mon; i++) {
            Sun = Rain = Cloudy = 0;
            for (int j = 0; j < day; j++) { //Monthly numbers
		switch (weaCons[i][j]) {
                    case 'S' : Sun++;
                    break;
                    case 'R' : Rain++;
                    break;
                    case 'C' : Cloudy++;
                    break;
		}
            }
            //Display monthly numbers
            cout << endl << "For ";
            if (i == 0) {
		cout << "June." << endl;
                large0 += Rain;
            }
            else if (i == 1) {
		cout << "July." << endl;
                large1 += Rain;
            }
            else if (i == 2) {
		cout << "August." << endl;
                large2 += Rain;
            }
            cout << "Rainy days : " << Rain << endl;
            cout << "Sunny days : " << Sun  << endl;
            cout << "Cloudy days: " << Cloudy << endl;

            //Calculate totals
            totalS += Sun;
            totalR += Rain;
            totalC += Cloudy;

            //Calculate largest
            if (large2 > large1 && large2 > large0) {
		large = 2;
            }
            else if (large1 > large2 && large1 > large0) {
                large = 1;
            }
            else if (large0 > large1 && large0 > large2) {
                large = 0;
            }
        }

	//Monthly totals
	cout << endl << "Three month totals. " << endl;
        cout << "Rainy days: " << totalR << endl;
	cout << "Sunny days: " << totalS  << endl;
	cout << "Cloudy days: " << totalC << endl;

	//Most rainy days
	cout << endl << "Month with most rainy days: ";
		if (large == 0) {
			cout << "June." << endl << endl;
                }
		else if (large == 1) {
			cout << "July." << endl << endl;
                }
		else if (large == 2) {
			cout << "August." << endl << endl;
                }
    //Exit stage right
    return 0;
}