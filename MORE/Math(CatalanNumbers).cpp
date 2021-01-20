//Math(CatalanNumbers)
//Task: given number n find number of valid parentheses expressions of that length.
//Reference: binomial equation, catalan number.
//Time Complexity: O(n).

#include <iostream>
using namespace std;

//Binomial Coefficient.
unsigned long int binom(unsigned int n, unsigned int k){
	unsigned long int res = 1;
	if(k > n-k) k = n-k; //n:highest degree, k:specific degree.

	for(int i = 0; i < k; ++i){
		res *= (n-i);
		res /= (i+1);
	}

	return res;
}

//nth Catalan Number.
unsigned long int catalan(unsigned int n){
	unsigned long int c = binom(2*n, n);
	return c /(n + 1); //2nCn/(n+1).
}

//Find Number of Balanced Paranthesis.
unsigned long int findWays(unsigned n){
	if(n&1) return 0; //odd n.
	return catalan(n/2); //n/2'th catalan number.
}

int main(){
	int n = 6;
	cout << "Total possible paranthesis expressions of length " << n << " is " << findWays(6) << std::endl;
	return 0;
}
