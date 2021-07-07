#include <iostream>

using namespace std;

int *getData(int);           //Return the array size and the array from the inputs
int *sumAry(int *,int);  //Return the array with successive sums
void prntAry(int *,int); //Print the array

int main(){
	//your code here
	int arySize, //Size of array input
	    *ary, //Pointer to first array
	    *sum; //Pointer to the sum array
	cin >> arySize;
	
	//Get array data from input into ary
	ary = getData(arySize);
	
	//Print the inputed array
	prntAry(ary,arySize);
	cout << endl;
	
	//Find the sum array and set to sum
	sum = sumAry(ary,arySize);
	
	//Print out the sum array
	prntAry(sum,arySize);
	
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

void prntAry(int *ary, int arySize){
    for(int i=0; i<arySize; i++){
        cout<<ary[i];
        if(i<arySize-1){
            cout << " ";
        }
    }
}

int *sumAry(int *ary, int arySize){
    int *sum = new int[arySize];
    sum[0] = ary [0];
    for (int i=1; i<arySize; i++){
        sum[i] = sum[i-1] + ary[i];
    }
    return sum;
}