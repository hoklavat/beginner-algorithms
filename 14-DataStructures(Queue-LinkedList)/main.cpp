//14- Data Structures (Queue - Linked List)
#include "Queue.h"
#include <iostream>
using std::cout;

int main(){
	Queue<int> queue;
	queue.enqueue(10);
	queue.enqueue(20);
	queue.enqueue(30);
	cout << queue.dequeue() << '\n';
	cout << queue.size() << '\n';
	cout << queue.dequeue() << '\n';
	cout << queue.dequeue() << '\n';
	cout << queue.size() << '\n';
	queue.enqueue(10);
	queue.enqueue(20);
	queue.enqueue(30);
	cout << queue.dequeue() << '\n';
	cout << queue.size() << '\n';	
	return 0;
}
