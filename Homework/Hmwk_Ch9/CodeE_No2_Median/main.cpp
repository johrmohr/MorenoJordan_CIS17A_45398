#include <iostream>
#include <iomanip> //IO manipulators

using namespace std;

int *getData(int);         //Return the array size and the array
void prntDat(int *, int);    //Print the integer array
float *median(int *,int);  //Fill the median Array with the Float array size, the median, and the integer array data
void prntMed(float *, int);     //Print the median Array

int main(){
	//your code here
	int *ary, //Pointer to dynamic int array
	    arySize; //Size of array input
	float *fltAry; //Pointer to dynamic float array
	
	//Get array size input
	cin>>arySize;
	
	//Set ary to the array inputed in getData function
	ary = getData(arySize);
	
	//print the dynamic int array
	prntDat(ary,arySize);
	
	//Create dynamic float array, find median, and fill array
	fltAry = median(ary,arySize);
	
	//Print dynamic float array
	prntMed(fltAry,arySize);
	
	return 0;
}

int *getData(int arySize){
    int *array = new int[arySize];
    arySize=0;
    while(cin>>*(array + arySize)){
        arySize++;
    }
    return array;
}

void prntDat(int *ary, int arySize){
    for(int i=0; i<arySize; i++){
        cout << ary[i];
        if(i<arySize-1){
            cout << " ";
        }
    }
    cout << endl;
}

float *median(int *ary,int arySize){
    int size = arySize+2;
    float *fltAry = new float[size];
    fltAry[0] = size;
    float median;
    if(arySize%2 == 0){
        float g = ary[(arySize/2)];
	    float x = ary[((arySize/2)-1)];
	    median = (g+x)/2;
    } 
    else{
        int f = ary[(arySize/2)];
        median = static_cast<float>(f);
    }
    fltAry[1] = median;
    for(int i=2; i<arySize+2; i++){
        fltAry[i] = ary[i-2];
    }
    return fltAry;
}

void prntMed(float *fltAry, int arySize){
    cout << fltAry[0]<<" ";
    for(int i=1; i<arySize+2; i++){
        cout << fixed << setprecision(2) << fltAry[i];
        if(i<arySize+1){
            cout << " ";
        }
    }
}