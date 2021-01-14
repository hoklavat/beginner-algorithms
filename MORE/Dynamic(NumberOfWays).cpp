//Dynamic(NumberOfWays)
//Task: find number of ways to obtain given number by summing specified numbers. numbers can be used multiple times.
//Reference: dynamic programming.

#include <iostream>
using namespace std;

//numbers used to reach n are 3, 5 and 10.
int count(int n){
	int T[n+1];
	int i;

	for(int j = 0; j < n+1; j++)
		T[j] = 0;
	
	T[0] = 1; 
	
	for(i = 3; i <= n; i++)
		T[i] += T[i-3];
	
	for(i = 5; i <= n; i++)
		T[i] += T[i-5];
	
	for(i = 10; i <= n; i++)
		T[i] += T[i-10];

	return T[n];
}

int main(void){
	int n = 20;
	cout << "Count for " << n << " is " << count(n) << endl;

	n = 13;
	cout <<"Count for "<< n<< " is " << count(n) << endl;
	
	return 0;
}