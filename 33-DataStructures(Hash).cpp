//33-DataStructures(Hash)

#include <iostream> 
using namespace std;

#include "Headers/Hash.cpp"

int main(){ 
	int a[] = {15, 11, 27, 8, 12}; //values for hash function.
	int n = sizeof(a)/sizeof(a[0]); //number of elements in array.	
	Hash h(7); //7 is number of buckets.
	
	for (int i = 0; i < n; i++)	
		h.insertItem(a[i]);
	
	h.deleteItem(12);
	h.displayHash(); //multiple values in same bucket (key) is possible based on hash function. collision.
	
	return 0; 
} 