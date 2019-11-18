//=%
#include <iostream>
#include <cstdbool>
#include <cstdlib>
#include "stackModule.cpp"
#define Qsize 10
using namespace std;

class Node{
 public : 
	char dataItem ;
	Node* next;

};

class Vertex{
 public :
	char dataItem;
	Node * head;  
	Vertex* next;
    
    Vertex(){
	head = NULL;
	next = NULL;
	}

    Node* getNode(char data){
	Node * np = new Node; //Node()
	np->dataItem = data;
	np->next = NULL;
	return np;
	}	

   void addNode(char data){
	Node* np = getNode(data);
	if (head == NULL)
		head = np;
	else{
		Node* ptr = head;
		while(ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = np;
	}
	}
	
};



class Graph{
 private:
 	Vertex* head;
	int size;  // total no of nodes
 public:
	 Graph(){ //constructor	
		head = NULL;
		size = 0;
	}

     Node* getNode(char data){
	Node * np = new Node; //Node()
	np->dataItem = data;
	np->next = NULL;
	return np;
	}


	void addVertex(char data){
		Vertex* newVertex = new Vertex;
		newVertex->dataItem = data ;
		newVertex->head = NULL;
		newVertex->next = NULL;
 
		if ( head == NULL)
			head = newVertex;
		else{
			Vertex* ptr = head;
			while(ptr->next != NULL)
				ptr = ptr->next;
			ptr->next = newVertex;
		}
		 size++;
	}

	void addEdge(char vertexFirst, char vertexSecond){
		Vertex* ptr = head;
		while(ptr->dataItem != vertexFirst && ptr != NULL)
			ptr = ptr->next;
		if (ptr == NULL)
			cout<<"\nvertex : "<<vertexFirst<<"doesnot exist"<<endl;
		else{	
			Node* nodePtr = ptr->head; //edge pointer
			Node* prvPtr = NULL;
			while(nodePtr != NULL && nodePtr->dataItem != vertexSecond){
				prvPtr = nodePtr;				
				nodePtr = nodePtr->next;
			}

			if (nodePtr == NULL && prvPtr == NULL)
				ptr->head = getNode(vertexSecond); 
			else if(nodePtr == NULL)
			  prvPtr->next = getNode(vertexSecond);
			else{
				cout<<"oops!! edge already exists"<<endl;
			}
		}
	}

	void showVertices(){
		Vertex* ptr = head;
		while(ptr != NULL){
			cout<<ptr->dataItem<<endl;
			ptr = ptr->next;
		}
			
	}
	
	Vertex * getPointer(char data){
		Vertex * ptr = head;
		while(ptr->dataItem != data)
			ptr = ptr->next;
		
		 return ptr;
	}
	

	bool isIn(char data , char array[],int count){
			for(int i=0;i<count;i++){
				if (data == array[i])
					return true;
		}
		  return false;
	}


	void depthFirstSearch(){
		Vertex* vertexPtr;
		Node* nodePtr;
		Stack<char> stack;

		char* visitedNode = new char[size]; //array of length = size of the graph = total no. of vertices
		int count = 0;

		vertexPtr = head;
		stack.push(vertexPtr->dataItem);
		while(!stack.isEmpty()){
			visitedNode[count++] = stack.pop();
			cout<<" "<<visitedNode[count-1] << " ";
			vertexPtr = getPointer(visitedNode[count-1]); //**
			
			nodePtr = vertexPtr->head;
			while(nodePtr != NULL){
				if (!isIn(nodePtr->dataItem,visitedNode,count))	// isIn(data,array,sizeofarray)	
					stack.push(nodePtr->dataItem);
				nodePtr = nodePtr->next;				
			}


		}
	}

};

int main(){
 Graph g;
system("clear");
g.addVertex('0');
g.addVertex('1');
g.addVertex('2');
g.addVertex('3');
g.addVertex('4');
g.addEdge('0','2');
g.addEdge('2','1');
g.addEdge('1','0');
g.addEdge('0','3');
g.addEdge('3','4');
g.addEdge('4','0');

g.depthFirstSearch();
cout<<"\n\n";

 return 0;
}

//=%
