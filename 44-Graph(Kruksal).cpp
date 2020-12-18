//44-Graph(Kruksal)
//Greedy/Graph Minimum Spanning Tree Finder.

#include <iostream>
using namespace std;

struct Edge{
	int source;
	int destination; 
	int weight;
};

struct Graph{
	int V;
	int E;
	Edge* edge;
};

Graph* createGraph(int V, int E){
	Graph* G = new Graph;
	G->V = V;
	G->E = E;
	G->edge = new Edge[E];
	return G;
}

struct Subset{
	int parent;
	int rank;
};

int find(Subset S[], int i){
	if(S[i].parent != i)
		S[i].parent = find(S, S[i].parent);
	return S[i].parent;
}

void Union(Subset S[], int x, int y){
	int xroot = find(S, x);
	int yroot = find(S, y);

	if(S[xroot].rank < S[yroot].rank)
		S[xroot].parent = yroot;
		
	else if(S[xroot].rank > S[yroot].rank)
		S[yroot].parent = xroot;
		
	else {
		S[yroot].parent = xroot;
		S[xroot].rank++;
	}
}

int edgeCompare(const void* a, const void* b){
	Edge* a1 =(Edge*)a;
	Edge* b1 =(Edge*)b;
	return a1->weight > b1->weight;
}

void KruskalMST(Graph* G){
	int V = G->V;
	Edge result[V]; //minimum spanning tree.
	int e = 0; //result.
	int i = 0; //sorted edges.

	qsort(G->edge, G->E, sizeof(G->edge[0]), edgeCompare);

	Subset* S = new Subset[sizeof(Subset) * V];

	for(int v = 0; v < V; v++) {
		S[v].parent = v;
		S[v].rank = 0;
	}

	while(e < V-1 && i < G->E){
		Edge next_edge = G->edge[i++];
		int x = find(S, next_edge.source);
		int y = find(S, next_edge.destination);
		if(x != y){
			result[e++] = next_edge;
			Union(S, x, y);
		}
	}

	cout << "Minimum Spanning Tree in Graph" << endl;
	int minimumCost = 0;
	for(i = 0; i < e; ++i){
		cout << result[i].source << " -- " << result[i].destination << " == " << result[i].weight << endl;
		minimumCost = minimumCost + result[i].weight;
	}
	cout << "Minimum Cost Spanning Tree: " << minimumCost << endl;
}

int main(){
	int V = 4;
	int E = 5;
	Graph* graph = createGraph(V, E);

	graph->edge[0].source = 0;
	graph->edge[0].destination = 1;
	graph->edge[0].weight = 10;
	graph->edge[1].source = 0;
	graph->edge[1].destination = 2;
	graph->edge[1].weight = 6;
	graph->edge[2].source = 0;
	graph->edge[2].destination = 3;
	graph->edge[2].weight = 5;
	graph->edge[3].source = 1;
	graph->edge[3].destination = 3;
	graph->edge[3].weight = 15;
	graph->edge[4].source = 2;
	graph->edge[4].destination = 3;
	graph->edge[4].weight = 4;

	KruskalMST(graph);

	return 0;
}