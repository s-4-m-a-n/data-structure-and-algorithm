//=%
#include <iostream>
#include <cstdlib>
#include <cstdbool>

using namespace std;

class Graph {
  private :
	    int** adjMatrix;
	    int* vertices; // stores the name of the vertices 
	    int size;
	    int verticesPointer; //stores the last index of vertices arrey


 public:
//----constructor creating 2d matrix dynamically ------------------------------------
	Graph(int n){  // since rows and colms of the matrix is equal . so size = row = colms
		size = n;
		adjMatrix = new int*[size];
		for (int i = 0 ; i < size ; i++)
			adjMatrix[i] = new int[size];
		
		setAdjMatrix();
		vertices = new int[size]; 
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

	int mappingIndex(int vertex){ //return the index value of respective vertices
		for (int i  = 0 ; i <= verticesPointer ; i++ ){
			if (vertices[i]  == vertex)
				return i;
		}	
		return NULL; // if vertex doesnot exist return null
	}


	void addVertex(int data){
		vertices[++verticesPointer]  = data;
	}
	
	void addEdge(int from , int to){
		int indexOfFrom = mappingIndex(from);
		int indexOfTo = mappingIndex(to);

		adjMatrix[indexOfFrom][indexOfTo]++;   // more than one edge is acceptable. 

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
	
//-----------------------------------------------------------------


};




int main(){
Graph graph(3); //graph with 3 vertex

graph.addVertex(1);
graph.addVertex(2);
graph.addVertex(3);
graph.addEdge(1,2);
graph.addEdge(3,2);
graph.show();

return 0;
}


//=%
