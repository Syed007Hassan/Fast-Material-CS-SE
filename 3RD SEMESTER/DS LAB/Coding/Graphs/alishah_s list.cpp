#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph {
  int numVertices;
  list<int> *adjLists;
  bool *visited;

   public:
  Graph(int V);
  void addEdge(int src, int dest);
  void DFS(int vertex);
  void BFS(int startVertex);
  void disp();
};

Graph::Graph(int vertices) {
  numVertices = vertices;
  adjLists = new list<int>[vertices];
  visited = new bool[vertices];
}

void Graph::addEdge(int src, int dest) {
  adjLists[src].push_front(dest);
  adjLists [dest].push_front(src);
}

void Graph::DFS(int vertex) {
  visited[vertex] = true;
  list<int> adjList = adjLists[vertex];

  cout << vertex << " ";

  list<int>::iterator i;
  for (i = adjList.begin(); i != adjList.end(); ++i)
    if (!visited[*i])
      DFS(*i);
}
void Graph::disp()
{
	for(int i=0;i<numVertices;i++)
	{
		list<int>::iterator k;
		cout<<i<<"->";
		for(k=adjLists[i].begin();k!=adjLists[i].end();k++)
		{
			cout<<*(k)<<" ";
		}
		cout<<endl;
	}
}
void Graph::BFS(int startVertex) {
  
  list<int> queue;
//  queue<int> queue;
  visited[startVertex] = true;
  queue.push_back(startVertex);

  list<int>::iterator i;

  while (!queue.empty()) {
    int currVertex = queue.front();
    cout<< currVertex << " ";
    queue.pop_front();

    for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i) {
      int adjVertex = *i;
      if (!visited[adjVertex]) {
        visited[adjVertex] = true;
        queue.push_back(adjVertex);
      }
    }
  }
}

int main() {
  Graph g(5);
  g.addEdge(0,1);
  g.addEdge(0, 2);
  g.addEdge(0,3);
  g.addEdge(1,4);
  g.addEdge(2,4);
  g.addEdge(3,4);
  
  cout<<"adjacency list\n";
  g.disp();
//  cout<<"depth frist search\n";
//  g.DFS(0);
  cout<<"\nbreadth frst search\n";
  g.BFS(0);
  return 0;
}
