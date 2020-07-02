#ifndef Vertex_h
#define Vertex_h

#include <string>
#include <vector>
using namespace std;

class Vertex{
private:
	string name = 0;
	bool visited = false;
	vector<Vertex *> neighbours;
public:
	Vertex(const string &name);
	~Vertex();
	const string &getName() const;
	void setName(const string &name);
	bool isVisited() const;
	void setVisited(bool visited);
	
	const vector<Vertex *> &getNeighbourList() const;
	void addNeighbour(Vertex *neighbour);
	friend ostream &operator<<(ostream &os, const Vertex &vertex);	
};

#endif