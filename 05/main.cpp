//05- Backtracking (N-Queen's Problem)
//place N queens on an NxN chess board so that no queen threatens any other.

#include "NQueensProblem.h"

int main(){
	QueensProblem problem{5};
	problem.solve();	
	return 0;
}
