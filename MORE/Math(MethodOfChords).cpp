//Math(MethodOfChords)
//Task: find root of continuous function in interval [a, b] where f(a)*f(b) < 0.
//Reference: numerical analysis.
//Worse case can be very slow.

#include<iostream>
using namespace std;

#define MAX_ITER 1000000

//Example Function.
double f(double x){
	return x*x*x - x*x + 2;
}

void chord(double a, double b){
	if(f(a)*f(b) >= 0) return;

	double c = a;
	for(int i = 0; i < MAX_ITER; i++){
		c =(a*f(b)-b*f(a))/(f(b)-f(a)); //x-crossing of line connecting a and b.

		if(f(c)==0) break;
		else if(f(c)*f(a) < 0) b = c;
		else a = c;
	}
	cout << "Root of function is " << c << endl;
}

int main(){
	double a =-200, b = 300;
	chord(a, b);
	return 0;
}

