//08-Backtracking(KnightsTour)
//can a knight visit every square of a chess board (8x8) exactly once started from first square?
//closed knight's tour: knight's ending point is same as the starting point.

#include <iostream>
#include <iomanip>
#include <vector>
#include <array>
using namespace std;

class KnightTour{
private:
	constexpr static int BOARD_SIZE = 8;
	vector<vector<int>> solutionMatrix;
	const static array<int, 8> xMoves;
	const static array<int, 8> yMoves;	
	
	void initializeBoard();
	
public:
	KnightTour();
	bool isValidMove(int x, int y);
	bool solveProblem(int stepCount, int x, int y);
	void showSolution();
	void solveKnightTourProblem();
};

//all possible combinations of knight movements.
const array<int, 8> KnightTour::xMoves = {2, 1, -1, -2, -2, -1, 1, 2};
const array<int, 8> KnightTour::yMoves = {1, 2, 2, 1, -1, -2,- 2, -1};

KnightTour::KnightTour(){
	//memory allocation for chess board.
	solutionMatrix.resize(BOARD_SIZE);
	for(auto &subMatrix: solutionMatrix)
		subMatrix.resize(BOARD_SIZE);
		
	//initally fill all squares with minimum integer value.
	initializeBoard();
}

void KnightTour::initializeBoard(){
	for(int x = 0; x < BOARD_SIZE; x++)
		for(int y = 0; y < BOARD_SIZE; y++)
			solutionMatrix[x][y] = INT32_MIN; 
}

//not valid square if x and y are out of boundaries or square has been visited already.
bool KnightTour::isValidMove(int x, int y){
	if(x < 0 || x >= BOARD_SIZE)
		return false;
	if(y < 0 || y >= BOARD_SIZE)
		return false;
	if(solutionMatrix[x][y] != INT32_MIN)
		return false;
	return true;
}

bool KnightTour::solveProblem(int stepCount, int x, int y){
	//base case of recursion.
	if(stepCount == BOARD_SIZE * BOARD_SIZE){
		return true;
	}
	
	//put a knight on square(0, 0), try all possible squares that knight can be placed, 
	//if square is not visited before put knight on this square, repeat process recursively with new square.
	//if stepCount equals all squares solved, otherwise not solved.
	for(size_t i = 0; i < xMoves.size(); i++){
		int nextX = x + xMoves[i];
		int nextY = y + yMoves[i];
		if(isValidMove(nextX, nextY)){
			solutionMatrix[nextX][nextY] = stepCount;
			if(solveProblem(stepCount + 1, nextX, nextY)){
				return true;
			}
			solutionMatrix[nextX][nextY] = INT32_MIN; //Backtracking
		}
	}
	return false;
}

void KnightTour::showSolution(){
	for(int i = 0; i < BOARD_SIZE; i++){
		cout << left;
		for(int j = 0; j < BOARD_SIZE; j++){
			cout << setw(2) << solutionMatrix[i][j] << setw(2) << ' ';			
		}
		cout << '\n';
	}
}

void KnightTour::solveKnightTourProblem(){
	solutionMatrix[0][0] = 0;
	if(!solveProblem(1, 0, 0)){
		cout << "No feasible solution found...\n";
		return;
	}
	showSolution();
}

int main(){
	KnightTour knightTour;
	knightTour.solveKnightTourProblem();
	return 0;
}