#ifndef DepthFirstSearch_h
#define DepthFirstSearch_h

#include "Vertex.h"
#include <vector>
#include <memory>
#include <iostream>
using std::vector;
using std::shared_ptr;
using std::cout;

class DepthFirstSearch{
	vector<shared_ptr<Vertex>> vertexList;
public:
	DepthFirstSearch(vector<shared_ptr<Vertex>> const &_vertexList);
	void operator()();
	void printVertices() const;
private:
	void dfs(Vertex *vertex);
};

#endif