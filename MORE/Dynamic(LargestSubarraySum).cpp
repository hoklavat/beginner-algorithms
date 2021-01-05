//Dynamic(LargestSubarraySum)
//Kadane’s Algorithm
//Task:  find sum of contiguous subarray within one-dimensional array of numbers which has largest sum.
//Reference: dynamic programming, search.
//Time Complexity: O(n).

#include<iostream>
#include<climits>
using namespace std;

int maxSubArraySum(int a[], int n){ 
	int max_so_far = INT_MIN, max_ending_here = 0;

	for(int i = 0; i < n; i++){ 
		max_ending_here = max_ending_here + a[i];
		if(max_ending_here < 0) max_ending_here = 0;
		else if(max_so_far < max_ending_here) max_so_far = max_ending_here;		
	}
	
	return max_so_far;
} 

int main(){
	int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	int n = sizeof(a)/sizeof(a[0]);
	int max_sum = maxSubArraySum(a, n);
	
	cout << "Maximum contiguous sum is " << max_sum << endl;
	
	return 0; 
}

