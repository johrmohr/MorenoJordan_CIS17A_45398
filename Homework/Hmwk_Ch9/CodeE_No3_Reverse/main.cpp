#include <iostream>

using namespace std;

int *getData(int);       //Fill the array
int *sort(int *,int);    //Sort smallest to largest
int *reverse(int *,int); //Sort in reverse order
void prntDat(int *,int); //Print the array


int main(){
	//your code here
	int arySize, //Size of array input
	    *ary; //Pointer to array
	cin >> arySize;
	
	//set ary to array data entered in getData function
	ary = getData(arySize);
	
	//sort the array
	sort(ary,arySize);

    //print out the sorted array
	prntDat(ary,arySize);
	cout << endl;
	
	//reverse the order of the array
	reverse(ary,arySize);
	
	//print the reversed array
	prntDat(ary,arySize);
	
	
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

int *sort(int *ary, int arySize){
    for(int i=arySize-1; i>=0; i--){
        for(int j=0; j<i; j++){
            if(ary[j]>ary[j+1]){
               int x = ary[j];
               ary[j] = ary[j+1];
               ary[j+1] = x;
            }
        }
    }
}

int *reverse(int *ary, int arySize){
   for(int i=arySize-1; i>=0; i--){
       for(int j=0; j<i; j++){
           if(ary[j]<ary[j+1]){
               int x = ary[j];
               ary[j] = ary[j+1];
               ary[j+1] = x;
           }
       }
   }
}

void prntDat(int *ary, int arySize){
    for(int i=0; i<arySize; i++){
        cout<<ary[i];
        if(i<arySize-1){
            cout << " ";
        }
    }
}