#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

class Graph{
	
     int *visited;
     int ver;
     vector <int> *graph;
	
	public:
		Graph(int x){
			ver = x;
			
			visited = new int[ver];
			for(int i = 0;i<ver;i++){
				visited[i] = 0;
			}
			
			graph = new vector<int> [ver];
		}
		
		
		addEdge(int u,int v){
			
			if(u < 0 || u >= ver || v<0 || v >= ver){
				cout<<"Invalid Vertice "<<endl;
				
			}
			
			graph[u].push_back(v);	
			
		}
		
		
		// DEPTH FIRST SEARCH
		
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
		
	
	}
		
	
       // BREADTH FIRST SEARCH
    
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
		
		
	  void display(){
	  	cout<<"DISPLAY graph"<<endl;
	  	
	  	for(int i =0 ;i<ver ;i++){
	  		vector <int>:: iterator k;
	  		cout<<i<<"->";
	  		for(k=graph[i].begin(); k !=graph[i].end(); k++){
	  			cout<<*k<<" ";
			  }
			  cout<<endl;
		  }
	  	
	  }
	  
	  
	  void clear(){
	  	
	  	for(int i=0;i<ver;i++){
	  		visited[i] = 0;
		  }
	  	
	  }
	  
	  
	  	
		
};

int main(){
	
	Graph g(4);
	
	g.addEdge(0,2);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(0,3);
	g.addEdge(1,3);
	g.addEdge(2,2);
	
	cout<<"DFS "<<endl;
	g.DFS(0);
	g.clear();
	cout<<endl;
	
	g.display();
	cout<<endl;
	
	cout<<"BFS "<<endl;

	
	g.BFS(0);


}
