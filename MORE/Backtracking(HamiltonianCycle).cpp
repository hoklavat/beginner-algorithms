//Backtracking(HamiltonianCycle)
//Task: determine whether given graph contains hamiltonian cycle or not.
//hamiltonian path in undirected graph is path that visits each vertex exactly once.
//hamiltonian cycle is hamiltonian path such that there is edge from last vertex to first vertex.
//Reference: backtracking, hamiltonian path/cycle.

#include <iostream>
using namespace std;

#define V 5 //number of vertices.

void print(int P[]){
	cout << "Solution Exists: ";
	for(int i = 0; i < V; i++)
		cout << P[i] << " ";
	cout << P[0] << " ";
	cout << endl;
}

bool isSafe(int v, bool G[V][V], int P[], int pos){
	if(G[P[pos-1]][v] == 0) return false;

	for(int i = 0; i < pos; i++)
		if(P[i] == v) return false; //already included.

	return true;
}

bool util(bool G[V][V], int P[], int pos){
	if(pos == V){
		if(G[P[pos-1]][P[0]] == 1) return true; //end is connected to start.
		else return false;
	}

	for(int v = 1; v < V; v++){
		if(isSafe(v, G, P, pos)){
			P[pos] = v;
			if(util(G, P, pos + 1) == true) return true;
			P[pos] = -1;
		}
	}
	
	return false;
}

bool solve(bool G[V][V]){
	int *P = new int[V];
	for(int i = 0; i < V; i++)
		P[i] = -1;

	P[0] = 0;
	if(util(G, P, 1) == false){
		cout << "Solution does not exist." << endl;
		return false;
	}

	print(P);
	
	return true;
}

int main(){
	bool G1[V][V] = {
		{0, 1, 0, 1, 0},
		{1, 0, 1, 1, 1},
		{0, 1, 0, 0, 1},
		{1, 1, 0, 0, 1},
		{0, 1, 1, 1, 0}};

	solve(G1);
	
	bool G2[V][V] = {
		{0, 1, 0, 1, 0},
		{1, 0, 1, 1, 1},
		{0, 1, 0, 0, 1},
		{1, 1, 0, 0, 0},
		{0, 1, 1, 0, 0}};

	solve(G2);

	return 0;
}