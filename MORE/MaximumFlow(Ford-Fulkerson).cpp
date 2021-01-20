//MaximumFlow(Ford-Fulkerson)
//Task: given graph which represents flow network where every edge has capacity.
//also given two vertices source s and sink t in graph, find maximum possible flow from s to t with following constraints;
// - flow on edge doesn’t exceed given capacity of edge.
// - incoming flow is equal to outgoing flow for every vertex except s and t.
//Edmonds-Karp use BFS in Ford Fulkerson implementation as BFS always picks path with minimum number of edges.
//Reference: maximum flow, ford-fulkerson, edmonds-karp.
//Time Complexity: O(max_flow * E).

#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
using namespace std;

#define V 6 //number of vertices.

//Check residual graph if there is path from source s to sink t.
bool bfs(int RG[V][V], int s, int t, int P[]){
	bool visited[V];
	memset(visited, 0, sizeof(visited));

	queue <int> q;
	q.push(s);
	visited[s] = true;
	P[s] = -1;

	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v = 0; v < V; v++){
			if(visited[v] == false && RG[u][v] > 0){
				q.push(v);
				P[v] = u;
				visited[v] = true;
			}
		}
	}

	return (visited[t] == true);
}

//Maximum Flow Algorithm.
int fordFulkerson(int G[V][V], int s, int t){
	int u, v;

	int RG[V][V]; //residual graph capacity.
	for(u = 0; u < V; u++)
		for(v = 0; v < V; v++)
			RG[u][v] = G[u][v];

	int P[V]; //store path.
	int max_flow = 0;

	while(bfs(RG, s, t, P)){
		int path_flow = INT_MAX;
		for(v = t; v != s; v = P[v]){
			u = P[v];
			path_flow = min(path_flow, RG[u][v]);
		}

		for(v = t; v != s; v = P[v]){
			u = P[v];
			RG[u][v] -= path_flow;
			RG[v][u] += path_flow;
		}

		max_flow += path_flow;
	}

	return max_flow;
}

int main(){
	int G[V][V] = { 
		{0, 16, 13, 0, 0, 0},
		{0, 0, 10, 12, 0, 0},
		{0, 4, 0, 0, 14, 0},
		{0, 0, 9, 0, 0, 20},
		{0, 0, 0, 7, 0, 4},
		{0, 0, 0, 0, 0, 0}
	};

	cout << "Maximum possible flow is " << fordFulkerson(G, 0, 5) << endl;

	return 0;
}
