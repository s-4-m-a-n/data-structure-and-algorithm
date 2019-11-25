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

void swap(int * min , int * greater){
		 int temp;
		 temp = *min;
		*min = *greater;
		*greater = temp;

}

void selectionSort(int arr[],int len){
	int minIndex;
	for (int i=0; i < len-1 ; i++){
		minIndex = i;
		for (int j = i+1 ; j < len ; j++){
			if (arr[minIndex] > arr[j])
				minIndex = j;
 		}
		if ( i != minIndex)
		swap(&arr[i],&arr[minIndex]);

		printArr(arr,len); // to display iteration
		cout<<endl;
	}


}




int main(){

int elements[MAX] = {1,7,3,9,2,1};
int length = sizeof(elements)/sizeof(elements[0]);

cout<<"---------Inputs-----------"<<endl;
printArr(elements,length);
cout<<endl;

cout<<"---------process-----------"<<endl;
selectionSort(elements,length);
cout<<endl;

cout<<"---------Output------------"<<endl;
printArr(elements,length);
cout<<endl;


return 0;
}
