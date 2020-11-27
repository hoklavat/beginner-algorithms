//19- Graph Algorithms (Depth First Search)
#include <iostream>
#include <memory>
#include "Vertex.h"
#include "DepthFirstSearch.h"
using namespace std;

int main(){
	vector <shared_ptr<Vertex>> graph;
	graph.resize(8);
	graph[0] = make_shared<Vertex>("A");
	graph[1] = make_shared<Vertex>("B");
	graph[2] = make_shared<Vertex>("C");
	graph[3] = make_shared<Vertex>("D");
	graph[4] = make_shared<Vertex>("E");
	graph[5] = make_shared<Vertex>("F");
	graph[6] = make_shared<Vertex>("G");
	graph[7] = make_shared<Vertex>("H");	
	graph[0]->addNeighbour(graph[1].get());
	graph[0]->addNeighbour(graph[4].get());
	graph[0]->addNeighbour(graph[5].get());
	graph[6]->addNeighbour(graph[7].get());
	graph[1]->addNeighbour(graph[2].get());
	graph[1]->addNeighbour(graph[3].get());
	graph[3]->addNeighbour(graph[4].get());	
	DepthFirstSearch depthFirstSearch(graph);
	depthFirstSearch();	
	return 0;
}
