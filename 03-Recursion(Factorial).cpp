//03-Recursion(Factorial)
//multiplication of integers from 1 to n. 1x2x3x...xn.

#include <iostream>
using namespace std;

int Factorial(int n){
	if(n == 1) return 1;
	return n * Factorial(n-1);
}

//recursion with accumulator is more memory efficient. 
//rather than storing a on stack, it is stored on heap temporarily for each recursive call.
int Factorial(int n, int a){
	if(n == 1) return a;
	return Factorial(n-1, n*a);
}

int main(){
	cout << "Factorial(5): " << Factorial(5) << endl;	
	cout << "Factorial(5, 1): " << Factorial(5, 1) << endl;
	return 0;
}