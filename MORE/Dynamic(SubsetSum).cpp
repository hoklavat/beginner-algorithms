//Dynamic(SubsetSum)
//Task: determine if there is subset of given set with sum equal to given sum.
//Reference: dynamic programming, recursion.
//Time Complexity: recursion:O(2^n), dynamic:O(sum*n).

#include <iostream>
using namespace std;

//Recursion
bool isSubsetSum1(int set[], int n, int sum){
	if(sum == 0) return true;
	if(n == 0) return false;
	if(set[n-1] > sum) return isSubsetSum1(set, n-1, sum);
	return isSubsetSum1(set, n-1, sum) || isSubsetSum1(set, n-1, sum-set[n-1]);
}

//Dynamic
bool isSubsetSum2(int set[], int n, int sum){
	bool subset[n+1][sum+1];
 
	for(int i = 0; i <= n; i++) subset[i][0] = true;
	for(int i = 1; i <= sum; i++) subset[0][i] = false;
 
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= sum; j++){
			if(j < set[i - 1]) subset[i][j] = subset[i-1][j];
			if(j >= set[i - 1]) subset[i][j] = subset[i-1][j] || subset[i-1][j-set[i-1]];
		}
	}
 
	for(int i = 0; i <= n; i++){
	   for(int j = 0; j <= sum; j++)
		  cout << subset[i][j] << "\t";
	   cout << endl;
	 }
 
	return subset[n][sum];
}

int main(){
	int set[] = {3, 34, 4, 12, 5, 2};
	int sum = 9;
	int n = sizeof(set)/sizeof(set[0]);
	
	if(isSubsetSum1(set, n, sum) == true)
		cout << "Found a subset with given sum." << endl;
	else
		cout << "No subset with given sum" << endl;
		
	cout << endl;
	
	if(isSubsetSum2(set, n, sum) == true)
		cout << "Found a subset with given sum." << endl;
	else
		cout << "No subset with given sum" << endl;

	return 0;
}
