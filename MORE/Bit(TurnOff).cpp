//Bit(TurnOff)
//Task: turn off particular bit in given number.

#include <iostream>
using namespace std;

int turnOff(int n, int k){
	if (k <= 0) return n;
	return (n & ~(1<<(k-1))); //only k'th bit is zero.
}

int main(){
	int n = 15;
	int k = 4;
	cout << turnOff(n, k) << endl;
	return 0;
}
