#pragma once
#include <vector>
#include <array>
using std::vector;

class KnightTour{
	vector<vector<int>> solutionMatrix;
	const static std::array<int, 8> xMoves;
	const static std::array<int, 8> yMoves;
	constexpr static int BOARD_SIZE = 8;
public:
	KnightTour();
	void solveKnightTourProblem();
	bool solveProblem(int stepCount, int x, int y);
	bool isValidMove(int x, int y);
	void showSolution();
private:
	void initializeBoard();
};