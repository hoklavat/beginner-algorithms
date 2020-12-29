//02-Recursion(Sum)
//sum of integers from 1 to n. 1+2+3+...+n.

#include <iostream>
using namespace std;

int Sum(int n){
	if(n == 1) return 1;
	return n + Sum(n-1);
}

int main(){
	cout << "Sum of integers from 1 to 10: " << Sum(10) << endl;	
	return 0;
}