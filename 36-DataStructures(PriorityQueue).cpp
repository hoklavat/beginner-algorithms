//36-DataStructures(PriorityQueue)

#include <iostream>
#include "Headers/PriorityQueue.cpp"
using namespace std;

int main(){
	PriorityQueue queue;
  
	for(int i = 9; i > 0; i--)
		queue.enqueue(i*10, i);
	
	queue.print();
	cout << "Size of Priority Queue: " << queue.size() << endl;
	cout << "Element with Minimum Priority: " << queue.peek() << ":" << queue.peekPriority()  << endl;	
	cout << "Dequeue: " << queue.dequeue() << endl;
	cout << "Element with Minimum Priority: " << queue.peek() << ":" << queue.peekPriority()  << endl;	
	cout << "Is queue empty: " << boolalpha << queue.isEmpty() << endl;
	queue.print();
	queue.clear();
	cout << "Is queue empty: " << boolalpha << queue.isEmpty() << endl;
	
	return 0;
}