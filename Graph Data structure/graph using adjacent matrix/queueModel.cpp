//Queue using linked list 
#include <iostream>
#define Qsize 10
using namespace std;

template <typename T>
class LinkedList{
 public :
	T dataItem;
	LinkedList* next;

};

template <typename T>
class Queue {
	private:
		LinkedList<T>* front;
		LinkedList<T>* rear;
 public:
	Queue(){
		front = NULL;
		rear = NULL;
	}

	LinkedList <T>* getNode(T data){  //returns the address of allocated memory 
		LinkedList<T> * np ;
		np = new LinkedList<T>;
		np->dataItem = data;
		np->next = NULL;
		return np;
	}

	void enqueue(T data){
		LinkedList<T>* ptr = getNode(data);

		if (front == NULL)
			front = rear = ptr;
		else {
		   rear->next = ptr;
		   rear = ptr;
		 } 
	}
	T dequeue(){
		T dataItem;
		if (front == NULL){
			cout<<"Queue is empty"<<endl;
			return NULL;
			}
		else{
			LinkedList<T>* ptr = front;
			front = front->next;
			dataItem = ptr->dataItem;
			delete ptr;

		        return dataItem;

		}
	}
	void show(){
		LinkedList<T>* ptr = front;
		cout<<"[ ";
		while(ptr != NULL){
			cout<<ptr->dataItem<<",  ";
			ptr = ptr->next;
		}
		cout<<"]"<<endl;
				
	}

	bool isEmpty(){
		   return  (front == NULL) ? true : false;
		}
	
};


/*

int main(){
Queue<char> q;
cout<<q.isEmpty();
q.enqueue('1');
q.enqueue('2');
q.enqueue('3');
q.enqueue('5');
cout<<q.dequeue();
q.show();

return 0;
}

*/
