//20-Sorting(ShellSort)

#include <iostream>
using namespace std;

int shellSort(int a[], int n){
	for(int gap = n/2; gap > 0; gap /= 2){
		for(int i = gap; i < n; i += 1){
			int temp = a[i];
			int j;
			for(j = i; j >= gap && a[j-gap] > temp; j -= gap)
				a[j] = a[j-gap];
			a[j] = temp;
		}
	}
	return 0;
}

void printArray(int a[], int n){
	for(int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

int main(){
	int a[] = {12, 34, 54, 2, 3};
	int n = sizeof(a)/sizeof(a[0]);

	cout << "Unsorted Array: ";
	printArray(a, n);

	shellSort(a, n);
	cout << "Sorted Array: ";
	printArray(a, n);

	return 0;
}