//Search(FindMinimumUnsorted)
//Task: given unsorted array A of size n, find minimum length subarray such that sorting this subarray makes whole array sorted.
//Reference: search, sort.
//Time Complexity: O(n)

#include <iostream> 
using namespace std; 

void printUnsorted(int A[], int n){
	int s = 0, e = n-1, i, max, min;
	
	//traverse left to right until smaller from previous is found.
	for(s = 0; s < n-1; s++){
		if(A[s] > A[s+1]) break;
	}
	
	//if reached end array is completely sorted. return.
	if(s == n-1){
		cout << "Whole array is sorted." << endl;
		return;
	}
	
	//traverse right to left until greater from previous is found.
	for(e = n-1; e > 0; e--){
		if(A[e] < A[e-1])
			break;
	}
	
	//assume max and min is first smaller.
	max = A[s];
	min = A[s];
	
	//search extremums between first smaller and first greater.
	for(i = s+1; i <= e; i++){
		if(A[i] > max) max = A[i]; //new maximum.
		if(A[i] < min) min = A[i]; //new minimum.
	}
	
	//traverse left to right until greater than minimum is found.
	for(i = 0; i < s; i++){
		if(A[i] > min){
			s = i; //new start.
			break;
		}
	}
	
	//traverse right to left until smaller than maximum is found.
	for(i = n-1; i >= e+1; i--){
		if(A[i] < max){
			e = i; //new end.
			break;
		}
	}
	
	cout << "Unsorted Array Indexes: "	<< s << " - " << e << endl;
	
	return;
} 

int main(){
	int A[] = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
	int n = sizeof(A)/sizeof(A[0]);
	printUnsorted(A, n);

	return 0;
}