//=%
#include <iostream>
#include <cstdbool>
#include <cstdlib>


using namespace std;

class Node{
 public : 
	char dataItem ;
	Node* next;

};

class Vertex{
 public :
	Node * head; // head of each linked list as  a dataItem 
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

    void createNode(char data){
	Node* np = getNode(data);
	 head = np;
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

 public:
	 Graph(){ //constructor	
		head = NULL;
	}

     Node* getNode(char data){
	Node * np = new Node; //Node()
	np->dataItem = data;
	np->next = NULL;
	return np;
	}


	void addVertex(char data){
		Vertex* newVertex = new Vertex;
		newVertex->createNode(data);
		if ( head == NULL)
			head = newVertex;
		else{
			Vertex* ptr = head;
			while(ptr->next != NULL)
				ptr = ptr->next;
			ptr->next = newVertex;
		}
		 
	}

	void addEdge(char vertexFirst, char vertexSecond){
		Vertex* ptr = head;
		while(ptr->head->dataItem != vertexFirst && ptr != NULL)
			ptr = ptr->next;
		if (ptr == NULL)
			cout<<"\nvertex : "<<vertexFirst<<"doesnot exist"<<endl;
		else{	
			Node* nodePtr = ptr->head;
			Node* prvPtr;
			while(nodePtr != NULL && nodePtr->dataItem != vertexSecond){
				prvPtr = nodePtr;				
				nodePtr = nodePtr->next;
			}

			if(nodePtr == NULL)
			prvPtr->next = getNode(vertexSecond);
			else{
				cout<<"oops!! edge already exists"<<endl;
			}
		}
	}

	void showVertices(){
		Vertex* ptr = head;
		while(ptr != NULL){
			cout<<ptr->head->dataItem<<endl;
			ptr = ptr->next;
		}
			
	}

	
};

int main(){
 Graph g;
g.addVertex('1');
g.addVertex('2');
g.addVertex('3');
g.addEdge('1','2');
g.addEdge('2','3');
g.showVertices();

 return 0;
}

//=%
