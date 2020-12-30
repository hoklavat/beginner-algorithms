//06-Backtracking(N-Queens)
//place N queens on an NxN chess board so that no queen threatens any other.

#include <iostream>
using namespace std;

#define N 4

void print(int B[N][N]){
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++)
			cout << " " << B[i][j] << " ";
		cout << endl;
	}
}

bool isSafe(int B[N][N], int row, int col){
	int i, j;
	
	for(i = 0; i < col; i++)
		if(B[row][i]) return false; //already occupied.
		
	for(i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if(B[i][j]) return false; //queen at diagonal.

	for(i = row, j = col; j >= 0 && i < N; i++, j--)
		if(B[i][j]) return false; //queen at other diagonal.

	return true;
}

bool solve(int B[N][N], int col){
	if(col >= N) return true;

	for(int i = 0; i < N; i++){
		if(isSafe(B, i, col)){
			B[i][col] = 1;
			if(solve(B, col + 1)) return true;
			B[i][col] = 0; //backtrack
		}	
	}
	return false;
}

int main(){
	int B[N][N] = { 
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0} 
	};

	if(solve(B, 0) == false) cout << "Solution does not exist." << endl;
	else print(B);
	
	return 0;
}