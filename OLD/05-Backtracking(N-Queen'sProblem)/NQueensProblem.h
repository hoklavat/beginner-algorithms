#pragma once
#include <vector>
using std::vector;

class QueensProblem{
	vector<vector<int>> chessTable;
	int numOfQueens = 0;
public:
	QueensProblem(int _numOfQueens);
	void solve();
private:
	bool setQueens(int colIndex);
	bool isPlaceValid(int rowIndex, int colIndex) const;
	void printQueens() const;
};