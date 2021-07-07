#include <iostream>

using namespace std;

int **getData(int &,int &);//Get the Matrix Data
void printDat(const int * const *,int,int);//Print the Matrix
int **augment(const int * const *,int,int);//Augment the original array
void destroy(int **,int);//Destroy the Matrix, i.e., reallocate memory

int main(){
	//your code here
	int **ary,
	    height,
	    length;
	cin >> height >> length;
	
	ary = getData(height,length);
	printDat(ary,height,length);
	
	cout << endl;
	
	ary = augment(ary,height,length);
	printDat(ary,height+1,length+1);
	
	destroy(ary,height);
	
	return 0;
}

int **getData(int &height,int &length){
   int **array = new int*[height];
   for(int i=0; i<height; i++){
       array[i] = new int[length];
   }
   for(int i=0; i<height; i++){
       for(int j=0; j<length; j++)
               cin >> array[i][j];
   }
   return array;
}

void printDat(const int *const *ary, int height, int length){
    for(int i=0; i<height; i++){
        for(int j=0; j<length; j++){
            cout << ary[i][j];
            if(j<length-1){
                cout << " ";
            }
        }
        if(i<height-1){
            cout << endl;
        }
    }   
}

int **augment(const int *const *ary, int height, int length){
   int **array = new int *[height+1];
   for(int i=0; i<height+1; i++){
       array[i] = new int[length+1];
   }
   for(int i=0; i<height+1; i++){
       for(int j=0; j<length+1; j++){
           if(i==0||j==0){
               array[i][j]=0;
           }
           else {
               array[i][j] = ary[i-1][j-1];
           }
       }
   }
   return array;
}

void destroy(int **ary, int height){
     for (int i=0; i<height; i++){
        delete[] ary[i];
     }
    delete ary;
}