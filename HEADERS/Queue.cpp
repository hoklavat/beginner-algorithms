#ifndef QUEUE
#define QUEUE

#include <iostream>
using namespace std;

#include "SingleLinkedList.cpp"

class LinearArrayQueue{
private:
	int *data;
	int front; //index of first element inserted. dequeue index.
	int rear; //index of last element inserted. enqueue index.
	int size; //number of elements inserted.
	int capacity; //fixed capacity for array.
	
public:
	LinearArrayQueue(): LinearArrayQueue(10){}

	LinearArrayQueue(int s){
		data = new int[capacity];
		front = 0;
		rear = capacity-1;
		size = 0;
		capacity = s;
	}
	
	~LinearArrayQueue(){
		cout << "Queue is destructed." << endl;
	}
	
	//underflow.
	bool isEmpty(){
		return size == 0;
	}
	
	//overflow.
	bool isFull(){
		return size == capacity;
	}
	
	void enqueue(int v){
		if(isFull()){
			cout << "ERROR: queue is full. cannot add new value." << endl;
			return;
		}
		if(data == nullptr){
			cout << "ERROR: queue deleted. cannot add new value." << endl;
			return;
		}
		rear = (rear+1)%capacity;
		data[rear] = v;
		size++;
	}
	
	int dequeue(){
		if(isEmpty()){
			cout << "ERROR: queue is empty. cannot fetch value." << endl;
			return -1;
		}
		int v = data[front];
		data[front] = 0;
		front = (front+1)%capacity;
		size--;
		return v;
	}
	
	int getFront(){
		if(isEmpty()){
			cout << "ERROR: queue is empty. cannot get value." << endl;
			return -1;
		}
		return data[front];
	}
	
	int getRear(){
		if(isEmpty()){
			cout << "ERROR: queue is empty. cannot get value." << endl;
			return -1;
		}
		return data[rear];
	}
	
	void deleteQueue(){
		data = nullptr;
		size = 0;
		cout << "Queue is deleted." << endl;
	}
	
	void print(){
		if(isEmpty()){
			cout << "ERROR: queue is empty. cannot print contents." << endl;
			return;
		}
		cout << "Contents of Queue: ";
		for(int i = 0; i < capacity; i++){
			cout << data[i] << " ";
		}
		cout << endl;
	}
};

//ring buffer.
class CircularArrayQueue{
private:
	int *data;
	int rear;
	int front;
	int size;

public:
	CircularArrayQueue(): CircularArrayQueue(10){}
		
	CircularArrayQueue(int s){
		size = s;
		data = new int[size];
		rear = -1;
		front = -1;
	}
	
	~CircularArrayQueue(){
		cout << "Queue is destructed." << endl;
	}
	
	bool isEmpty(){
		if(rear == -1)
			return true;
		return false;
	}
	
	bool isFull(){
		if((front == 0 && rear == size-1) || (rear == (front-1)%(size-1)))
			return true;
		else
			return false;
	}
	
	void enqueue(int v){
		if(data == nullptr){
			cout << "ERROR: queue not exists. cannot add new value." << endl;
			return;
		}
		else if(isFull()){
			cout << "ERROR: queue is full. cannot add new value." << endl;
			return;
		}
		else if(front == -1){
			front = 0;
			rear = 0;
			data[rear] = v;
		}
		else if(rear == size-1 && front != 0){
			rear = 0;
			data[rear] = v;
		}
		else{
			rear++;
			data[rear] = v;
		}
	}
	
	int dequeue(){
		if(isEmpty()){
			cout << "ERROR: queue is empty. cannot fetch value." << endl;
			return -1;
		}
		else{
			int v = data[front];
			data[front] = -1;
			if(front == rear)
				front = rear = -1;
			else if(front == size-1)
				front = 0;
			else
				front++;
			return v;
		}
	}
	
	int peek(){
		if(isEmpty()){
			cout << "ERROR: queue is empty. cannot get value." << endl;
			return -1;
		}
		return data[front];
	}
	
	void deleteQueue(){
		data = nullptr;
		cout << "Queue is deleted." << endl;
	}
	
	void print(){		
		cout << "Contents of Queue: ";
		if(isEmpty()){
			cout << endl;
			return;
		}
		if(rear >= front){
			for(int i = front; i <= rear; i++)
				cout << data[i] << " ";			
		}
		else{
			for(int i = front; i < size; i++)
				cout << data[i] << " ";
			for(int i = 0; i <= rear; i++)
				cout << data[i] << " ";
		}		
		cout << endl;
	}
};

class LinearLinkedListQueue{
private:
	SingleLinkedList *data;
	
public:
	LinearLinkedListQueue(){
		data = nullptr;
	}
	
	~LinearLinkedListQueue(){
		cout << "Queue is destructed." << endl;
	}
	
	bool isEmpty(){
		if(data->getHead() == nullptr)
			return true;
		else
			return false;
	}
	
	void enqueue(int v){
		if(data == nullptr){
			data = new SingleLinkedList(v);
			return;
		}
		else{
			data->insert(v, data->getSize());
		}
	}
	
	int dequeue(){
		int v = -1;
		if(isEmpty()){
			cout << "ERROR: queue is empty. cannot fetch value." << endl;
			return -1;
		}
		else{
			v = data->getHead()->getValue();
			data->deleteNode(0);
		}
		return v;
	}
	
	int peek(){
		if(isEmpty()){
			cout << "ERROR: queue is empty. cannot get value." << endl;
			return -1;
		}
		return data->getHead()->getValue();
	}
	
	int deleteQueue(){
		data = nullptr;
		cout << "Queue is deleted." << endl;
	}
	
	void print(){
		data->traverse();
	}
};

class CircularLinkedListQueue{
private:
	SingleLinkedList *data;
	
public:
	CircularLinkedListQueue(){
		data = nullptr;
	}
	
	~CircularLinkedListQueue(){
		cout << "Queue is destructed." << endl;
	}
	
	bool isEmpty(){
		if(data->getHead() == nullptr)
			return true;
		else
			return false;
	}
	
	void enqueue(int v){
		if(data == nullptr){
			data = new SingleLinkedList(v);
			return;
		}
		else{
			data->insert(v, data->getSize());
		}
	}
	
	int dequeue(){
		int v = -1;
		if(isEmpty()){
			cout << "ERROR: queue is empty. cannot fetch value." << endl;
			return -1;
		}
		else if(data->getHead() == data->getTail()){
			v = data->getHead()->getValue();
			data->deleteNode(0);
		}
		else{
			v = data->getHead()->getValue();
			data->setHead(data->getHead()->getNext());
			data->getTail()->setNext(data->getHead());
			data->setSize(data->getSize()-1);
		}
		return v;
	}
	
	int peek(){
		if(isEmpty()){
			cout << "ERROR: queue is empty. cannot get value." << endl;
			return -1;
		}
		return data->getHead()->getValue();
	}
	
	int deleteQueue(){
		data = nullptr;
		cout << "Queue is deleted." << endl;
	}
	
	void print(){
		data->traverse();
	}
};

#endif