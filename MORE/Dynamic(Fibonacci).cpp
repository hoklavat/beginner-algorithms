//Dynamic(Fibonacci)
//Task: find nth fibonacci number.
//Reference: dynamic programming, fibonacci, memoization, tabulation.

#include<iostream>

#define NIL -1
#define MAX 100

int T[MAX];

void init(){
	for(int i = 0; i < MAX; i++)
		T[i] = NIL;
}

int fibMemoization(int n){
	if (T[n] == NIL){
		if (n <= 1) T[n] = n;
		else T[n] = fibMemoization(n-1) + fibMemoization(n-2);
	}
	return T[n];
}

int fibTabulation(int n){
	int f[n+1];
	int i;
	f[0] = 0; 
	f[1] = 1; 
	for (i = 2; i <= n; i++)
		f[i] = f[i-1] + f[i-2];
	return f[n];
}

int main (){
	int n = 40;

	init();
	std::cout << "Fibonacci by Memoization: " << fibMemoization(n) << std::endl;
	
	init();
	std::cout << "Fibonacci by Tabulation: " << fibTabulation(n) << std::endl;

	return 0;
}
