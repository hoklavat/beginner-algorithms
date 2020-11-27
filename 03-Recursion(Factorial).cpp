//03-Recursion(Factorial)

#include <iostream>
using namespace std;

int Factorial(int n){
	if(n == 1) return 1;
	return n * Factorial(n-1);
}

//recursion with accumulator is more memory efficient. 
//rather than storing a on stack until recursion ends, 
//it is stored temporarily on heap for each recursive call.
int Factorial(int n, int a){
	if(n == 1) return a;
	return Factorial(n-1, n*a);
}

int main(){
	cout << "Factorial(5): " << Factorial(5) << endl;	
	cout << "Factorial(5, 1): " << Factorial(5, 1) << endl;
	return 0;
}