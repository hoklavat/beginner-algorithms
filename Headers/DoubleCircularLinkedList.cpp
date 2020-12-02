#ifndef DOUBLE_CIRCULAR_LINKED_LIST
#define DOUBLE_CIRCULAR_LINKED_LIST

#include <iostream>
using namespace std;

#include "DoubleNode.cpp"

class DoubleCircularLinkedList{
private:
	DoubleNode *head; //first node in linked list.
	DoubleNode *tail; //last node in linked list.
	int size; //number of elements.

public:
	DoubleCircularLinkedList(): DoubleCircularLinkedList(0){}

	DoubleCircularLinkedList(int v){
		DoubleNode *node;
		node = new DoubleNode(v);			
		head = new DoubleNode();
		tail = new DoubleNode();
		node->setPrev(node);
		node->setNext(node);	
		head = node;
		tail = node;
		size = 1;
	}
	
	~DoubleCircularLinkedList(){
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
			node->setPrev(tail);
			head->setPrev(node);
			tail->setNext(node);
			head = node;
		}
		else if(l >= size){ //insert at last position.
			node->setNext(head);
			node->setPrev(tail);
			head->setPrev(node);
			tail->setNext(node);
			tail = node;
		}
		else{ //insert at middleware position.
			DoubleNode *temp = head;
			int index = 0;
			while(index < l-1){
				temp = temp->getNext();
				index++;
			}
			node->setPrev(temp);
			node->setNext(temp->getNext());
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
				head->setNext(nullptr);
				tail->setNext(nullptr);
				head = nullptr;
				tail = nullptr;
				setSize(getSize()-1);
				return;
			}
			head = head->getNext();
			head->setPrev(nullptr);
			tail->setNext(head);
			setSize(getSize()-1);
		}
		else if(l >= getSize()-1){ //delete last node.
			if(getSize() == 1){
				head->setNext(nullptr);
				head->setPrev(nullptr);
				tail = nullptr;
				head = nullptr;
				setSize(getSize()-1);
				return;
			}
			tail = tail->getPrev();
			tail->setNext(head);
			head->setPrev(tail);
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
		if(tail == nullptr){
			cout << "Linked list already deleted." << endl;
			return;
		}
		else{
			head->setPrev(nullptr);
			tail->setNext(nullptr);
			head = nullptr;
			tail = nullptr;
			cout << "Linked list deleted." << endl;
		}
	}	
};

#endif