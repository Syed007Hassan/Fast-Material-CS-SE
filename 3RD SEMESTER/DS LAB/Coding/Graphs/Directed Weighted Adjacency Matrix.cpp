#include <iostream>
#include <stack>
#include <queue>
//#include <vector>
using namespace std;

#define I 0

class Graphs{
private:
	int** adjMatrix;
	int vertices;
	bool *visited;
public:
	Graphs(int NumVertices){
		this->vertices = NumVertices;
		adjMatrix = new int*[vertices];
		
		visited = new bool[vertices];
		for(int i=0; i<vertices; i++)
			visited[i]=false;
		
		for(int i=0; i<vertices; i++)
			adjMatrix[i] = new int[vertices];
		
		for(int i=0; i<vertices; i++){
			for(int j=0; j<vertices; j++)
				adjMatrix[i][j] = I;
		}
	}
	
	void AddEdge(int i, int j, int w){
		if(i < 0 || i >= vertices){
			if(j<0 || j>= vertices){
				cout << "Vertic doesn't exists.\n";
				return;
			}
		}
		adjMatrix[i][j] = w;
	}
	
	void RemoveAnEdge(int i, int j){
		adjMatrix[i][j] = I;
	}
	
	void Display(){
		for(int i=0; i<vertices; i++){
			for(int j=0; j<vertices; j++)
				cout << adjMatrix[i][j] << " ";
			cout << endl;
		}
		cout << endl;
	}
	
	void AddVertex(){
		int newVertices = vertices+1;
		
		// update the visited array
		bool *NewVisited = new bool[newVertices];
		for(int i=0; i<newVertices; i++)
			NewVisited[i]=false;
		for(int i=0; i<vertices; i++)
			NewVisited[i]=visited[i];
		
		// delete existing vertices array
		delete[] visited;
		visited = NewVisited;
		
		
		// update the adjacency matrix
		int **newAdjMatrix = new int*[newVertices];
		for(int i=0; i<newVertices; i++)
			newAdjMatrix[i] = new int[newVertices];
		
		
		for(int i=0; i<newVertices; i++){
			for(int j=0; j<newVertices; j++)
				newAdjMatrix[i][j] = I;
		}
		
		for(int i=0; i<vertices; i++){
			for(int j=0; j<vertices; j++)
				newAdjMatrix[i][j] = adjMatrix[i][j];
		}
		
		// delete existing matrix
		for(int i= vertices-1; i>=0; i--)
			delete[] adjMatrix[i];
		delete[] adjMatrix;
		
		// assigning newmatrix to old matrix
		adjMatrix = newAdjMatrix;
		vertices= newVertices;
		
	}

	void DFS(int source){
		if(!visited[source]){
			cout << source << " ";
			visited[source] = true;
			for(int i=1; i<vertices; i++){
				if(adjMatrix[source][i] && !visited[i])
					DFS(i);
			}
		}
	}
	
	void Clear(){
		for(int i=0; i<vertices; i++){
			visited[i] = false;
		}
	}
	void BFS(int source){
		queue<int> q;
		
		visited[source]=true;
		cout << source << " ";
		q.push(source);
		
		while(!q.empty()){
			int u = q.front();
			q.pop();
			
			for(int i=0; i<vertices; i++){
				if(adjMatrix[u][i] && !visited[i]){
					cout << i << " ";
					visited[i]= true;
					q.push(i);
				}
			}
		}
	}
	
	~Graphs(){
		for(int i= vertices-1; i>=0; i--)
			delete[] adjMatrix[i];
		delete[] adjMatrix;
	}
};


int main(){
	Graphs gg(5);
	gg.AddEdge(0,1,5);
	gg.AddEdge(0,2,7);
	gg.AddEdge(0,3,8);
	gg.AddEdge(1,4,3);
    gg.AddEdge(2,4,6);
    gg.AddEdge(3,4,9);
    
	cout << "WEIGHTED ADJACENCY MATRIX\n";
	gg.Display();
	
	cout << "\nDepth First Search : ";	
	gg.DFS(0);
	gg.Clear();
	
	cout << "\nBreath First Search: ";
	gg.BFS(0);
	
	
	return 0;
}
