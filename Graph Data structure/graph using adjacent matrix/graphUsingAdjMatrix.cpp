//=%
#include <iostream>
#include <cstdlib>
#include <cstdbool>
#include "stackModule.cpp"
#include "queueModel.cpp"

using namespace std;

template<typename T>

class Graph {
  private :
	    int** adjMatrix;
	    T* vertices; // array that stores the name of the vertices 
	    int size; //total no of nodes/vertices of the graph 
	    int verticesPointer; //stores the last index of vertices array


 public:
//----constructor creating 2d matrix dynamically ------------------------------------
	Graph(int n){  // since rows and colms of the matrix is equal . so size = row = colms
		size = n;
		adjMatrix = new int*[size];
		for (int i = 0 ; i < size ; i++)
			adjMatrix[i] = new int[size];
		
		setAdjMatrix();
		vertices = new T[size]; //**
		verticesPointer  = -1;
	}

	void setAdjMatrix(){  //initializing 0's to the adj Matrix
		for (int i = 0 ; i < size ; i++){
			for (int j = 0 ; j < size ; j++)		
				adjMatrix[i][j]=0;				
		}

	}

	
	~Graph(){  //destructor 
		for(int i = 0 ; i < size ; i++ )
			delete [] adjMatrix[i];
		delete [] adjMatrix;
		delete [] vertices;
	}
	
//----------------------------------------------------------------
//---------------- member functions ------------------------------

	int mappingIndex(T vertex){ //return the index value of respective vertices
		for (int i  = 0 ; i <= verticesPointer ; i++ ){
			if (vertices[i]  == vertex)
				return i;
		}	
		return -1; // if vertex doesnot exist return -1
	}


	void addVertex(T vertex){
		vertices[++verticesPointer]  = vertex;
	}
	
	void addEdge(T from , T to){
		int indexOfFrom = mappingIndex(from);
		int indexOfTo = mappingIndex(to);
	      if (indexOfFrom != -1 && indexOfTo != -1)  
			adjMatrix[indexOfFrom][indexOfTo]++;   // more than one edge is acceptable. 
	      else
		cout<<"\n ! error on adding edge\n\t :!: make sure vertex is added into the graph\n";
	}


	void show(){
		cout<<"   ";
		for (int i = 0 ; i <= verticesPointer ;i++)
			cout<<vertices[i]<<"  ";
		cout<<endl;
		for (int i = 0 ; i < size ; i++ ){
			cout<<vertices[i]<<"  ";
			for (int j = 0 ; j < size ; j++)
				cout<<adjMatrix[i][j]<<"  ";
			cout<<endl;
		}

	}

	bool isIn(T vertex,T vertices[] , int length){
		for (int i = 0 ; i < length ; i++){
			if (vertex == vertices[i] )
				return true;
		}
		return false;
		
	}

	void depthFirstSearch(T initialVertex){
			 
		Stack<T> stack; // Stack<char> stack;
		
		int index = mappingIndex(initialVertex); 
		stack.push(vertices[index]); // pushing initial vertices
 
		T* visitedVertex = new T[verticesPointer++]; //verticesPointer indirectly represents the total vertices available in the graph
		int pointer=0;
		while(!stack.isEmpty()){
		   T vertex = stack.pop();
		   if (!isIn(vertex,visitedVertex,pointer)){
					visitedVertex[pointer++] = vertex;
					cout<<vertex<<"  ";
				
				index = mappingIndex(vertex);

			 for (int i = 0 ; i < size ; i++){
				if ((adjMatrix[index][i] > 0) && !isIn(vertices[i],visitedVertex,pointer))// searching edges of last visited nodes
							stack.push(vertices[i]);			  //checking if it is already visited or not 
	 					
			}
		    }
		}	
		
	}


	void breadthFirstSearch(T initialVertex){
			Queue<T> queue; // Stack<char> stack;
		
		int index = mappingIndex(initialVertex); 
		queue.enqueue(vertices[index]); // pushing initial vertices
 
		T* visitedVertex = new T[verticesPointer++]; //verticesPointer indirectly represents the total vertices available in the graph
		int pointer=0;
		while(!queue.isEmpty()){
		   T vertex = queue.dequeue();
		   if (!isIn(vertex,visitedVertex,pointer)){
					visitedVertex[pointer++] = vertex;
					cout<<vertex<<"  ";
				
				index = mappingIndex(vertex);

			 for (int i = 0 ; i < size ; i++){
				if ((adjMatrix[index][i] > 0) && !isIn(vertices[i],visitedVertex,pointer))// searching edges of last visited nodes
						queue.enqueue(vertices[i]);			  //checking if it is already visited or not 
	 					
			}
		    }
		}	

	}
	
	
//-----------------------------------------------------------------


};




int main(){
Graph<char> graph(3); //graph with 3 vertices

graph.addVertex('A');
graph.addVertex('B');
graph.addVertex('C');

graph.addEdge('A','A');
graph.addEdge('A','B');
graph.addEdge('A','C');
graph.addEdge('C','B');
graph.show();
cout<<"\n";
graph.depthFirstSearch('A'); //
cout<<"\n";
graph.breadthFirstSearch('A');
return 0;
}


//=%
