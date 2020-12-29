//57-DivideConquer(MinimumCost)
//find minimum cost to reach last cell.

#include <iostream>
#include <climits>
using namespace std;

int minCost(int cost[5][5], int row, int col){
	if(row == -1 || col == -1) return INT_MAX;
	if(row == 0 && col == 0) return cost[0][0];
	
	int mcUp = minCost(cost, row-1, col);
	int mcLeft = minCost(cost, row, col-1);
	int mc = min(mcUp, mcLeft);	
	int cellCost = cost[row][col];
	
	return mc+cellCost;	
}

int main(){
	int cost[5][5] = {
		{4, 7, 8, 6, 4},
		{6, 7, 3, 9, 2},
		{3, 8, 1, 2, 4},
		{7, 1, 7, 3, 7},
		{2, 9, 8, 9, 3}
	};
	
	cout << "Minimum cost to reach last cell is " << minCost(cost, 4, 4) << endl;
	
	return 0;
}

