//08-Backtracking(KnightsTour)
//knight must visit each square on chess board exactly once without violating chess rules.

#include <iostream>
#include <iomanip>
using namespace std;

#define N 8 //size of board.

void print(int S[N][N]){
	for(int x = 0; x < N; x++){
		for(int y = 0; y < N; y++)
			cout << " " << setw(2) << S[x][y] << " ";
		cout << endl;
	}
}

int isSafe(int x, int y, int S[N][N]){
	return(x >= 0 && x < N && y >= 0 && y < N && S[x][y] == -1); //true if square not visited before.
}

int solve(int x, int y, int movei, int S[N][N], int xMove[N], int yMove[N]){
	int k, next_x, next_y;
	
	if(movei == N*N) return 1; //all squares are visited.
	
	for(k = 0; k < 8; k++){
		next_x = x + xMove[k]; //next possible column.
		next_y = y + yMove[k]; //next possible row.
		if(isSafe(next_x, next_y, S)){
			S[next_x][next_y] = movei; //hold movement number.
			if(solve(next_x, next_y, movei+1, S, xMove, yMove) == 1) return 1;
			else S[next_x][next_y] = -1;
		}
	}
	
	return 0;
}

int main(){
	int S[N][N]; //squares of board.
	
	//possible knight movements.
	int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
	int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};
	
	//initialize board.
	for(int x = 0; x < N; x++)
		for(int y = 0; y < N; y++)
			S[x][y] = -1;

	S[0][0] = 0;
	if(solve(0, 0, 1, S, xMove, yMove) == 0) {
		cout << "Solution does not exist.";
	}
	else{
		cout << "Solution exists: " << endl;
		print(S);
	}
		
	return 0;
}