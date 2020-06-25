#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include "Tree.h"
#include <memory>
#include <iostream>
#include <exception>

class EmptyTreeException: std::exception{
public:
	EmptyTreeException(){};
	const char *what() const noexcept override{
		return "BinarySearchTree is empty()";
	}
};

template <typename t_Data>
class BinarySearchTree: public Tree<t_Data>{
	struct Node{
		t_Data data;
		std::unique_ptr<Node> left;
		std::unique_ptr<Node> right;
		Node(const t_Data &_data): data(_data){}
	};
	std::unique_ptr<Node> root;
public:
	void insert(const t_Data &data) override{
		if(root){
			insertNode(data, root.get());
		}
		else{
			root = std::make_unique<Node>(data);
		}
	}
	
	void traversal() const override{
		if(!root)
			return;
		inOrderTraversal(root.get());
		std::cout << '\n';
	}
	
	void remove(const t_Data &data) override{
		if(!root)
			return;
		remove(data, root);
	}
	
	const t_Data &getMaxValue() const override{
		if(!root)
			throw EmptyTreeException{};
		return getMax(root.get());
	}
	
	const t_Data &getMinValue() const override{
		if(!root)
			throw EmptyTreeException{};
		return getMin(root.get());
	}
private:
	void insertNode(const t_Data &data, Node *node){
		if(data < node->data){
			if(node->left)
				insertNode(data, node->left.get());
			else
				node->left = std::make_unique<Node>(data);
		}
		else{
			if(node->right)
				insertNode(data, node->right.get());
			else
				node->right = std::make_unique<Node>(data);
		}			
	}
	
	void inOrderTraversal(Node *node) const{
		if(node->left)
			inOrderTraversal(node->left.get());
		std::cout << node->data << " ---> ";
		if(node->right)
			inOrderTraversal(node->right.get());
	}
	
	void remove(const t_Data &data, std::unique_ptr<Node> &nodeRef){
		if(data < nodeRef->data){
			if(nodeRef->left)
				remove(data, nodeRef->left);
		}
		else if(data > nodeRef->data){
			if(nodeRef->right)
				remove(data, nodeRef->right);
		}
		else{
			if(!nodeRef->left && !nodeRef->right){
				std::cout << "Removing a leaf node...\n";
				nodeRef.reset();
				return;
			}
			if(!nodeRef->left){
				std::cout << "Removing the right child...\n";
				std::unique_ptr<Node> temp = std::move(nodeRef->right);
				nodeRef.reset();
				nodeRef = std::move(temp);
				return;
			}
			else if(!nodeRef->right){
				std::cout << "Removing the left child...\n";
				std::unique_ptr<Node> temp = std::move(nodeRef->left);
				nodeRef.reset();
				nodeRef = std::move(temp);
				return;
			}
			std::cout << "Removing item with two children...\n";
			std::unique_ptr<Node> temp = detachRightMost(nodeRef->left);
			temp->right = std::move(nodeRef->right);
			std::unique_ptr<Node> &tempLeftMost = getLeftMost(temp);
			tempLeftMost->left = std::move(nodeRef->left);
			nodeRef.reset();
			nodeRef = std::move(temp);
		}
	}
	
	std::unique_ptr<Node> detachRightMost(std::unique_ptr<Node> &nodeRef){
		if(nodeRef->right)
			return detachRightMost(nodeRef->right);
		return std::move(nodeRef);
	}
	
	std::unique_ptr<Node> &getLeftMost(std::unique_ptr<Node> &nodeRef){
		if(nodeRef->left)
			return getLeftMost(nodeRef->left);
		return nodeRef;
	}
	
	const t_Data &getMax(Node *node) const{
		if(node->right){
			return getMax(node->right.get());
		}
		return node->data;
	}

	const t_Data &getMin(Node *node) const{
		if(node->left){
			return getMin(node->left.get());
		}
		return node->data;
	}
	
};



#endif