#include <iostream>
#include <queue>
#include <stack>

using namespace std;

template <class T>
class Node{
public:
	T data;
	int weight;
	Node<T> *next;
	
	Node(T data = 0, int weight= 0){
		this->data = data;
		this->weight = weight;
		this->next = NULL;
	}
};

template <class T>
class List{
private:
	Node<T> *head;
	Node<T> *tail;
public:
	List(){
		head = tail = NULL;
	}
	
	Node<T>* GetHead(){
		return this->head;
	}
	void push(T data, int weight){
		Node<T> *temp = new Node<T>(data,weight);
		
		if(!head){
			head = tail = temp;
		}
		else{
			tail->next = temp;
			tail = temp;
		}
	}
	
	void Display(){
		Node<T> *temp = head;
		
		while(temp){
			cout << temp->data << "(" << temp->weight << ") ";
			temp = temp->next;
		}
		cout << endl;
	}
};

class WeightedAdjancencyList{
private:
	int vertices;
	List<int> *adj;
	bool* visited;
public:
	WeightedAdjancencyList(int vertices){
		this->vertices = vertices;
		this->adj = new List<int>[this->vertices];
		this->visited = new bool[this->vertices];
		
		ClearVisited();
	}
	
	void ClearVisited(){
		for(int i=0; i<this->vertices; i++)
			visited[i] = false;
	}
	
	void AddEdge(int source, int destination, int weight){
		adj[source].push(destination, weight);
	}
	
	void BFS(int source){
		queue<int> q;
		q.push(source);
		visited[source] = true;
		
		while(!q.empty()){
			int temp = q.front();
			cout << temp << " ";
			q.pop();
			
			Node<int> *tempNode = adj[temp].GetHead();
			while(tempNode){
				if(!visited[tempNode->data]){
					q.push(tempNode->data);
					visited[tempNode->data] = true;
				}
				tempNode = tempNode->next;
			}
		}
	}
	
	void DFS(int source){
		stack<int> s;
		s.push(source);
		visited[source] = true;
		
		while(!s.empty()){
			int temp = s.top();
			s.pop();
			
			cout << temp << " ";
			
			Node<int>* tempNode = adj[temp].GetHead();
			while(tempNode){
				if(!visited[tempNode->data]){
					s.push(tempNode->data);
					visited[tempNode->data] = true;
				}
				tempNode = tempNode->next;
			}
		}
	}
	
	void showAdjacencyList(){
        for (int i = 0; i < this->vertices; ++i)
        {
            cout << i << " => ";
            this->adj[i].Display();
        }
    }
};

int main(){
	WeightedAdjancencyList g(5);
	
	g.AddEdge(0,1,5);
	g.AddEdge(0,2,7);
	g.AddEdge(0,3,4);
	g.AddEdge(1,4,3);
	g.AddEdge(2,4,9);
	g.AddEdge(3,4,6);
	
	
	cout << "WEIGHTED ADJACENCY LIST\n";
	g.showAdjacencyList();
	
	cout << "\nDepth First Search : ";
	g.DFS(0);
	g.ClearVisited();
	
	cout << "\nBreath First Search: ";
	g.BFS(0);
	return 0;
}

