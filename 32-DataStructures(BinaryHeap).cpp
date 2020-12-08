//32-DataStructures(BinaryHeap)
//Minimum Heap: minimum at root.
//Maximum Heap: maximum at root.

#include "Headers/BinaryHeap.cpp"

int main() { 
    MinHeap h(10); 
    h.insertKey(6);
	h.insertKey(9);
	h.insertKey(1);
	h.insertKey(7);
	h.insertKey(4);
	h.insertKey(2);
	h.insertKey(10);
	h.insertKey(8);
	h.insertKey(3);
	
	cout << "Root: " << h.getMin() << endl;
	h.extractMin();
	cout << "Root after Extraction: " << h.getMin() << endl;
	
	h.insertKey(0);
	cout << "Root after Insertion: " << h.getMin() << endl;
	
	h.decreaseKey(3, -5);
	cout << "Root after Replacement: " << h.getMin() << endl << endl;
	
    return 0; 
} 