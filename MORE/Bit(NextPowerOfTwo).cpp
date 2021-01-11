//Bit(NextPowerOfTwo)
//Task: find number p which is greater than or equal to given number n and smallest power of 2.
//Formula: p = pow(2, ceil(log2(n)).
//Reference: bitwise operations.
//Time Complexity: O(logn)

#include <iostream>
using namespace std;

unsigned int find(unsigned int n){
	unsigned count = 0;

	if(n && !(n&(n-1))) return n; //n is power of two.
	
	while(n != 0){
		n >>= 1; //count of bits.
		count += 1;
	}
	
	//while (p < n) p <<= 1; //alternative.
	
	return 1 << count; //2^count.
}

//faster method for 32-bit integers.
unsigned int find32(unsigned int n){ 
    n--; //10001-1=10000.
    n |= n >> 1; //11000.
    n |= n >> 2; //11110.
    n |= n >> 4; //11111.
    n |= n >> 8; //11111.
    n |= n >> 16; //11111.
    n++; //10000.
    return n;
}

int main(){
	unsigned int n = 17;
	cout << find(n) << endl;
	cout << find32(n) << endl;
	
	return 0;
}