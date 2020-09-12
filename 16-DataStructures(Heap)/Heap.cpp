#include "Heap.h"
#include <iostream>
using std::cout;

Heap::Heap(){
	heap.resize(CAPACITY);
}

void Heap::insert(int item){
	if(isHeapFull())
		throw std::overflow_error("Heap is full...");
	heap[heapSize] = item;
	++heapSize;
	fixUp(heapSize - 1);	
}

int Heap::getMax() const{
	if(heapSize == 0)
		throw std::length_error("Heap is empty...");
	return heap[0];
}

int Heap::poll(){
	int max = getMax();
	std::swap(heap[0], heap[heapSize - 1]); //replace removed root node with last node
	heapSize--;
	fixDown(0);
	return max;
}

void Heap::heapsort(){
	int size = heapSize;
	for(int i = 0; i < size; i++){
		int max = poll();
		cout << max << ' ';		
	}
	cout << '\n';
}

void Heap::fixUp(int index){
	int parentIndex = (index - 1) / 2;
	if(index > 0 && heap[index] > heap[parentIndex]){ //Max Heap: check whether parent is greater than child, if not swap.
		std::swap(heap[index], heap[parentIndex]);
		fixUp(parentIndex); //from last node to root.
	}
}

void Heap::fixDown(int index){
	int indexLeft = 2 * index + 1 ;
	int indexRight = 2 * index + 2;
	int indexLargest = index;
	if(indexLeft < heapSize && heap[indexLeft] > heap[index]) //left-child largest?
		indexLargest = indexLeft;
	if(indexRight < heapSize && heap[indexRight] > heap[indexLargest]) //right-child largest?
		indexLargest = indexRight;
	if(index != indexLargest){
		std::swap(heap[index], heap[indexLargest]);
		fixDown(indexLargest);
	}
}

bool Heap::isHeapFull() const{
	return CAPACITY == heapSize;
}
	