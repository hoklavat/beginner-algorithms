#ifndef BreadthFirstSearch_h
#define BreadthFirstSearch_h

#include "Vertex.h"
#include <deque>
#include <memory>
#include <iostream>

class BreadthFirstSearch{
public:
	void operator()(shared_ptr<Vertex> root) const;
};

#endif