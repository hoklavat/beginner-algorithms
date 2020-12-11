//19-Sorting(RadixSort)

#include <iostream>
using namespace std;

int getMax(int a[], int n){
	int max = a[0];
	for(int i = 1; i < n; i++)
		if(a[i] > max)
			max = a[i];
	return max;
}

void countSort(int a[], int n, int exp){
	int output[n];
	int i, count[10] = {0};

	for(i = 0; i < n; i++)
		count[(a[i] / exp) % 10]++; //digit value.

	for(i = 1; i < 10; i++)
		count[i] += count[i-1];

	for(i = n-1; i >= 0; i--) {
		output[count[(a[i] / exp) % 10] - 1] = a[i];
		count[(a[i] / exp) % 10]--;
	}

	for(i = 0; i < n; i++)
		a[i] = output[i];
}

void radixsort(int a[], int n){
	int m = getMax(a, n);

	for(int exp = 1; m/exp > 0; exp *= 10) //exp = 10^i. i is digit number.
		countSort(a, n, exp);
}

void printArray(int a[], int n){
	for(int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

int main(){
	int a[] = {170, 45, 75, 90, 802, 24, 2, 66};
	int n = sizeof(a)/sizeof(a[0]);
	cout << "Unsorted Array: ";
	printArray(a, n);
	
	cout << "Sorted Array: ";
	radixsort(a, n);
	printArray(a, n);
	
	return 0;
}