//02-Recursion(Sum)

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