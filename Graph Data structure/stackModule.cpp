//=%
// to create an object of stack of specific datatype::  stack <datatype> object;

#include <iostream>
#include <stdbool.h>
#define QSize 10 

using namespace std;

template<typename T>

class Stack{

public:
	T dataItems[QSize];
	int top;

	Stack(){
	top = -1;
	}


	void push(T data){
	if (top == (QSize-1))
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
	
	bool isEmpty(){
		if (top == -1)
			return true;
		else 
			return false;
	}
	
	bool isFull() {
		if (top == QSize-1)
			return true;
		else 
			return false;
	}


};







