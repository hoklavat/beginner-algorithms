#ifndef GraphColoring_h
#define GraphColoring_h

#include <vector>
using std::vector;

class GraphColoring{
	vector<vector<int>> graphMatrix;
	int numOfColors;
	vector<int> colors;
public:
	GraphColoring(const vector<vector<int>> &graph, int _numOfColors);
	void operator()();
private:
	bool solve(size_t nodeIndex);
	bool isColorValid(size_t nodeIndex, size_t colorIndex);
	void showResult();
};

#endif
