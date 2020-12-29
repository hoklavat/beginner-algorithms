//04-Recursion(Fibonacci)
//fibonacci number is sum of previous two fibonacci numbers assuming that F(0)=0 and F(1)=1 where F(n) is nth fibonacci number.
//F(n)=F(n-1)+F(n-2). 0, 1, (0+1), (1+1), (1+2), (2+3), (3+5), ...

#include <iostream>
using namespace std;

//Head Recursion
int Fibonacci_Head(int n){
	if(n == 0) return 0;
	if(n == 1) return 1;
	int fib1 = Fibonacci_Head(n-1); //n=2 -> 1.
	int fib2 = Fibonacci_Head(n-2); //n=2 -> 0.
	return fib1+fib2; //n=2 -> 1+0=1.
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