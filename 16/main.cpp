//16- Data Structures (Heap)
#include <iostream>
#include "Heap.h"

int main(){
	 Heap heap{};
	 heap.insert(10);
	 heap.insert(8);
	 heap.insert(12);
	 heap.insert(20);
	 heap.insert(-2);
	 heap.insert(0);
	 heap.insert(1);
	 heap.insert(321);
	 heap.heapsort();
	return 0;
}
