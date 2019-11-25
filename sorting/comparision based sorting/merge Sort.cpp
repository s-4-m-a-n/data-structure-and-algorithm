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

void merge(int arr[],int l,int m,int r){
	int nL = m-l+1;
	int nR = r-m;

	 /* create temp arrays */
	int L[nL]; //left subArray
	int R[nR]; //right subArray

	/* Copy data to temp arrays L[] and R[] */
	for (int i=0;i<nL;i++)
	      L[i]= arr[l+i];
	for (int i = 0 ; i < nR ; i++)
		R[i] = arr[(m+1)+i];


	/* Merge the temp arrays back into arr[l..r]*/
	int i = 0; // Initial index of first subarray 
	int j =0; // Initial index of second subarray
 	int k = l; // Initial index of merged subarray 

	
	while(i < nL && j < nR){
		if (L[i] < R[j])
			arr[k++] = L[i++];
		else 
			arr[k++] = R[j++]; 
	} 
	
 	/* Copy the remaining elements of L[], if there 
       are any */
	while(i < nL){
		arr[k++] = L[i++];
	}
	while(i < nR){
		arr[k++] = R[j++];
	}

}



void mergeSort(int arr[],int l , int r){
	int m = (l+r)/2;   // to avoid overflow used m = l + (r-l)/2

	
	if (l < r){
	
	mergeSort(arr,l,m);  //divide
	mergeSort(arr,m+1,r);//divide

	merge(arr,l,m,r); //conquer
	
}	
}




int main(){

int elements[MAX] = {1,7,3,9,2,1};
int length = sizeof(elements)/sizeof(elements[0]);

cout<<"---------Inputs-----------"<<endl;
printArr(elements,length);
cout<<endl;

cout<<"---------process-----------"<<endl;
mergeSort(elements,0,length-1);
cout<<endl;

cout<<"---------Output------------"<<endl;
printArr(elements,length);
cout<<endl;


return 0;
}
