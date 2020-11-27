//04-Recursion(Fibonacci)

#include <iostream>
using namespace std;

//Head Recursion
int Fibonacci_Head(int n){
	if(n == 0) return 0;
	if(n == 1) return 1;
	int fib1 = Fibonacci_Head(n-1);
	int fib2 = Fibonacci_Head(n-2);
	return fib1+fib2;
}

//Tail Recursion
int Fibonacci_Tail(int n){
	if(n == 0) return 0;
	if(n == 1) return 1;
	return Fibonacci_Tail(n-1)+Fibonacci_Tail(n-2);
}

//Accumulative Tail Recursion
int Fibonacci_ATail(int n, int a, int b){
	if(n == 1) return b;
	return Fibonacci_ATail(n-1, b, a+b);
}

int main(){
	cout << "10th Fibonacci Number (Head) : " << Fibonacci_Head(10) << endl;
	cout << "10th Fibonacci Number (Tail) : " << Fibonacci_Tail(10) << endl;
	cout << "10th Fibonacci Number (ATail): " << Fibonacci_ATail(10, 0, 1) << endl;
	return 0;
}