#ifndef DOUBLE_LINKED_LIST
#define DOUBLE_LINKED_LIST

#include <iostream>
using namespace std;

#include "DoubleNode.cpp"

class DoubleLinkedList{
private:
	DoubleNode *head; //first node in linked list.
	DoubleNode *tail; //last node in linked list.
	int size; //number of elements. size starts from 1. position starts from 0. avoid confusion.

public:
	DoubleLinkedList(): DoubleLinkedList(0){}

	DoubleLinkedList(int v){
		DoubleNode *node;
		node = new DoubleNode(v);			
		head = new DoubleNode();
		tail = new DoubleNode();
		node->setPrev(nullptr);
		node->setNext(nullptr);	
		head = node;
		tail = node;
		size = 1;
	}
	
	~DoubleLinkedList(){
		delete head;
		delete tail;
		cout << "Link list destructed." << endl;
	}
	
	void setHead(DoubleNode *n){head = n;}
	DoubleNode *getHead(){return head;}
	
	void setTail(DoubleNode *n){tail = n;}
	DoubleNode *getTail(){return tail;}
	
	void setSize(int s){size = s;}
	int getSize(){return size;}
	
	bool exists(){return head != nullptr;}
	
	//insert.
	void insert(int v, int l){
		DoubleNode *node = new DoubleNode(v);
		if(!exists()){
			cout << "ERROR: linked list doesn't exist." << endl;
			return;
		}
		else if(l == 0){ //insert at first position. 
			node->setNext(head);
			node->setPrev(nullptr);
			head->setPrev(node); //push previous head forward.
			head = node; //new head.
		}
		else if(l >= size){ //insert at last position.
			node->setNext(nullptr);			
			node->setPrev(tail);
			tail->setNext(node); //append new tail after previous tail.
			tail = node; //new tail.
		}
		else{ //insert at middleware position.
			DoubleNode *temp = head;
			int index = 0;
			while(index < l-1){
				temp = temp->getNext(); //iterate until reaching preciding node.
				index++;
			}
			DoubleNode *tempNext = temp->getNext();
			node->setPrev(temp);
			node->setNext(tempNext);
			temp->setNext(node);
			node->getNext()->setPrev(node);
		}
		setSize(getSize()+1);
	}
	
	//traverse.
	void traverse(){
		if(!exists()){
			cout << "ERROR: linked list doesn't exist." << endl;
			return;
		}
		cout << "Contents of List(" << getSize() << "): ";
		DoubleNode *temp;
		temp = new DoubleNode();
		temp = head;
		for(int i = 0; i < getSize(); i++){
			cout << temp->getValue() << " ";
			temp = temp->getNext();
		}
		cout << endl;
	}
	
	//reverse traverse.
	void traverseReverse(){
		if(!exists()){
			cout << "ERROR: linked list doesn't exist." << endl;
			return;
		}
		cout << "Reverse Contents of List(" << getSize() << "): ";
		DoubleNode *temp;
		temp = new DoubleNode();
		temp = tail;
		for(int i = 0; i < getSize(); i++){
			cout << temp->getValue() << " ";
			temp = temp->getPrev();
		}
		cout << endl;
	}
	
	
	//search.
	int search(int v){
		if(!exists()){
			cout << "ERROR: linked list doesn't exist." << endl;
			return -1;
		}
		DoubleNode *temp;
		temp = new DoubleNode();
		temp = head;
		for(int i = 0; i < getSize(); i++){
			if(temp->getValue() == v){
				return i;
			}
			temp = temp->getNext();
		}
		return -1;
	}
	
	//delete node.
	void deleteNode(int l){
		if(!exists()){
			cout << "ERROR: linked list doesn't exist." << endl;
			return;
		}
		else if(l == 0){ //delete first node.
			if(getSize() == 1){
				head = nullptr;
				tail = nullptr;
				setSize(getSize()-1);
				return;
			}
			head = head->getNext();
			head->setPrev(nullptr);
			setSize(getSize()-1);
		}
		else if(l >= getSize()-1){ //delete last node.
		
			DoubleNode *temp;
			temp = new DoubleNode();
			temp = tail->getPrev();
			if(temp == head){
				tail = nullptr;
				head = nullptr;
				setSize(getSize()-1);
				return;
			}
			temp->setNext(nullptr);
			tail = temp;
			setSize(getSize()-1);
		}
		else{ //delete middleware node.
			DoubleNode *temp;
			temp = new DoubleNode();
			temp = head;
			for(int i = 0; i < l-1; i++){
				temp = temp->getNext();
			}
			temp->setNext(temp->getNext()->getNext());
			temp->getNext()->setPrev(temp);
			setSize(getSize()-1);
		}
	}
	
	//delete linked list.
	void deleteList(){
		DoubleNode *temp;
		temp = new DoubleNode();
		temp = head;
		for(int i = 0; i < size; i++){
			temp->setPrev(nullptr);
			temp = temp->getNext();
		}
		
		head = nullptr;
		tail = nullptr;
		cout << "Link list deleted." << endl;
	}	
};

#endif