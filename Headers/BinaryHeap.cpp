#ifndef BINARY_HEAP
#define BINARY_HEAP

#include<iostream>
#include<climits>
using namespace std;

class MinHeap{
private:
	int *data;
	int capacity;
	int size;
	
public:
	MinHeap(int c){
		data = new int[c];
		size = 0;
		capacity = c;		
	}
	
	void swap(int *x, int *y){
		int temp = *x;
		*x = *y;
		*y = temp;
	}	
	
	//index of left child.
	int left(int i){ 
		return (2*i + 1);
	}
	
	//index of right child.
	int right(int i){
		return (2*i + 2);
	}
	
	//index of parent node.
	int parent(int i){
		return (i-1)/2;
	}
	
	//return root key.
	int getMin(){
		return data[0];
	}
	
	// to heapify a subtree with the root at given index
	void MinHeapify(int i){
		int l = left(i);
		int r = right(i);
		int min = i; //assume minimum is current one.
		
		//left child is new minimum if current one is not.
		if (l < size && data[l] < data[i])
			min = l;
		
		//right child is new minimum if current one or left child is not.
		if (r < size && data[r] < data[min])
			min = r;
		
		//if minimum is not current one, swap with minimum child.
		if (min != i){
			swap(&data[i], &data[min]);
			MinHeapify(min); //recursively repeat process until current one is minimum.
		}
	}
	
	int extractMin(){
		if (size <= 0)
			return INT_MAX;
			
		if (size == 1){
			size--;
			return data[0];
		}

		int root = data[0];
		data[0] = data[size-1]; //new minimum is assumed to be the last key.
		size--;
		MinHeapify(0); //traverse until minimum is placed in root node.
	
		return root; //return minimum
	}
	
	//decrease value, replace parent if less.
	void decreaseKey(int i, int v){
 		data[i] = v;
		while(i != 0 && data[parent(i)] > data[i]){ //if parent node is greater than current one.
			swap(&data[i], &data[parent(i)]);
			i = parent(i); //new current one is parent.
		}
	}
	
	//delete current one.
	void deleteKey(int i){
		decreaseKey(i, INT_MIN); //replace with lowest integer possible.
		extractMin(); //remove root node which contains INT_MIN.
	}
	
	//insert new key.
	void insertKey(int k){
		if (size == capacity){
			cout << "ERROR: overflow. cannot insert new key.";
			return;
		}
	
		size++;
		int i = size-1;
		data[i] = k;
		
		//same process as decreaseKey. place minimum at root.
		while(i != 0 && data[parent(i)] > data[i]){
			swap(&data[i], &data[parent(i)]);
			i = parent(i);
		}
	}
};

#endif