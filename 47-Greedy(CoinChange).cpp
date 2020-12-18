//47-Greedy(CoinChange)

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int d[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000}; //denominations.
int n = sizeof(d)/sizeof(d[0]); //number of denominations.

void findMin(int V){ //V is target total.
	sort(d, d+n); //sort from smalles to largers.
	vector<int> result;
	
	for(int i = n-1; i >= 0; i--){
		while(V >= d[i]){
			V -= d[i];
			result.push_back(d[i]);
		}
	}

	for(int i = 0; i < result.size(); i++)
		cout << result[i] << " + ";
	cout << "\b\b " << endl;;
}

int main(){
	int n = 93;
	
	cout << "Minimal number of change for " << n << " is: ";
	findMin(n);
	
	return 0;
}