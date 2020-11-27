#include "Vertex.h"

Vertex::Vertex(const string &_name): name(_name){}
Vertex::~Vertex() = default;

const string &Vertex::getName() const{
	return name;
}

void Vertex::setName(const string &name){
	this->name = name;
}

bool Vertex::isVisited() const{
	return visited;
}

void Vertex::setVisited(bool visited){
	this->visited = visited;
}

const vector<Vertex *> &Vertex::getNeighbourList() const{
	return neighbours;
}

void Vertex::addNeighbour(Vertex *neighbour){
	neighbours.push_back(neighbour);
}

ostream &operator<<(ostream& strm, const Vertex &vertex){
	strm << vertex.name;
	return strm;
}