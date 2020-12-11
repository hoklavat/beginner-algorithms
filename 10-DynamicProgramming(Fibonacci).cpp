//09-DynamicProgramming(Fibonacci)
//this method reduces calculation count by storing previous calculation results in a table.

#include <iostream>
#include <vector>
using namespace std;

class FibonacciAlgorithm{
	vector<int> memorizeTable; //stores previous calculations.
public:
	FibonacciAlgorithm();
	int fibonacciMemorize(int n);
	int naiveFibonacci(int n);
};

FibonacciAlgorithm::FibonacciAlgorithm(){
	memorizeTable.resize(100);
	memorizeTable[0] = 0;
	memorizeTable[1] = 1;
}

//if nth fibonacci number is already existed in table return it, otherwise calculate and store it in that table then return.
int FibonacciAlgorithm::fibonacciMemorize(int n){
	if(n == 0) return 0;
	if(n == 1) return 1;
	if(memorizeTable[n] != 0){
		return memorizeTable[n];
	}
	else{
		memorizeTable[n] = fibonacciMemorize(n - 1) + fibonacciMemorize(n - 2);
		return memorizeTable[n];
	}	
}

//repeats same calculations.
int FibonacciAlgorithm::naiveFibonacci(int n){
	if(n == 0) return 0;
	if(n == 1) return 1;
	return naiveFibonacci(n - 1) + naiveFibonacci(n - 2);
}

int main(){
	FibonacciAlgorithm fibonacciAlgorithm;
	
	//dynamic fibonacci. very fast.
	cout << "60th Fibonacci Number: " << fibonacciAlgorithm.fibonacciMemorize(60) << '\n';
	
	//naive fibonacci. too slow.
	//cout << "60th Fibonacci Number: " << fibonacciAlgorithm.naiveFibonacci(60) << '\n';
	
	return 0;
}