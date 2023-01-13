#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

// directed adjacencylist
class AdjacencyList{
private:
	int vertices;
	bool* visited;
	vector<int> *graph;
public:
	AdjacencyList(int vertices){
		this->vertices = vertices;
		
		visited = new bool[this->vertices];
		for(int i=0; i<vertices; i++)
			visited[i] = false;
		
		graph = new vector<int>[this->vertices];
	}
	
	void Add_Edge(int u, int v){
		if(u<0 || u>=vertices){
			cout << "Invalid entry";
			return;
		}
		graph[u].push_back(v);
//		graph[v].push_back(u);
	}
	
	void DFS(int source){
		stack<int> st;
		
		st.push(source);
		visited[source]= true;
		
		while(!st.empty()){
			int u = st.top();
			st.pop();
			
			cout << u << " ";
			
			for(int i=0 ; i<graph[u].size(); i++){
				if(!visited[graph[u][i]]){
					st.push(graph[u][i]);
					visited[graph[u][i]]= true;
				}
			}
		}
		
		for(int i=0; i<vertices; i++)
			visited[i]= false;
	}
	
	void BFS(int source){
		queue<int> q;
	
		q.push(source);
		visited[source]= true;
		
		while(!q.empty()){
			int u = q.front();
			q.pop();
			
			cout << u << " ";
			
			for(int i=0 ; i<graph[u].size(); i++){
				if(!visited[graph[u][i]]){
					q.push(graph[u][i]);
					visited[graph[u][i]]= true;
				}
			}
		}
	}
};

int main(){
	AdjacencyList matrix(5);
	matrix.Add_Edge(0,1);
	matrix.Add_Edge(0,2);
    matrix.Add_Edge(0,3);
    matrix.Add_Edge(1,4);
    matrix.Add_Edge(2,4);
    matrix.Add_Edge(3,4);
    
    cout << "DFS : ";
    matrix.DFS(0);
    cout << "\nBFS : ";
    matrix.BFS(2);
	return 0;
}
