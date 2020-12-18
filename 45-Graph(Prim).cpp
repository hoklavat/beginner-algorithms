//45-Graph(Prim)
//Greedy/Graph Minimum Spanning Tree Finder.

#include <iostream>
#include <climits>
using namespace std;

#define V 5

//vertice with minimum key.
int minKey(int k[], bool MST[]){
	int min = INT_MAX;
	int i;

	for(int v = 0; v < V; v++)
		if(MST[v] == false && k[v] < min){
			min = k[v];
			i = v;
		}
	return i;
}

void printMST(int P[], int G[V][V]){
	cout<<"Edge\tWeight" << endl;
	for(int i = 1; i < V; i++)
		cout << P[i] << " - " << i << "\t" << G[i][P[i]] << endl;
}

void primMST(int G[V][V]){
	int P[V]; //parent.
	int K[V]; //key.
	bool MST[V];

	for(int i = 0; i < V; i++){
		K[i] = INT_MAX;
		MST[i] = false;
	}

	K[0] = 0;
	P[0] = -1;

	for(int c = 0; c < V-1; c++){
		int u = minKey(K, MST);
		MST[u] = true;

		for(int v = 0; v < V; v++)
			if(G[u][v] && MST[v] == false && G[u][v] < K[v]){
				P[v] = u;
				K[v] = G[u][v];
			}
				
	}

	printMST(P, G);
}

int main(){
	int graph[V][V] = { 
	{ 0, 2, 0, 6, 0 },						
	{ 2, 0, 3, 8, 5 },
	{ 0, 3, 0, 0, 7 },
	{ 6, 8, 0, 0, 9 },
	{ 0, 5, 7, 9, 0 } };
	
	primMST(graph);

	return 0;
}