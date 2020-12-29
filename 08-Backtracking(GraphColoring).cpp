//08-Backtracking(GraphColoring)
//coloring vertices of graph such that no adjacent vertices share same color.

#include <iostream>
using namespace std;

#define V 4 //number of vertices.

void print(int C[]){
	cout << "Solution Exists:" << endl;
	for(int i = 0; i < V; i++) cout << C[i] << " ";
	cout << endl;
}

bool isSafe(bool G[V][V], int C[], int v, int c){
	for(int i = 0; i < V; i++)
		if(G[v][i] && c == C[i]) return false; //adjacent vertice has same color.
	return true;
}

bool coloring(bool G[V][V], int C[], int v, int m){
	if(v == V) return true;
	for(int c = 1; c <= m; c++){
		if(isSafe(G, C, v, c)){
			C[v] = c;
			if(coloring(G, C, v+1, m)) return true;
			C[v] = 0;
		}
	}	
	return false;
}

int main(){
	bool G[V][V] ={
		{0, 1, 1, 1},
		{1, 0, 1, 0},
		{1, 1, 0, 1},
		{1, 0, 1, 0},
	}; //graph with 4 vertices. if vertices are connected corresponding element is 1.
	int C[V]; //colors of vertices.
	int m = 3; //number of colors.	
	
	for(int i = 0; i < V; i++) C[i] = 0;

	if(coloring(G, C, 0, m) == false) cout << "Solution does not exist" << endl;
	else print(C);

	return 0;
}