//42-GraphAlgorithms(FloydWarshall)
//Dynamic/Graph Shortest Path Algorithm

#include <iostream>
#include <climits>
using namespace std;

#define V 4
#define INF 99999

void printSolution(int D[][V])
{
	cout << "Shortest Distances Matrix" << endl;
	for (int i = 0; i < V; i++){
		for (int j = 0; j < V; j++){
			if (D[i][j] == INF) cout << "*" << "\t";
			else cout << D[i][j] << "\t";
		}
		cout << endl;
	}
}

void FloydWarshall (int G[][V]){
	int D[V][V]; //shortest distances between every pair of vertices.

	for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++)
			D[i][j] = G[i][j];

	for (int k = 0; k < V; k++){
		for (int i = 0; i < V; i++){
			for (int j = 0; j < V; j++){
				if (D[i][k] + D[k][j] < D[i][j]) D[i][j] = D[i][k] + D[k][j];
			}
		}
	}

	printSolution(D);
}

int main(){
	int graph[V][V] = { 
					{0, 5, INF, 10},
					{INF, 0, 3, INF},
					{INF, INF, 0, 1},
					{INF, INF, INF, 0}
					};

	FloydWarshall(graph);
	
	return 0;
}