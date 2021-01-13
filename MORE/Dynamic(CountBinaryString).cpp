//Dynamic(CountBinaryString)
//Task: given positive integer N, count all possible distinct binary strings of length N such that there are no consecutive 1’s.
//Reference: dynamic programming, fibonacci, binary string.
//count is also (n+2)th fibonacci number for n>=1.

#include <iostream>
using namespace std;

int count(int n){
	int a[n], b[n];
	a[0] = b[0] = 1;
	for(int i = 1; i < n; i++){
		a[i] = a[i-1] + b[i-1];
		b[i] = a[i-1];
	}
	return a[n-1] + b[n-1];
}

int main(){
	cout << count(3) << endl; //000, 001, 010, 100, 101.
	return 0;
}
