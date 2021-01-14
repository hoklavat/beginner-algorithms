//Bit(OppositeSigns)
//Task: given two signed integers, return true if signs of given integers are different, otherwise false.
//Reference: bitwise exclusive or.

#include <iostream>
using namespace std;

bool oppositeSigns(int x, int y){
	return ((x^y) < 0); //xor of sign bits is 1. so result of xor is negative.
}

int main(){
	int x = 100, y = -100;
	
	if (oppositeSigns(x, y) == true)
		cout << "Signs are opposite." << endl;
	else
		cout << "Signs are not opposite." << endl;
		
	return 0;
}