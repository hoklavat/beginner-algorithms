//56-DivideConquer(LongestPalindromicSubstring)

#include <iostream>
using namespace std;

int findLPSAux(string s, int start, int end){
	if(start > end) return 0;
	if(start == end) return 1;
	
	int c1 = 0;
	if(s.at(start) == s.at(end)){
		int r = end - start - 1;
		if(r == findLPSAux(s, start+1, end-1)) c1 = r + 2;
	}
	
	int c2 = findLPSAux(s, start+1, end);
	int c3 = findLPSAux(s, start, end-1);
	
	return max(c1, max(c2, c3));
}

int findLPS(string s){
	return findLPSAux(s, 0, s.length()-1);
}

int main(){
	string s = "popboboblop";
	
	cout << "Length of longest palindromic substring in " << s << " is " << findLPS(s) << endl;
	
	return 0;
}