//Dynamic(OptimalBinarySearchTree)
//Task: construct binary search tree such that total cost of all searches is as small as possible.
//keys are stored in K array in sorted order .
//frequencies are stored in F array such that index of frequency matches with index of corresponding key.
//Reference: binary search tree, recursion, dynamic programming.
//Time Complexity: O(n^x)

#include <iostream>
#include <climits>
using namespace std;

int sum(int F[], int i, int j){
	int s = 0;
	for(int k = i; k <= j; k++) s += F[k];
	return s;
}

int optCost(int F[], int i, int j){
	if(j < i) return 0; //no element in sub array.
	if(j == i) return F[i]; //one element in sub array.	
	int fsum = sum(F, i, j); //sum of frequencies between i and j.
	int min = INT_MAX;

	for(int r = i; r <= j; ++r){
		int cost = optCost(F, i, r-1) + optCost(F, r+1, j);
		if(cost < min) min = cost;
	}

	return min + fsum;
}

//Recursion
int optimalSearchTree1(int K[], int F[], int n){
	return optCost(F, 0, n - 1);
}

//Dynamic
int optimalSearchTree2(int K[], int F[], int n){
	int cost[n][n];

	for(int i = 0; i < n; i++) cost[i][i] = F[i];

	for(int L = 2; L <= n; L++){
		for(int i = 0; i <= n-L+1; i++){
			int j = i+L-1;
			cost[i][j] = INT_MAX;
			for(int r = i; r <= j; r++){
				int c =((r > i)? cost[i][r-1]:0) + ((r < j)? cost[r+1][j]:0) + sum(F, i, j);
				if(c < cost[i][j])cost[i][j] = c;
			}
		}
	}
	
	return cost[0][n-1];
}

int main(){
	int K[] = {10, 12, 20};
	int F[] = {34, 8, 50};
	int n = sizeof(K)/sizeof(K[0]);
	cout << "Cost of Optimal BST is " << optimalSearchTree1(K, F, n) << endl;
	cout << "Cost of Optimal BST is " << optimalSearchTree2(K, F, n) << endl;
	
	return 0;
}