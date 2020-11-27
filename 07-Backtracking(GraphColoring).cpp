//07-Backtracking(GraphColoring)
//graph is an nxn matrice that represents adjacency of vertices where n is the number of vertices.
//value of graph[i][j] is 1 if there is a direct edge from i to j (i and j are adjacent), otherwise 0.
//m is maximum number of colors that can be used.
//using m colors, color vertices of a graph such that no two adjacent vertices share the same color.

#include <iostream>
#include <vector>
using namespace std;

class GraphColoring{
private:
	int numOfColors;
	vector<int> colors;	
	vector<vector<int>> graphMatrix;
	
	bool isColorValid(size_t nodeIndex, size_t colorIndex); //size_t = unsigned int
	bool solve(size_t nodeIndex);	
	void showResult();
	
public:
	GraphColoring(const vector<vector<int>> &graph, int _numOfColors);
	void operator()();
};

GraphColoring::GraphColoring(const vector<vector<int>> &graph, int _numOfColors): graphMatrix(graph), numOfColors(_numOfColors){
	colors.resize(graphMatrix.size());
}

//if any adjacent vertice of input vertice(nodeIndex) have same color denoted by colorIndex return false.
bool GraphColoring::isColorValid(size_t nodeIndex, size_t colorIndex){
	for(size_t i = 0; i < graphMatrix.size(); i++){
		if(graphMatrix[nodeIndex][i] == 1 && colorIndex == colors[i]) //if adjacent vertices have same color return false.
			return false;
	}
	return true;
}

//color input vertice with colorIndex if any adjacent vertice of this vertice doesn't already colored with the same color.
bool GraphColoring::solve(size_t nodeIndex){
	//recursion base case.
	if(nodeIndex == graphMatrix.size())
		return true;
		
	for(int colorIndex = 1; colorIndex <= numOfColors; colorIndex++){
		if(isColorValid(nodeIndex, colorIndex)){ //if false at any recursion therere is no solution.
			colors[nodeIndex] = colorIndex; 
			if(solve(nodeIndex + 1))
				return true;
		}
	}
	
	return false;
}

void GraphColoring::operator()(){
	if(solve(0)){
		showResult();
	}
	else{
		cout << "No solution with the given parameters...\n";
	}
}

void GraphColoring::showResult(){
	for(size_t i = 0; i < graphMatrix.size(); i++)
		cout << "Node " << (i + 1) << " has color index: " << colors[i] << "\n";
	cout << "\n";
}

int main(){
	//matrix represents five nodes A, B, C, D, E and which of them are adjacent to each other.
	//for example A is adjacent with B and D.
	const vector<vector<int>> graphMatrix = {
		//A  B  C  D  E
		{ 0, 1, 0, 1, 0 }, //A
		{ 1, 0, 1, 1, 0 }, //B
		{ 0, 1, 0, 1, 0 }, //C
		{ 1, 1, 1, 0, 1 }, //D
		{ 0, 0, 0, 1, 0 }, //E
	};
	
	constexpr int numOfColors = 3;
	GraphColoring graphColoring(graphMatrix, numOfColors);
	graphColoring();
	
	return 0;
}