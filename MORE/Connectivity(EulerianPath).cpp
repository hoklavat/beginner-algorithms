//Connectivity(EulerianPath)
//eulerian path is path in graph that visits every edge exactly once. semi eulerian.
//eulerian circuit is eulerian path which starts and ends on same vertex. eulerian.
//is it possible to draw given graph without lifting pencil from paper and without tracing any of edges more than once.
//Reference: undirected graph, depth first search, connectivity.
//Time Complexity: O(V+E).

#include<iostream>
#include <list>
using namespace std;

class Graph{
	int V;
	list<int> *data;
	
public:
	Graph(int V){
		this->V = V; 
		data = new list<int>[V]; 
	}
	
	~Graph(){
		delete [] data; 
	}

	void addEdge(int v, int w){
		data[v].push_back(w);
		data[w].push_back(v);
	}
	
	//depth first search.
	void DFSUtil(int v, bool visited[]){
		visited[v] = true;
		list<int>::iterator i;		
		for(i = data[v].begin(); i != data[v].end(); ++i)
			if(!visited[*i]) DFSUtil(*i, visited);
	}
	
	//check if all non-zero degree vertices are connected using depth first search traversal.
	bool isConnected(){
		int i;
		
		bool visited[V];		
		for(i = 0; i < V; i++) 
			visited[i] = false;

		for(i = 0; i < V; i++)
			if(data[i].size() != 0) break;

		if(i == V) return true;

		DFSUtil(i, visited);

		for(i = 0; i < V; i++)
			if(visited[i] == false && data[i].size() > 0) return false;

		return true;
	}

	//check if this graph is eulerian or not.
	//0: not Eulerian
	//1: semi eulerian
	//2: eulerian
	int isEulerian(){
		if(isConnected() == false) return 0;

		//vertices with odd degree.
		int odd = 0;
		for(int i = 0; i < V; i++)
			if(data[i].size() & 1) odd++; //if last bit is 1, it is odd.

		//odd vertices are more than 2 graph is not eulerian.
		if(odd > 2) return 0;

		//if odd count is 2, then semi-eulerian.
		//if odd count is 0, then eulerian
		//odd count can never be 1 for undirected graph.
		return(odd)? 1 : 2;
	}
};

void test(Graph &g){
	int res = g.isEulerian();
	if(res == 0)
		cout << "graph is not eulerian." << endl;
	else if(res == 1)
		cout << "graph has euler path." << endl;
	else
		cout << "graph has euler cycle." << endl;
}

int main(){
	Graph g1(5);
	g1.addEdge(1, 0);
	g1.addEdge(0, 2);
	g1.addEdge(2, 1);
	g1.addEdge(0, 3);
	g1.addEdge(3, 4);
	test(g1);

	Graph g2(5);
	g2.addEdge(1, 0);
	g2.addEdge(0, 2);
	g2.addEdge(2, 1);
	g2.addEdge(0, 3);
	g2.addEdge(3, 4);
	g2.addEdge(4, 0);
	test(g2);

	Graph g3(5);
	g3.addEdge(1, 0);
	g3.addEdge(0, 2);
	g3.addEdge(2, 1);
	g3.addEdge(0, 3);
	g3.addEdge(3, 4);
	g3.addEdge(1, 3);
	test(g3);

	// all vertices form cycle.
	Graph g4(3);
	g4.addEdge(0, 1);
	g4.addEdge(1, 2);
	g4.addEdge(2, 0);
	test(g4);

	//all vertices with zero degree.
	Graph g5(3);
	test(g5);

	return 0;
}
