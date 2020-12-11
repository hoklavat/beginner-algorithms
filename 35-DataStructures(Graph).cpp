//34-DataStructures(Graph)

#include<iostream>
#include <list>
using namespace std;

#include "Headers/Graph.cpp"

int main(){
	Graph g(4); //total 4 nodes.
	g.addEdge(0, 1); //edge from node 0 to node 1.
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Breadth First Traversal: ";
	g.BFS(2);
	cout << endl;
	
	cout << "Depth First Traversal: ";
	g.DFS(2);
	cout << endl;

	return 0;
}