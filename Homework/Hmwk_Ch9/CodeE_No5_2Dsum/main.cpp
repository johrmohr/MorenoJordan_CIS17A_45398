#include <iostream>

using namespace std;

int **getData(int &,int &);               //Return the 2-D array and its size.
void prntDat(const int* const *,int,int); //Print the 2-D Array
void destroy(int **,int,int);             //Deallocate memory
int sum(const int * const *, int,int);    //Return the Sum

int main(){
	//your code here
	int **ary, //Pointer to the array
	    height, //height of 2d array input
	    length; //length of 2d array input
	
	ary = getData(height,length);
	
	prntDat(ary,height,length);
	
	cout << sum(ary,height,length);

    destroy(ary,height,length);
	
	
	return 0;
}

int **getData(int &height, int &length){
    cin >> height >> length;
    int **ary = new int*[height];
    for (int i=0; i<height; i++){
        ary[i] = new int[length];
        for (int j=0; j<length; j++){
            cin >> ary[i][j];
        }
    }
    return ary;
}

void prntDat(const int *const *ary, int height, int length){
    for (int i=0; i<height; i++){
        for (int j=0; j<length; j++){
            cout << ary[i][j];
            if(j<length-1){
            cout << " ";
            }
        }
        cout << endl;
    }
}

void destroy(int **ary, int height, int length){
     for (int i=0; i<height; i++){
        delete[] ary[i];
     }
    delete ary;
}

int sum(const int *const *ary, int height, int length){
    int sum = 0;
    for (int i=0; i<height; i++){
        for (int j=0; j<length; j++){
            sum += ary[i][j];
        }
    }
    return sum;
}