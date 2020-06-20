//08- Dynamic Programming (Fibonacci)
//reduce calculation count by storing previous calculation results in a table.
#include "FibonacciProblem.h"
#include <iostream>
using std::cout;

int main(){
	FibonacciAlgorithm fibonacciAlgorithm;
	cout << fibonacciAlgorithm.fibonacciMemorize(60) << '\n';
	//cout << fibonacciAlgorithm.naiveFibonacci(60) << '\n'; //too slow
	return 0;
}
