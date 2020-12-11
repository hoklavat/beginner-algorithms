#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

#include <iostream>
using namespace std;

struct Node{
	int data;
	int priority;
	Node* next;
	Node* prev;	
};

class PriorityQueue{
private:
	Node *first;
	Node *last;
	
public:

	PriorityQueue(){
		first = last = NULL;
	}
	
	void enqueue(int v, int p){
		Node *add = new Node();
		add->data = v;
		add->priority = p;
		
		//if minimum it is new first.
		if(first == NULL || p < first->priority){
			add->next = first;
			first = add;
		}
		
		//if not minimum insert after nearest smaller priority. 
		else{
			Node *temp = first;
			while(temp->next != NULL && temp->priority < p){
				temp = temp->next;
			}
			add->next = temp->next;
			temp->next = add;
		}
	}
	
	int dequeue(){
		Node *temp;
		temp = first;
		first = first->next;
		int v = temp->data;
		delete temp;
		return v;
	}

	int peek(){
		return first->data;
	}
	
	int peekPriority(){
		return first->priority;
	}

	void clear(){
		while(first != NULL){
			Node *temp = first;
			first = first->next;
			delete temp;
		}
		cout << "Priority queue is cleared." << endl;
	}

	void print(){
		Node *temp = first;
		cout << "Contents of Priority Queue: ";
		while(temp != NULL){
			cout << temp->data << ":" << temp-> priority << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	int size(){
		if(first == NULL)
			return 0;
		else if(first == last)
			return 1;
			
		int count = 0;
		Node *temp = first;
		while(temp != NULL){
			temp = temp->next;
			count++;
		}
		
		return count;
	}
	
	bool isEmpty(){
		if(first == NULL)
			return true;
		else
			return false;
	}
};

#endif