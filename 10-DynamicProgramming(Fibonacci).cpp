//09-DynamicProgramming(Fibonacci)
//this method reduces calculation count by storing previous calculation results in a table.

#include<iostream>
using namespace std;

int fibonacci(int n){
	int f[n+2]; //stores previously calculated fibonacci numbers.
	f[0] = 0;
	f[1] = 1;
	for(int i = 2; i <= n; i++) f[i] = f[i-1]+f[i-2];	
	return f[n];
};

int main(){
	int n = 60;	
	cout << n << "th fibonacci number is " << fibonacci(n) << endl;	
	return 0;
}