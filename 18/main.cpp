//18- Graph Algorithms (Breadth First Search)
#include "BreadthFirstSearch.h"
using namespace std;

int main(){
	BreadthFirstSearch breadthFirstSearch;
	shared_ptr<Vertex> vertex1 = make_shared<Vertex>("A");
	shared_ptr<Vertex> vertex2 = make_shared<Vertex>("B");
	shared_ptr<Vertex> vertex3 = make_shared<Vertex>("C");
	shared_ptr<Vertex> vertex4 = make_shared<Vertex>("D");
	shared_ptr<Vertex> vertex5 = make_shared<Vertex>("E");
	shared_ptr<Vertex> vertex6 = make_shared<Vertex>("F");
	shared_ptr<Vertex> vertex7 = make_shared<Vertex>("G");
	shared_ptr<Vertex> vertex8 = make_shared<Vertex>("H");
	vertex1->addNeighbour(vertex2.get());
	vertex1->addNeighbour(vertex6.get());
	vertex1->addNeighbour(vertex7.get());
	vertex7->addNeighbour(vertex8.get());
	vertex2->addNeighbour(vertex3.get());
	vertex2->addNeighbour(vertex4.get());
	vertex4->addNeighbour(vertex5.get());
	breadthFirstSearch(vertex1);
	return 0;
}
