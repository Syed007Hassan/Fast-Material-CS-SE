#include <iostream>
#include <list>

using namespace std;

class UndirectedAdjancencyList{
private:
	int numVertices;
	list<int> *adjLists;
	bool *visited;
public:
	UndirectedAdjancencyList(int vertices){
		numVertices = vertices;
  		adjLists = new list<int>[vertices];
  		visited = new bool[vertices];
	}
	
	void addEdge(int src, int dest) {
	  	adjLists[src].push_front(dest);
		adjLists[dest].push_front(src);
	}
	
	void DFS(int vertex) {
		visited[vertex] = true;
		list<int> adjList = adjLists[vertex];
		
		cout << vertex << " ";
		
		list<int>::iterator i;
		for (i = adjList.begin(); i != adjList.end(); ++i){
			if (!visited[*i])
		  		DFS(*i);
		}
	}
	
	void BFS(int source){
		list<int> queue;
		visited[source] = true;
		queue.push_back(source);
		
		list<int>:: iterator i;
		
		while(!queue.empty()){
			int u = queue.front();
			cout << u << " ";
			queue.pop_front();
			
			for(i= adjLists[u].begin(); i!=adjLists[u].end(); i++){
				int adjVertex = *i;
				if(!visited[adjVertex]){
					visited[adjVertex]= true;
					queue.push_back(adjVertex);
				}
			}
		}
	}
	
	void ClearVisited(){
		for(int i=0; i< numVertices; i++)
			visited[i]= false;
	}
	
	void disp(){
		for(int i=0;i<numVertices;i++){
			list<int>::iterator k;
			cout<<i<<"-> ";
			for(k=adjLists[i].begin();k!=adjLists[i].end();k++)
				cout<<*(k)<<" ";
			cout<<endl;
		}
	}
};

int main(){
	UndirectedAdjancencyList g(5);
	
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(0,3);
	g.addEdge(1,4);
	g.addEdge(2,4);
	g.addEdge(3,4);
	
	cout << "UNDIRECTED ADJACENCY LIST\n\n";
	g.disp();
	cout << "Depth First Search : ";
	g.DFS(0);
	g.ClearVisited();
	
	cout << "\nBreath First Search: ";
	g.BFS(0);
	
	return 0;
}
