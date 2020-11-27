//17-Sorting(HeapSort)

#include <iostream>
using namespace std;

void swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}

void heapify(int a[], int n, int i){
	int largest = i; //initialize largest as root.
	int l = 2*i + 1; //left child.
	int r = 2*i + 2; //right child.

	if(l < n && a[l] > a[largest])
		largest = l;

	if(r < n && a[r] > a[largest])
		largest = r;

	if(largest != i){
		swap(a[i], a[largest]);
		heapify(a, n, largest);
	}
	
	//if(largest == i) return; base case of recursion.
}

void heapSort(int a[], int n){
	for(int i = n/2 - 1; i >= 0; i--)
		heapify(a, n, i);

	for(int i = n-1; i > 0; i--){
		swap(a[0], a[i]);
		heapify(a, i, 0);
	}
}

void printArray(int a[], int n){
	for(int i = 0; i < n; ++i)
		cout << a[i] << " ";
	cout << endl;
}

int main(){
	int a[] = {12, 11, 13, 5, 6, 7};
	int n = sizeof(a)/sizeof(a[0]);
	cout << "Unsorted Array: ";
	printArray(a, n);

	heapSort(a, n);
	cout << "Sorted Array: ";
	printArray(a, n);
}