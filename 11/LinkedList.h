#pragma once

#include "List.h"
#include <memory>
#include <iostream>

template<class t_Data>
class LinkedList: public List<t_Data>{
	struct Node{
		t_Data data;
		std::unique_ptr<Node> nextNode;
		Node(const t_Data &_data): data(_data){}
	};	
	int sizeCounter = 0;	
	std::unique_ptr<Node> head;
	
public:
	LinkedList() = default;
	
	void insert(const t_Data &data) override{
		sizeCounter++;
		insertDataBeginning(data);
	}
	
	void remove(const t_Data &data) override{
		//empty
		if(!head)
			return;
		//first node
		if(head->data == data){
			auto newHead = std::move(head->nextNode);
			head = std::move(newHead);
			sizeCounter--;
			return;
		}
		//only one node and not equal
		if(!head->nextNode){
			std::cout << data << " is not found in a list.\n";
			return;
		}
		//middle search and remove
		Node *prev = head.get();
		Node *next = head->nextNode.get();
		while(next->data != data){
			prev = next;
			next = next->nextNode.get();
		}
		if(!next){
			std::cout << data << " is not found in a list.\n";
			return;
		}
		std::unique_ptr<Node> temp = std::move(next->nextNode);
		prev->nextNode = std::move(temp);
	}
	
	void traverseList() const override{
		Node *node = head.get();
		while(node){
			std::cout << node->data << ' ';
			node = node->nextNode.get();
		}
		std::cout << '\n';
	}
	
	int size() const override{
		return sizeCounter;
	}

private:
	void insertDataBeginning(const t_Data &data){
		std::unique_ptr<Node> newNode = std::make_unique<Node>(data);
		newNode->nextNode = std::move(head);
		head = std::move(newNode);		
	}
};