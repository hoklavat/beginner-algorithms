//Search(ClosestSum)
//Task: find pair in sorted array whose sum is closest to x.
//Time Complexity: O(n)

#include <iostream>
using namespace std;

void find(int A[], int n, int x){
	int res_l, res_r, l = 0, r = n-1, d = INT32_MAX;
	while(r > l){
		if(abs(A[l]+A[r]-x) < d){
			res_l = l;
			res_r = r;
			d = abs(A[l]+A[r]-x);
		}
		if(A[l]+A[r] > x) r--;
		else l++;
	}
	cout <<"Closest pair is " << A[res_l] << " and " << A[res_r] << endl;
}

int main(){
	int A[] = {10, 22, 28, 29, 30, 40};
	int x = 54;
	int n = sizeof(A)/sizeof(A[0]);	
	find(A, n, x);
	return 0;
}



