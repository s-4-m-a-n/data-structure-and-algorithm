//=%
#include <iostream>
#include <cstdbool>
#include <cstdlib>
#include "stackModule.cpp"
#include "queueModel.cpp"
#define Qsize 10

/*  GrAPH data structure : 




  [ graph: Vertex* head] -----> [ vertex : dataItem ] 	   [        weight   ]      [         weight  ] 
				|	  Node* head|----->[ node : dataItem ]      [ node : dataItem ]
				[      vertex* next ]      [       node* next]----->[       node* next]----> .....

						|	
						|
					       \|/
						v

				[ vertex : dataItem ]      [         weight  ]      [         weight  ] 
				|	  Node* head|----->[ node : dataItem ]      [ node : dataItem ]
				[      vertex* next ]      [       node* next]----->[       node* next]---->.....
						
						|	
						|
					       \|/
						v
						.
						.
						.


*/


using namespace std;

class Node{
 public : 
	char dataItem ;
	int weight;
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

    Node* getNode(char data,int weight){
	Node * np = new Node; //Node()
	np->dataItem = data;
	np->weight = weight;
	np->next = NULL;
	return np;
	}	

   void addNode(char data,int weight){
	Node* np = getNode(data,weight);
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

     Node* getNode(char data,int weight){
	Node * np = new Node; //Node()
	np->dataItem = data;
	np->weight = weight;
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

	void addEdge(char vertexFirst, char vertexSecond,int weight){
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
				ptr->head = getNode(vertexSecond,weight); 
			else if(nodePtr == NULL)
			        prvPtr->next = getNode(vertexSecond,weight);
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
	
	Vertex * getPointer(char data){   // search vertex list 
		Vertex * ptr = head; // graph's head
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
		char node = stack.pop(); 
		if (!isIn(node,visitedNode,count)){
			visitedNode[count++] = node;
			cout<<" "<<node << " ";
			vertexPtr = getPointer(node); 
			
			nodePtr = vertexPtr->head;
			while(nodePtr != NULL){
				if (!isIn(nodePtr->dataItem,visitedNode,count))	// isIn(data,array,sizeofarray)	
					stack.push(nodePtr->dataItem);
				nodePtr = nodePtr->next;				
			}
		    }


		}
	}
	void breadthFirstSearch(){
		Vertex* vertexPtr;
		Node* nodePtr;
		Queue<char> queue;
		
		char* visitedNode = new char[size];
		int count = 0;
		
		vertexPtr = head;
		queue.enqueue(vertexPtr->dataItem);
	
		while(!queue.isEmpty()){
 			char node = queue.dequeue();
		   if (!isIn(node,visitedNode,count)){
			visitedNode[count++] = node;
			cout<<" "<<node<<" ";
		    	vertexPtr = getPointer(node);
			
			nodePtr = vertexPtr->head;
			while(nodePtr != NULL){

				if (!isIn(nodePtr->dataItem,visitedNode,count))
					queue.enqueue(nodePtr->dataItem);  
			
				nodePtr = nodePtr->next;
			}
		     }

		   }
		}

	void displayEdges(){
		Vertex* vertexPtr = head;
			cout<<"EDGES"<<"   "<<"weights"<<endl;
		while( vertexPtr != NULL){
			Node* nodePtr = vertexPtr->head;
			while(nodePtr != NULL){				
				cout<<vertexPtr->dataItem<<"-"<<nodePtr->dataItem<<"   :   "<<nodePtr->weight<<endl;
				nodePtr = nodePtr->next;	
			}
			vertexPtr = vertexPtr->next;
		}

	}


};



int main(){
 Graph g;
system("clear");
g.addVertex('2');
g.addVertex('0');
g.addVertex('3');
g.addVertex('1');
g.addEdge('1','2',3);  // addEdge(char startingNode,char endNode , int weight);
g.addEdge('2','3',5);
g.addEdge('3','3',6);
g.addEdge('2','0',2);
g.addEdge('0','2',2);
g.addEdge('0','1',1);

g.depthFirstSearch();
cout<<"\n\n";
g.breadthFirstSearch();
cout<<"\n\n";
g.displayEdges();
 return 0;
}

//=%
