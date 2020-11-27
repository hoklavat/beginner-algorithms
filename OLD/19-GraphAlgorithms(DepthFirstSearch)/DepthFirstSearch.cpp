#include "DepthFirstSearch.h"

DepthFirstSearch::DepthFirstSearch(vector<shared_ptr<Vertex>> const &_vertexList): vertexList(_vertexList){}

void DepthFirstSearch::operator()(){
	for(auto vertex: vertexList){
		if(!vertex->isVisited())
			dfs(vertex.get());
	}
	cout << '\n';
}

void DepthFirstSearch::dfs(Vertex *vertex){
	cout << *vertex << '\n';
	for(Vertex *v: vertex->getNeighbourList()){
		if(!v->isVisited()){
			v->setVisited(true);
			dfs(v);
		}			
	}
}

void DepthFirstSearch::printVertices() const{
	for(auto vertex: vertexList){
		cout << *vertex << '\n';
	}
}