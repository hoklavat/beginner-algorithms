//Math(BisectionMethod)
//Task: find root of continuous function in interval [a, b] where f(a)*f(b) < 0.
//Reference: intermediate value theorem.
//This algorithm cannot detect multiple roots.

#include<iostream>
using namespace std;

#define EPSILON 0.01

//Example Function.
double f(double x){
	return x*x*x - x*x + 2;
}

void bisection(double a, double b){
	if(f(a)*f(b) >= 0) return;

	double c = a;
	while((b-a) >= EPSILON){
		c =(a+b)/2; //middle point.
		if(f(c) == 0.0) break;
		else if(f(c)*f(a) < 0) b = c;
		else a = c;
	}
	cout << "Root of function is " << c << endl;
}

int main(){
	double a =-200, b = 300;
	bisection(a, b);	
	return 0;
}

