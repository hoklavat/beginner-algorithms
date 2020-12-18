//50-DivideConquer(NumberOfWays)
//number of different ways to express number as sum of 1, 3 and 4.

#include <iostream>
using namespace std;

int NumberOfWays(int n){
	if(n == 0 || n == 1 || n == 2) return 1;	
	if(n == 3) return 2;
	
	int subtract1 = NumberOfWays(n-1);
	int subtract3 = NumberOfWays(n-3);
	int subtract4 = NumberOfWays(n-4);
	
	return subtract1+subtract3+subtract4;
}

int main(){
	cout << NumberOfWays(10) << endl;
}