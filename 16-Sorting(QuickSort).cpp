//16-Sorting(QuickSort)

#include <iostream>
using namespace std;

void swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int a[], int low, int high){
	int pivot = a[high]; //last element as pivot.
	int i = (low-1); //index of smaller element.
	
	//place smaller numbers before pivot, greater ones after pivot.
	for(int j = low; j <= high-1; j++){
		if(a[j] < pivot){
			i++;
			swap(&a[i], &a[j]);
		}
	}
	swap(&a[i+1], &a[high]); //place pivot before greater ones.
	
	return(i+1);
}

void quickSort(int a[], int low, int high){
	if(low < high){
		int pi = partition(a, low, high);
		quickSort(a, low, pi-1);
		quickSort(a, pi+1, high);
	}
}

void printArray(int a[], int n){
	int i;
	for(i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

int main(){
	int a[] = {10, 7, 8, 9, 1, 5};
	int n = sizeof(a)/sizeof(a[0]);
	cout << "Unsorted Array: ";
	printArray(a, n);
	
	quickSort(a, 0, n-1);
	cout << "Sorted Array: ";
	printArray(a, n);
	
	return 0;
}