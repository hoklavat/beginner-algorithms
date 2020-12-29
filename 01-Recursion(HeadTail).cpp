//01-Recursion(Head/Tail)
//head recursion: function calls itself at beginning. stack overflow risk.
//tail recursion: function calls itself at end. no stack overflow risk.

#include <iostream>
using namespace std;

void Head(int n){
	if(n == 0) return;
	Head(n-1);
	cout << n << " ";
}

void Tail(int n){
	if(n == 0) return;
	cout << n << " ";
	Tail(n-1);
}

int main(){
	cout << "*** HEAD RECURSION ***" << endl;
	Head(10);
	cout << endl << endl;
	
	cout << "*** TAIL RECURSION ***" << endl;
	Tail(10);
	cout << endl;
}