//12-Sorting(SelectionSort)
//find minimum then swap with previous minimum.

#include <iostream>
using namespace std;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selectionSort(int a[], int n){
	int min_idx;
	for(int i = 0; i < n-1; i++){
		min_idx = i;
		for(int j = i+1; j < n; j++)
			if(a[j] < a[min_idx]) min_idx = j;
		swap(&a[min_idx], &a[i]);
	}
}

void printArray(int a[], int n){
	int i;
	for(int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

int main(){
	int a[] = {64, 25, 12, 22, 11};
	int n = sizeof(a)/sizeof(a[0]);
	
	cout << "Unsorted array: ";
	printArray(a, n);
	
	selectionSort(a, n);
	cout << "Sorted array: ";
	printArray(a, n);
	
	return 0;
}