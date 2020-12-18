//54-DivideConquer(LongestCommonSubsequence)

#include <iostream>
using namespace std;

int findLCSLengthAux(string s1, string s2, int i1, int i2){	
	if(i1 == s1.length() || i2 == s2.length()) return 0;
		
	int c3 = 0;
	if(s1.at(i1) == s2.at(i2)) c3 = 1 + findLCSLengthAux(s1, s2, i1+1, i2+1);	
	int c1 = findLCSLengthAux(s1, s2, i1, i2+1);
	int c2 = findLCSLengthAux(s1, s2, i1+1, i2);
	
	return max(c3, max(c1, c2));
}

int findLCSLength(string s1, string s2){
	return findLCSLengthAux(s1, s2, 0, 0);
}

int main(){
	string s1 = "Hello";
	string s2 = "Hell Fire";
	
	cout << "Length of longest common subsequence in strings " << s1 << " and " << s2 << " is " << findLCSLength(s1, s2) << endl;
	
	return 0;
}