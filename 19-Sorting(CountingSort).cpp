//18-Sorting(CountingSort)

#include <iostream>
#include <string.h>
using namespace std;

#define RANGE 255

void countSort(char a[]){
	char output[strlen(a)];
	int i;
	int count[RANGE + 1];
	memset(count, 0, sizeof(count));

	for(i = 0; a[i]; i++)
		count[a[i]]++;

	for(i = 1; i <= RANGE; i++)
		count[i] += count[i-1];

	for(i = 0; a[i]; i++){ //when a[i] not null.
		output[count[a[i]]-1] = a[i];
		count[a[i]]--;
	}

	/*
	//More Stable Algorithm
	for(i = sizeof(a)-1; i>=0; --i)
	{
		output[count[a[i]]-1] = a[i];
		--count[a[i]];
	}
	*/

	for(i = 0; a[i]; ++i)
		a[i] = output[i];
}

int main(){
	char a[] = "geeksforgeeks";
	cout << "Unsorted Character Array: " << a << endl;

	countSort(a);
	cout << "Sorted Character Array: " << a << endl;
	
	return 0;
}