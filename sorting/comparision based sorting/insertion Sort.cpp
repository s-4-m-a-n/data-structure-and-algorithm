//=%

#include <iostream>
#include <cstdbool>
#include <cstdlib>
#define MAX

using namespace std;

void printArr(int arr[],int len){
	for (int i=0 ; i<len ; i++)
		cout<<arr[i]<<"  ";
}


//-----------------------------------------------------------------
/*
void swap(int * min , int * greater){
		 int temp;
		 temp = *min;
		*min = *greater;
		*greater = temp;

}


void insertionSort(int arr[],int len){
	int indexPointer,searchPointer ;
	for (int i = 1 ; i < len ; i++){
		indexPointer = i;

		while( arr[indexPointer] < arr[indexPointer-1] && indexPointer > 0){
			swap(arr[indexPointer],arr[indexPointer-1]);
			indexPointer--;
		}
	} 
}
*/
//------------------------------------------------------------------


void insertionSort(int arr[],int len){
	int key,j;
	for (int i = 1 ; i < len ; i++){
		key = arr[i];
 		j = i-1 ;
		
		while( j >= 0 && arr[j] > key){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
} 

}


int main(){

int elements[MAX] = {1,7,3,9,2,1};
int length = sizeof(elements)/sizeof(elements[0]);

cout<<"---------Inputs-----------"<<endl;
printArr(elements,length);
cout<<endl;

cout<<"---------process-----------"<<endl;
insertionSort(elements,length);
cout<<endl;

cout<<"---------Output------------"<<endl;
printArr(elements,length);
cout<<endl;


return 0;
}
