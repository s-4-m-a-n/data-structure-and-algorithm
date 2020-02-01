#include <stdio.h>
void MergeSort(int [] ,int ,int);
int Partation(int [],int,int);
int main()
{  
    int arr[] = {7,6,2,1,6,5,8,1,0,2,3};
    int l = 0;
    int r = (sizeof(arr) / sizeof(arr[0])) -1 ;

    MergeSort(arr,l,r);    
    for (int i = 0 ; i <= r ; i++)
        printf("%d ,",arr[i]);
}

 void MergeSort(int A[],int l,int r){
    if (l < r){
        int p = Partation(A,l,r);
        MergeSort(A,l,p-1);
        MergeSort(A,p+1,r);
    }
    
}


int Partation(int A[],int l , int r){
    int x = l;
    int y = r;
    int p = A[l];
 while(x<y){   
    while(A[x] <= p && x < r)
            x++;
    
    while(A[y] >= p && y > l)
            y--;
    
    if(x < y)
        {
            int temp = A[x];
            A[x] = A[y];
            A[y] = temp;
            
        }
}
    
A[l] = A[y];
A[y] = p; 
    
return y;
}
