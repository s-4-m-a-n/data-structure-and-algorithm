//=%

#include <iostream>
#include <cstdbool>
#include <cstdlib>
#define MAX

using namespace std;

int main(){

int elements[MAX] = {1,7,3,9,2,1};
int length = 6;
cout<<"------------INputs-------------------"<<endl;
for (int i = 0 ; i < length ; i++)
	cout<< elements[i] <<endl;

cout<<"----------- comparision--------------"<<endl;
//----------main algorithm---------------------

for (int i = 0 ; i < length-1 ; i++){
	for (int j = 0 ; j < (length-1)-i; j++)
		{
			if (elements[j] > elements[j+1])
				{	
					int temp = elements[j];
					elements[j]= elements[j+1];
					elements[j+1] = temp;
					cout<<"("<<elements[j]<<","<<elements[j+1]<<")"<< " ";
				}
			
		}
cout<<endl;
}
//----------------------------------------------- 

cout<<"-----------------OUTPUT---------------"<<endl;
for (int i = 0 ; i < length ; i++)
	cout<< elements[i] <<endl;

return 0;
}
