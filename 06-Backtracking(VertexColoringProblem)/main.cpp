//06- Backtracking (Vertex Coloring Problem)
//coloring vertices of a graph such that no two adjacent vertices share the same color.
#include <iostream>
#include <vector>
#include "GraphColoring.h"
using std::vector;

using namespace std;

int main(){
	const vector<vector<int>> graphMatrix = {
		{0, 1, 0, 1, 0},
		{1, 0, 1, 1, 0},
		{0, 1, 0, 1, 0},
		{1, 1, 1, 0, 1},
		{0, 0, 0, 1, 0},
	};
	
	constexpr int numOfColors = 3;
	GraphColoring graphColoring(graphMatrix, numOfColors);
	graphColoring();
	
	return 0;
}
