#include <stdio.h>

//%= 

void fiboIteration(int);
int  fiboRecursion(int);
void fiboDynamic(int);
int fiboMemoization(int);

int fibo[20];

void main(){
	int n;

	printf("enter any number");
	scanf("%d",&n);

	//fiboIteration(n);
	//printf("\n");
	//for (int i = 0;i<n;i++){
	// printf("%d   ", fiboRecursion(i));
	//}

	//printf("\n");

	//fiboDynamic(n);
	for(int i = 0; i<n;i++){
	   fibo[i] = -1;
	}
	for (int i = 0; i<n;i++){

	printf("%d  ",fiboMemoization(i));

	}
}



void fiboIteration(int n){

int i;
int temp;
int a = 0;
int b = 1;

for (i = 0 ; i < n ; i++){
   printf("%d   ",a);
    temp = a;
    a = b;
    b = temp + b;
}

}


int fiboRecursion(int n){
  if (n ==  1){
    return 1;
 }
else if (n ==  0){
  return 0;
}

else{
  return fiboRecursion(n-2)+fiboRecursion(n-1);
}

}




void fiboDynamic(int n){  //bottom-up approach : dynamic memory allocation

fibo[0] = 0;
fibo[1] = 1;



for (int i = 0  ; i < n ;i++){

     fibo[i+2] = fibo[i] + fibo[i+1];
    printf("%d   ",fibo[i]);
}


}


int fiboMemoization (int n ){  //top-down approach : recursion with memoization 
    
   if ( n < 2){
   return n;
}
  else if (fibo[n] != -1){

return fibo[n];

}

fibo[n]=fiboMemoization(n-1)+fiboMemoization(n-2);

return fibo[n];

}













