//Graph(DepthFirstTraversal)
//Task: in graph, start from given node, visit and mark adjacent unmarked nodes recursively until there is no unmarked 
//adjacent nodes. backtrack and check for other unmarked nodes and traverse again for disconnected graphs.
//Time Complexity: O(V+E). V: number of vertices. E: number of edges.

#include <iostream>
#include <list>
using namespace std;

class Graph{
	int V; //number of vertices (nodes).
	list<int>* A; //adjacency list.
	void DFSUtil(int v, bool V[]);

public:
	Graph(int V);
	void addEdge(int v, int w);
	void DFS();
};

Graph::Graph(int V){
	this->V = V;
	A = new list<int>[V];
}

void Graph::addEdge(int v, int w){
	A[v].push_back(w); //A[v]: adjacent vertices of v.
}

void Graph::DFSUtil(int v, bool V[]){
	V[v] = true; //vertice visited.
	cout << v << " "; //print currently visited.
	
	list<int>::iterator i;
	for(i = A[v].begin(); i != A[v].end(); ++i)
		if(!V[*i]) DFSUtil(*i, V); //if not visited repeat process.
}

void Graph::DFS(){
	bool* v = new bool[V]; //stores vertices visited respectively.
	for(int i = 0; i < V; i++)
		v[i] = false; //mark all unvisited.

	for(int i = 0; i < V; i++)
		if(v[i] == false)
			DFSUtil(i, v);
}

int main(){
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);
	g.DFS();
	return 0;
}


