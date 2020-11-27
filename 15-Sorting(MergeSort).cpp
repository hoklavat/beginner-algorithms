//15-Sorting(MergeSort)

#include <iostream>
using namespace std;

void merge(int a[], int l, int m, int r){ //left, middle, right indexes.
	int n1 = m - l + 1; //count for left part.
	int n2 = r - m; //count for right part.
	int L[n1], R[n2]; //left array, right array.
	
	//copy left part.
	for(int i = 0; i < n1; i++)
		L[i] = a[l + i];
	
	//copy right part.
	for(int j = 0; j < n2; j++)
		R[j] = a[m + 1 + j];
	
	//merge parts while sorting.
	int i = 0;
	int j = 0;
	int k = l;
	while(i < n1 && j < n2){
		if(L[i] <= R[j]){
			a[k] = L[i];
			i++;
		}
		else{
			a[k] = R[j];
			j++;
		}
		k++;
	}
	
	//place remaining elements if there is any.
	while(i < n1){
		a[k] = L[i];
		i++;
		k++;
	}
	while(j < n2){
		a[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int a[], int l, int r){
	if(l >= r) return; //base case of recursion.
	
	int m = (l+r-1)/2; //middle index.
	mergeSort(a, l, m); //divide left part first.
	mergeSort(a, m+1, r);
	merge(a, l, m, r);
}

void printArray(int a[], int n){
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

int main(){
	int a[] = {12, 11, 13, 5, 6, 7};
	int n = sizeof(a)/sizeof(a[0]);

	cout << "Unsorted array: ";
	printArray(a, n);

	mergeSort(a, 0, n-1);
	cout << "Sorted array: ";
	printArray(a, n);
	
	return 0;
}