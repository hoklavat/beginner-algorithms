//43-Graph(UnionFind)
//used to detect cycle in graph.

#include <iostream>
using namespace std;

struct Edge{
	int source;
	int destination;
};

struct Graph{
	int V;
	int E;
	Edge* edge;
};

Graph* createGraph(int V, int E){
	Graph* G = new Graph();
	G->V = V;
	G->E = E;
	G->edge = new Edge[sizeof(Edge) * G->E];
	return G;
}

int find(int P[], int i){
	if (P[i] == -1)
		return i;
	return find(P, P[i]);
}

void Union(int P[], int x, int y){
	P[x] = y;
}

int isCycle(Graph* G){
	int *P = new int[sizeof(int) * G->V];
	
	for(int i = 0; i < G->V; i++)
		*(P+i) = -1;

	for (int i = 0; i < G->E; i++){
		int x = find(P, G->edge[i].source);
		int y = find(P, G->edge[i].destination);
		if (x == y) return 1;
		Union(P, x, y);
	}
	
	return 0;
}

int main(){
	int V = 3, E = 3;
	Graph* graph = createGraph(V, E);

	graph->edge[0].source = 0;
	graph->edge[0].destination = 1;
	graph->edge[1].source = 1;
	graph->edge[1].destination = 2;
	graph->edge[2].source = 0;
	graph->edge[2].destination = 2;

	if (isCycle(graph))
		cout << "Graph contains cycle." << endl;
	else
		cout << "Graph doesn't contain cycle." << endl;

	return 0;
}