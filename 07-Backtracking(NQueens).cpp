//06-Backtracking(N-Queens)
//place N queens on an NxN chess board so that no queen threatens any other.

#include <vector>
#include <iostream>
using namespace std;

class QueensProblem{
private:
	vector<vector<int>> chessTable;
	int numOfQueens = 0;
	
	bool isPlaceValid(int rowIndex, int colIndex) const;
	bool setQueens(int colIndex);	
	void printQueens() const;
	
public:
	QueensProblem(int _numOfQueens);
	void solve();
};

QueensProblem::QueensProblem(int _numOfQueens): numOfQueens(_numOfQueens){
	chessTable.resize(numOfQueens);
	for(auto &chessRow: chessTable)
		chessRow.resize(numOfQueens);
}

//check if a square is threatened by other queen.
bool QueensProblem::isPlaceValid(int rowIndex, int colIndex) const{
	//check if queen exists at same row.
	for(int i = 0; i < colIndex; i++)
		if(chessTable[rowIndex][i] == 1)
			return false; //
			
	//check if queen exists at diagonal from top left to bottom right.
	for(int i = rowIndex, j = colIndex; i >= 0 && j >= 0; i--, j--)
		if(chessTable[i][j] == 1)
			return false;
			
	//check if queen exists at diagonal from top right to bottom left.
	for(int i = rowIndex, j = colIndex; i < numOfQueens && j >= 0; i++, j--)
		if(chessTable[i][j] == 1)
			return false;
	
	//no queen threatens this square.
	return true; 
}

//set queens at squares which is not threatened by other queens.
bool QueensProblem::setQueens(int colIndex){
	//base case of recursion.
	if(colIndex == numOfQueens){
		return true;
	}
	
	//for each row, start with column 0, scan until end column, if a non-threatened square is found place 1, else place 0.
	for(int rowIndex = 0; rowIndex < numOfQueens; rowIndex++){
		if(isPlaceValid(rowIndex, colIndex)){
			chessTable[rowIndex][colIndex] = 1;
			if(setQueens(colIndex + 1)){ //recursion
				return true;
			}
			chessTable[rowIndex][colIndex] = 0;
		}
	}
	
	return false;
}

void QueensProblem::printQueens() const{
	for(size_t i = 0; i < chessTable.size(); i++){
		for(size_t j = 0; j < chessTable.size(); j++){
			if(chessTable[i][j] == 1){
				cout << " * ";				
			}
			else{
				cout << " - ";
			}
		}
		cout << "\n";
	}
}

void QueensProblem::solve(){
	if(setQueens(0)){
		printQueens();
	}
	else{
		cout << "There is no solution...\n";
	}
}

int main(){
	QueensProblem problem{5};
	problem.solve();	
	return 0;
}