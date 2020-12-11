//30-DataStructures(Queue)

#include <iostream>
using namespace std;

#include "Headers\Queue.cpp"

void Demo_LinearArrayQueue(){
	LinearArrayQueue q{10};
	
	cout << "Is queue empty: " << q.isEmpty() << endl;
	
	cout << "Enqueue in progress." << endl;
	for(int i = 0; i < 10; i++)
		q.enqueue(i*10);		
	
	q.print();
	
	cout << "Is queue full: " << q.isFull() << endl;
	
	cout << "Dequeue first 3 elements." << endl;
	for(int i = 0; i < 3; i++)
		q.dequeue();
	
	q.print();
	
	cout << "Front element: " << q.getFront() << endl;
	cout << "Rear element: " << q.getRear() << endl;	
	
	q.deleteQueue();
	q.enqueue(100);
}

void Demo_CircularArrayQueue(){
	CircularArrayQueue q{10};
	
	q.print();
	cout << "Is queue empty? " << q.isEmpty() << endl;
	for(int i = 0; i < 10; i++)
		q.enqueue(i*10);
	
	q.print();
	cout << "Is queue full? " << q.isFull() << endl;
	
	cout << "Dequeue: ";
	for(int i = 0; i < 5; i++)
		cout << q.dequeue() << " ";
	cout << endl;
	
	q.print();
	
	
	for(int i = 0; i < 5; i++)
		q.enqueue(i);
		
	q.print();
	
	q.deleteQueue();
	
}

void Demo_LinearLinkedListQueue(){
	LinearLinkedListQueue q;
	
	for(int i = 0; i < 10; i++)
		q.enqueue(i*10);	
	q.print();
	
	for(int i = 0; i < 5; i++)
		q.dequeue();
	q.print();
		
	for(int i = 0; i < 5; i++)
		q.enqueue(i);		
	q.print();
	
	cout << "First element: " << q.peek() << endl;
	cout << "Dequeue: " << q.dequeue() << endl;
	
	q.deleteQueue();
}

void Demo_CircularLinkedListQueue(){
	CircularLinkedListQueue q;
	
	for(int i = 0; i < 10; i++)
		q.enqueue(i*10);		
	q.print();
	
	for(int i = 0; i < 5; i++)
		q.dequeue();
	q.print();
	
	for(int i = 0; i < 5; i++)
		q.enqueue(i);		
	q.print();
	
	cout << "First element: " << q.peek() << endl;
	cout << "Dequeue: " << q.dequeue() << endl;
	
	q.deleteQueue();
}

int main(){
	//Demo_LinearArrayQueue();
	//Demo_CircularArrayQueue();
	//Demo_LinearLinkedListQueue();
	Demo_CircularLinkedListQueue();
	
	return 0;
}