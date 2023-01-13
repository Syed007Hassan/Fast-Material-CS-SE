#include<iostream>
#include<queue>
using namespace std;

class Graph{
	
	public:
		
		int **arr;
		int v;
		int *visited;
		
	
	Graph(int n){
		v = n;
		arr = new int *[v];
		
		visited = new int[v];
		for(int i = 0 ;i < v; i++){
			visited[i] = 0;
		}
		
		for(int i = 0 ;i < v; i++){
			arr[i] = new int[v];
			
			for(int j = 0;j< v;j++){
				arr[i][j] = 0;
			}
		}
		
		
		
	}
	
	void insertedgeUndirected(int x, int y){
		
		if(x >= v || x < 0  || y >=v || y < 0 ){
					cout<<"Wrong edge inserted "<<endl;
					return ;
				}
		
		
			for(int i = 0 ;i < v; i++){
			for(int j = 0;j< v;j++){
				if(x == i && y == j){
					arr[i][j] = 1;
					arr[j][i] = 1;
				}
			}
		}
		
	}
	
   	void insertedgeDirected(int x, int y){
		
		if(x >= v || x < 0  || y >=v || y < 0 ){
					cout<<"Wrong edge inserted "<<endl;
					return;
				}
				
		
			for(int i = 0 ;i < v; i++){
			for(int j = 0;j< v;j++){
				
				
				if(x == i && y == j){
					arr[i][j] = 1;
				}
			}
		}
		
	}
	
	void DFS(int source){
	//	cout<<"DFS "<<endl;
		if(!visited[source]){
			cout << source << " ";
			visited[source] = true;
			for(int i=1; i<v; i++){
				if(arr[source][i] && !visited[i])
					DFS(i);
			}
		}
	}
	
    void BFS(int source){
    	cout<<"BFS"<<endl;
    	queue<int> q;
    
		q.push(source);
		visited[source] = 1;
		
		while(!q.empty()){
			int x = q.front();
		    q.pop();
		    cout<<x<<" ";
		    
		    for(int i =0;i<v;i++){
		    	if(arr[x][i] && !visited[i]){

		    		visited[i] = 1;
		    		q.push(i);
				}
			}
		}	
	}
	
	void clear(){
		for(int i=0; i<v; i++){
			visited[i] = 0;
		}
	}
	
	
	void print(){
		
		for(int i = 0 ;i < v; i++){
			for(int j = 0;j< v;j++){
				cout<<arr[i][j]<<" ";
			}
			cout<<endl;
		}
		
		cout<<endl<<endl;
	}
	
	
	
	

};

int main(){
	
	
	Graph v1(5);
	
	v1.insertedgeDirected(5,3);
	
	v1.insertedgeDirected(0,1);
	v1.insertedgeDirected(0,2);
	v1.insertedgeDirected(0,3);
	v1.insertedgeDirected(1,4);
	v1.insertedgeDirected(2,4);
	v1.insertedgeDirected(3,1);
	v1.insertedgeDirected(4,2);
	v1.insertedgeDirected(4,3);
	
	v1.print();
	

	
	v1.BFS(0);
	
	v1.clear();

    cout<<endl<<"DFS"<<endl;
	v1.DFS(0);
	
	
	
}
