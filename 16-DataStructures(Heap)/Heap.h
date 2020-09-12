#ifndef Heap_h
#define Heap_h

#include <vector>
using std::vector;

class Heap{
	vector<int> heap; //tree-like structure to one-dimensional array; parent node i -> left node 2i+1, right node 2i+2
	int heapSize = 0;
	constexpr static int CAPACITY = 10;
public:
	Heap();
	void insert(int item);
	int getMax() const;
	int poll();
	void heapsort();
private:
	void fixUp(int index);
	void fixDown(int index);
	bool isHeapFull() const;
};

#endif