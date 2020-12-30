//14-Sorting(BucketSort)

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void bucketSort(float a[], int n){ //elements are floating point values between [0, 1).
	vector<float> b[n]; //vector of bucket array. each bucket can take n elements.

	for(int i = 0; i < n; i++){
		int bi = n*a[i]; //indexes for buckets are obtained by casting elements into integers between [0, n).
		b[bi].push_back(a[i]); //some of buckets have elements, some doesn't. bucket with lower index contains lower numbers.
	}

	for(int i = 0; i < n; i++)
		sort(b[i].begin(), b[i].end()); //sort elements in each bucket.

	int index = 0;
	for(int i = 0; i < n; i++)
		for (int j = 0; j < b[i].size(); j++) 
			a[index++] = b[i][j]; //concatenate elements in buckets respectively.
}

void printArray(float a[], int n){
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

int main(){
	float a[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
	int n = sizeof(a)/sizeof(a[0]);
	cout << "Unsorted array: ";
	printArray(a, n);
	
	bucketSort(a, n);
	cout << "Sorted array: ";
	printArray(a, n);

	return 0;
}