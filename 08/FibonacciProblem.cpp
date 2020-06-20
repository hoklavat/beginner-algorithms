#include "FibonacciProblem.h"
#include <iostream>
using std::cout;

FibonacciAlgorithm::FibonacciAlgorithm(){
	memorizeTable.resize(100);
	memorizeTable[0] = 0;
	memorizeTable[1] = 1;
}

int FibonacciAlgorithm::fibonacciMemorize(int n){
	if(n == 0) return 0;
	if(n == 1) return 1;
	if(memorizeTable[n] != 0){
		return memorizeTable[n];
	}
	else{
		memorizeTable[n] = fibonacciMemorize(n - 1) + fibonacciMemorize(n - 2); //for iteration is faster than recursion
		return memorizeTable[n];
	}	
}

int FibonacciAlgorithm::naiveFibonacci(int n){
	if(n == 0) return 0;
	if(n == 1) return 1;
	return naiveFibonacci(n - 1) + naiveFibonacci(n - 2);
}