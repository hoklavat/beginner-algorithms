//Dynamic(NondecreasingNumbers)
//Task: given number of digits n, find count of total non-decreasing numbers with n digits.
//nondecreasing number: every digit except first one is greater than or equal to previous digit.
//Reference: dynamic programming.

#include <iostream>
#include <cstring>
using namespace std;

long long int count(int n){
	long long int D[10][n+1]; //[ends-with][length]
	memset(D, 0, sizeof D);

	for(int i = 0; i < 10; i++)
		D[i][1] = 1;

	for(int d = 0; d <= 9; d++){ //digit.
		for(int l = 2; l <= n; l++){ //length.
			for(int x = 0; x <= d; x++)
				D[d][l] += D[x][l-1];
		}
	}

	long long int c = 0;
	for(int i = 0; i < 10; i++)
		c += D[i][n];

	return c;
}

long long int formula(int n){
    int N = 10;
    long long count = 1;
    for(int i=1; i<=n; i++){
        count *=(N+i-1);
        count /= i;
    }
    return count;
}

int main(){
	int n = 3;
	cout << count(n) << endl; //123, 134, 125, etc...
	cout << formula(n) << endl;
	return 0;
}