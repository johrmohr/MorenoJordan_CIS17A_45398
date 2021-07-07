#include <iostream>

using namespace std;

int *getData(int &);//Read the array
int *augment(const int *,int);//Augment and copy the original array
void prntAry(const int *,int);//Print the array

int main(){
	//your code here
	int *ary,
	    *aug,
	    arySize;
	cin>>arySize;
	
	ary = getData(arySize);
	
	prntAry(ary,arySize);
	
	cout << endl;
	
	aug = augment(ary,arySize);
	
	prntAry(aug,arySize+1);
	
	
	
	return 0;
}

int *getData(int &arySize){
    int *array = new int [arySize];
    for(int i=0; i<arySize; i++){
        cin>>array[i];
    }
    return array;
}

int *augment(const int *ary, int arySize){
    int *augAry = new int [arySize+1];
    augAry[0] = 0;
    for (int i = 0; i<arySize; i++){
        augAry[i+1] = ary[i];
    }
    return augAry;
}

void prntAry(const int *ary, int arySize){
    for (int i=0; i<arySize; i++) {
        cout << ary[i];
        if(i<arySize-1){
            cout << " ";
        }
    }
}