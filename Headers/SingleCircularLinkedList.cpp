#ifndef SINGLE_CIRCULAR_LINKED_LIST
#define SINGLE_CIRCULAR_LINKED_LIST

#include <iostream>
using namespace std;

#include "SingleNode.cpp"

class SingleCircularLinkedList{
private:
	SingleNode *head;
	SingleNode *tail;
	int size;

public:
	SingleCircularLinkedList(): SingleCircularLinkedList(0){}

	SingleCircularLinkedList(int v){
		SingleNode *node;
		node = new SingleNode(v);
		head = new SingleNode();
		tail = new SingleNode();
		head = node;
		tail = node;
		size = 1;
	}
	
	~SingleCircularLinkedList(){
		delete head;
		delete tail;
		cout << "Link list destructed." << endl;
	}
	
	void setHead(SingleNode *n){head = n;}
	SingleNode *getHead(){return head;}
	
	void setTail(SingleNode *n){tail = n;}
	SingleNode *getTail(){return tail;}
	
	void setSize(int s){size = s;}
	int getSize(){return size;}
	
	bool exists(){return head != nullptr;}
	
	//insert.
	void insert(int v, int l){
		SingleNode *node = new SingleNode(v);
		if(!exists()){
			cout << "ERROR: linked list doesn't exist." << endl;
			return;
		}
		else if(l == 0){ //insert at first position. 
			node->setNext(head);
			head = node;
			tail->setNext(node);
		}
		else if(l >= size){ //insert at last position.
			tail->setNext(node);
			tail = node;
			tail->setNext(head);
		}
		else{ //insert at middleware position.
			SingleNode *temp = head;
			int index = 0;
			while(index < l-1){
				temp = temp->getNext();
				index++;
			}
			node->setNext(temp->getNext());
			temp->setNext(node);
		}
		setSize(getSize()+1);
	}
	
	//traverse.
	void traverse(){
		if(!exists()){
			cout << "ERROR: linked list doesn't exist." << endl;
			return;
		}
		cout << "Contents of List: ";
		SingleNode *temp;
		temp = new SingleNode();
		temp = head;
		for(int i = 0; i < getSize(); i++){
			cout << temp->getValue() << " ";
			temp = temp->getNext();
		}
		cout << endl;
	}	
	
	//search.
	int search(int v){
		if(!exists()){
			cout << "ERROR: linked list doesn't exist." << endl;
			return -1;
		}
		SingleNode *temp;
		temp = new SingleNode();
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
			head = head->getNext();
			tail->setNext(head);
			setSize(getSize()-1);
			if(getSize() == 0) tail = nullptr;
		}
		else if(l >= getSize()){ //delete last node.
			SingleNode *temp;
			temp = new SingleNode();
			temp = head;
			for(int i = 0; i < getSize()-1; i++){
				temp = temp->getNext();
			}
			if(temp == head){
				tail = nullptr;
				head = nullptr;
				setSize(getSize()-1);
				return;
			}
			temp->setNext(head);
			tail = temp;
			setSize(getSize()-1);
		}
		else{ //delete middleware node.
			SingleNode *temp;
			temp = new SingleNode();
			temp = head;
			for(int i = 0; i < l-1; i++){
				temp = temp->getNext();
			}
			temp->setNext(temp->getNext()->getNext());
			setSize(getSize()-1);
		}
	}
	
	//delete linked list.
	void deleteList(){
		head = nullptr;
		if(tail == nullptr){
			cout << "Link list already deleted." << endl;
			return;			
		}
		else{
			tail->setNext(nullptr);
			tail = nullptr;
		}
		cout << "Link list deleted." << endl;
	}	
};

#endif