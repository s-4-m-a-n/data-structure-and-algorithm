//=%
#include <iostream>
using namespace std;


template <typename T>

class Node{
 public : 
	T dataItem ;
	Node<T>* next;

};

template <typename T>

class LinkedList{
 public : 
// data member
	  Node<T>* head;
public:	  int length;
//member functions
public :   LinkedList(){
		head = NULL;
		length = 0;
		}

private : Node<T>* getNode(T data){
 		Node<T>* newNode = new Node<T>;
		newNode->dataItem = data;
		newNode->next = NULL;
		return newNode;
	}
 public:
   void addNode(T data){
	Node<T>* newNode = getNode(data);
	if(head == NULL){
		head = newNode;
		length++;
	} 
	else{
		length++;
		Node<T>* ptr = head;
		while(ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = newNode;
	} 
      }	
   void show(){
	Node<T>* ptr = head;
	if(ptr == NULL){
		cout<<"\n linked List is empty \n ";
		}
	else{
		cout<<"[ ";
	while(ptr != NULL){
		cout<<ptr->dataItem<<", ";
		ptr = ptr->next;		
		}
		cout<<"]"<<endl;
	    }
     }


  T index(int index = -1){
	Node<T>* ptr = head;
	if(length == 0 || index > (length-1)){
		cout<<"\n LInked List is empty\n";
		return NULL;
		}
	
	else{
		if (index == -1)
			index = length-1 ; // indexing last item 
		for (int j = 1 ; j <= index ; j++)
			ptr = ptr->next;

		return ptr->dataItem;
	}

	}
    void remove(int index = -1){
	if (index > length-1){
		cout<<"\nerror : index value is out of range. Item cannot be removed. \n";
		}
	else if (index == 0){
		Node<T>* ptr = head;
		head = head->next;
		delete(ptr);
		length--;
	}
	else if (index == -1) {// remove last item
		Node<T>* ptr = head;
		Node<T>* prvptr ;
		while(ptr->next != NULL){
			prvptr = ptr;	
			ptr = ptr->next;
			}
		prvptr->next = NULL;
		delete(ptr); 
		length--;
	}
	else {
		Node<T>* ptr = head;
		for (int j = 1 ; j < index ; j++)
			ptr = ptr->next;

		Node<T>* pt = ptr->next;
		ptr->next = pt->next;
		delete(pt);
		length--;
		}
	}
};





/*

LinkedList<char> l1 ;
l1.addNode('A');
l1.addNode('B');
l1.addNode('C');
l1.remove(4); // remove(<index value>)
l1.show();
char item = l1.index(0);  // returns the data Item of given index value
cout << l1.length;
*/




//=%
