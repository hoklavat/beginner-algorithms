//52-DivideConquer(StringConversion)

#include <iostream>
using namespace std;

int findMinOperationsAux(string s1, string s2, int i1, int i2){
	if(i1 == s1.length())
		return s2.length()-i2;
	
	if(i2 == s2.length())
		return s1.length()-i1;
		
	if(s1.at(i1) == s2.at(i2))
		return findMinOperationsAux(s1, s2, i1+1, i2+1);
	
	int c1 = 1 + findMinOperationsAux(s1, s2, i1+1, i2); //delete.
	int c2 = 1 + findMinOperationsAux(s1, s2, i1, i2+1); //insert.
	int c3 = 1 + findMinOperationsAux(s1, s2, i1+1, i2+1); //replace.
	
	return min(c1, min(c2, c3));
}

int findMinOperations(string s1, string s2){
	return findMinOperationsAux(s1, s2, 0, 0);
}

int main(){
	string s1 = "tarhana";
	string s2 = "lehana";
	
	//one replace, one insert, one delete.
	cout << "Minimum operations to convert " << s1 << " to " << s2 << " is " << findMinOperations(s1, s2) << endl;
	
	return 0;
}