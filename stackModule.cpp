//=%
// to create an object of stack of specific datatype::  stack <datatype> object;

#include <iostream>
#define QSize 5

using namespace std;

template<typename T>

class stack{

public:
	T dataItems[QSize];
	int top;

	stack(){
	top = -1;
	}


	void push(T data){
	if (top == QSize-1)
		cout<<"stack is full";
	else{
	  dataItems[++top] = data;	
	    }
	}


	T pop(){
	if (top == -1){
                cout<<"empty";
		return NULL;
		}
	else {  
	 	return dataItems[top--];
		}
	}

	void show(){
	for (int i = top ; i > -1 ; i--){
		cout << dataItems[i]<<endl;
	}

	}


};







