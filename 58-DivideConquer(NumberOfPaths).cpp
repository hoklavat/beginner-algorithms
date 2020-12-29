//58-DivideConquer(NumberOfPaths)
//find number of paths to reach last cell without exceeding given cost limit.

#include <iostream>
using namespace std;

#define SIZE 4

int numberOfPaths(int data[SIZE][SIZE], int row, int col, int cost){
	if(cost < 0) return 0;
	if(row == 0 && col == 0) return (data[0][0] == cost)?1:0;
	if(row == 0) return numberOfPaths(data, 0, col-1, cost-data[row][col]);
	if(col == 0) return numberOfPaths(data, row-1, 0, cost-data[row][col]);	
	int n1 = numberOfPaths(data, row-1, col, cost-data[row][col]); //number of paths from previous row.
	int n2 = numberOfPaths(data, row, col-1, cost-data[row][col]); //number of paths from previous column.	
	return n1+n2;	
}

int main(){
	int cost = 25;
	int data[SIZE][SIZE] = {
		{4, 7, 1, 6},
		{5, 7, 3, 9},
		{3, 2, 1, 2},
		{7, 1, 6, 3}
	};	
	
	cout << "Total number of paths with cost " << cost << " are " << numberOfPaths(data, SIZE-1, SIZE-1, cost) << endl;
	
	return 0;
}

