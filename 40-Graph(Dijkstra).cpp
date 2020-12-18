//40-Graph(Dijkstra)
//Greedy/Graph Shortest Path Algorithm

#include <iostream>
#include <limits.h>
#include <stdio.h>
using namespace std;

#define V 9

int minDistance(int dist[], bool sptSet[]){
	int min = INT_MAX, min_index;

	for(int v = 0; v < V; v++)
		if(sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

void printSolution(int dist[]){
	cout << "Vertex\tDistance from Source" << endl;
	for(int i = 0; i < V; i++)
		cout << i << "\t" << dist[i] << endl;
}

void dijkstra(int graph[V][V], int src){
	int dist[V];
	bool sptSet[V]; //true if vertex i is included in shortest path tree or shortest distance from src to i is finalized.

	for(int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	dist[src] = 0; //distance to self is zero.

	//find shortest path for all vertices.
	for(int count = 0; count < V - 1; count++){
		int u = minDistance(dist, sptSet);
		sptSet[u] = true;
		for(int v = 0; v < V; v++)
			if(!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

	//print the constructed distance array.
	printSolution(dist);
}

int main(){
	int graph[V][V] = { {0,  4,  0,  0,  0,  0,  0,  8,  0},
						{4,  0,  8,  0,  0,  0,  0, 11,  0},
						{0,  8,  0,  7,  0,  4,  0,  0,  2},
						{0,  0,  7,  0,  9, 14,  0,  0,  0},
						{0,  0,  0,  9,  0, 10,  0,  0,  0},
						{0,  0,  4, 14, 10,  0,  2,  0,  0},
						{0,  0,  0,  0,  0,  2,  0,  1,  6},
						{8, 11,  0,  0,  0,  0,  1,  0,  7},
						{0,  0,  2,  0,  0,  0,  6,  7,  0}};

	dijkstra(graph, 0);

	return 0;
}