//41-GraphAlgorithms(BellmanFord)
//Dynamic/Graph Shortest Path Algorithm

#include <iostream>
#include <climits>
using namespace std;

//weighted edge structure.
struct Edge{
	int source; 
	int destination; 
	int weight;
};

struct Graph{
	int V; //number of vertices. 
	int E; //number of edges.
	struct Edge* edge; //graph.
};

struct Graph* createGraph(int V, int E){
	struct Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;
	graph->edge = new Edge[E];
	return graph;
};

void printSolution(int D[], int V)
{
	cout << "Vertex\tDistance from Source" << endl;
	for(int i = 0; i < V; ++i)
		cout << i << "\t" << D[i] << endl;
}

void BellmanFord(struct Graph* G, int s){
	int V = G->V;
	int E = G->E;
	int D[V]; //distances.

	for(int i = 0; i < V; i++)
		D[i] = INT_MAX;
	D[s] = 0;

	for(int i = 1; i <= V - 1; i++){
		for(int j = 0; j < E; j++){
			int u = G->edge[j].source;
			int v = G->edge[j].destination;
			int w = G->edge[j].weight;
			if(D[u] != INT_MAX && D[u] + w < D[v]) D[v] = D[u] + w;
		}
	}
	
	//check negative weights.
	for(int i = 0; i < E; i++){
		int u = G->edge[i].source;
		int v = G->edge[i].destination;
		int w = G->edge[i].weight;
		if(D[u] != INT_MAX && D[u] + w < D[v]){
			cout << "Graph contains negative weight cycle." << endl;
			return;
		}
	}

	printSolution(D, V);

	return;
}

int main(){
	int V = 5;
	int E = 8;
	struct Graph* graph = createGraph(V, E);

	graph->edge[0].source = 0;
	graph->edge[0].destination = 1;
	graph->edge[0].weight = -1;

	graph->edge[1].source = 0;
	graph->edge[1].destination = 2;
	graph->edge[1].weight = 4;

	graph->edge[2].source = 1;
	graph->edge[2].destination = 2;
	graph->edge[2].weight = 3;

	graph->edge[3].source = 1;
	graph->edge[3].destination = 3;
	graph->edge[3].weight = 2;

	graph->edge[4].source = 1;
	graph->edge[4].destination = 4;
	graph->edge[4].weight = 2;

	graph->edge[5].source = 3;
	graph->edge[5].destination = 2;
	graph->edge[5].weight = 5;

	graph->edge[6].source = 3;
	graph->edge[6].destination = 1;
	graph->edge[6].weight = 1;

	graph->edge[7].source = 4;
	graph->edge[7].destination = 3;
	graph->edge[7].weight = -3;

	BellmanFord(graph, 0);

	return 0;
}