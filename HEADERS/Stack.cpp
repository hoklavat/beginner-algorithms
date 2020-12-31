#ifndef STACK
#define STACK

#include <iostream>
using namespace std;

#include "Headers/SingleLinkedList.cpp"

//stack implemented with array.
class StackArray{
private:
	int *data;
	int top;
	int size;
	
public:
	StackArray(): StackArray(10){};
	
	StackArray(unsigned int s){
		data = new int[s];
		size = s; //total capacity.
		top = -1; //increment after each push. decrement after each pop.
	}
	
	bool isFull(){
		if(top == size - 1){
			return true;
		}
		return false;
	}
	
	bool isEmpty(){
		if(top == -1){
			return true;
		}
		return false;
	}
	
	int getSize(){
		return size;
	}
	
	void push(int v){
		if(isFull()){
			cout << "Stack is full. Unable to push data." << endl;
			return;			
		}
		data[top+1] = v;
		top++;
	}
	
	int pop(){
		if(isEmpty()){
			cout << "Stack is empty. Unable to pop data." << endl;
			return -1;
		}
		return data[top--];
	}
	
	int getTop(){
		if(isEmpty()){
			cout << "Stack is empty." << endl;
			return -1;
		}
		return data[top];
	}
	
	void deleteStack(){
		delete data;
		cout << "Stack is deleted." << endl;
	}
};

//stack implemented with linked list.
class StackList{
private:
	SingleLinkedList *data;
	
public:
	StackList(){
		data = new SingleLinkedList();
	}
	
	bool isEmpty(){
		if(data->getHead() == nullptr){
			return true;
		}
		return false;
	}
	
	int getSize(){
		return data->getSize();
	}
	
	void push(int v){
		if(data->getHead() == nullptr){
			data = new SingleLinkedList();
		}
		data->insert(v, 0);
	}
	
	int pop(){
		int v;
		if(isEmpty()){
			cout << "Stack is empty. Unable to pop data." << endl;
			return -1;
		}
		v = data->getHead()->getValue();
		data->deleteNode(0);
		return v;		
	}
	
	int getTop(){
		if(isEmpty()){
			cout << "Stack is empty. No data available." << endl;
		}
		return data->getHead()->getValue();
	}
	
	void deleteStack(){
		data->setHead(nullptr);
		cout << "Stack is deleted." << endl;
	}
};

#endif