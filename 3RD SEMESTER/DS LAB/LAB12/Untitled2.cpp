#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;


class Graphs{
	
	int *visited;
	vector <int> *graph;
	int ver;
	
	public:
		
		Graphs(int v){
			
			ver = v;
			
			visited = new int[ver];
			for(int i = 0;i< ver ;i++){
				visited[i] = 0;
			}
			
			graph = new vector <int> [ver];
			
		}
		
		
		int add_edge(int u, int v){
			
			if(u < 0 || u >= ver || v< 0 || v >= ver){
				cout<<"Invalid edge>> "<<endl;
				return -1;
			}
			
			graph[u].push_back(v);  
//			graph[v].push_back(u);
			
		}
		
		
		int remove(int u,int v){
			
			graph[u].pop_back();
			graph[v].pop_back();
		
		}
		
		
		void BFS(int source){
		cout<<"BFS "<<endl;	
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
	
		

			
			
//			int DFS(int source){		  
//		     visited[source] = 1;
//			 
//			 vector <int> val = graph[source];	
//			 cout<<source<<" ";
//			 
//			 vector <int> :: iterator k;
//			 
//			 for( k = val.begin(); k!=val.end(); ++k){
//			 	
//			 	 if(visited[*k] == 0){
//			 	 	DFS(*k);
//				  }
//			 }
//		
//		}
			void DFS(int source) {
				visited[source]= true;
				vector<int> val = graph[source];
				
				cout << source << " ";
				
				vector<int>:: iterator i;
				
				for(i=val.begin();i!=val.end();++i) {
					if(visited[*i]==false) {
						DFS(*i);
					}
				}
			
		}
		
	    void display(){
	    	
	    	cout<<"DISPLAY GARPH "<<endl;
	    	
	    	for(int i = 0;i< ver ; i++){
	    		
	    		vector <int>:: iterator k;
				
				cout<<i<<"->";
				
				for(k = graph[i].begin(); k!=graph[i].end() ; k++){
					cout<<*k<<" "; 
				} 
				
				cout<<endl;	
			}
	   }
		
		void clear(){
			
			for(int i = 0; i < ver ; i++){
				visited[i] = 0;
			}
		}

};

int main(){
	
	
	
	Graphs gg(5);
	
	gg.add_edge(0,1);
	gg.add_edge(0,2);
	gg.add_edge(0,3);
	gg.add_edge(1,4);
	gg.add_edge(2,4);
	gg.add_edge(3,4);
	
	
	gg.display();
    cout<<endl;
		
	gg.BFS(0);
	
	gg.clear();
	
	cout<<endl<<"DFS "<<endl;
	gg.DFS(2);
}
