#ifndef BINARY_TREE
#define BINARY_TREE

#include <iostream>
using namespace std;

struct Node{
	int value;
	Node* left;
	Node* right;
};

class BinaryTree{
private:
	Node *root;
	
public:
	BinaryTree(){
		root = nullptr;
	}

	~BinaryTree(){
		deleteTree();
	}
	
	void deleteTree(Node* leaf){
		if(leaf != nullptr){
			deleteTree(leaf->left);
			deleteTree(leaf->right);
			delete leaf;
		}
	}
	
	void deleteTree(){
		deleteTree(root);
	}

	void insert(int v, Node* leaf){
		
		//small ones to left.
		if(v < leaf->value){
			if(leaf->left != nullptr){
				insert(v, leaf->left);
			}else{
				leaf->left = new Node;
				leaf->left->value = v;
				leaf->left->left = nullptr;
				leaf->left->right = nullptr;
			}
		}
		
		//greater ones to right.
		else if(v >= leaf->value){
			if(leaf->right != nullptr){
				insert(v, leaf->right);
			}else{
				leaf->right = new Node;
				leaf->right->value = v;
				leaf->right->right = nullptr;
				leaf->right->left = nullptr;
			}
		}
	}	
	
	void insert(int v){
		if(root != nullptr){
			insert(v, root);
		}
		else{
			root = new Node;
			root->value = v;
			root->left = nullptr;
			root->right = nullptr;
		}
	}	

	Node* search(int v, Node* leaf){
		if(leaf != nullptr){
			//if equal return.
			if(v == leaf->value){
				return leaf;
			}
			
			//if smaller search left.
			if(v < leaf->value){
				return search(v, leaf->left);
			}
			
			//if larger search right.
			else{
				return search(v, leaf->right);
			}
		}
	
		//not found.
		else{
			return nullptr;
		}
	}

	Node* search(int v){
		return search(v, root);
	}
	
	void inorderTraverse(Node* leaf){
		if(leaf != nullptr){
			inorderTraverse(leaf->left);
			cout << leaf->value << " ";
			inorderTraverse(leaf->right);
		}
	}
	
	void inorderTraverse(){
		inorderTraverse(root);
	}	
	
	void postorderTraverse(Node*leaf){
		if(leaf != nullptr){
			inorderTraverse(leaf->left);
			inorderTraverse(leaf->right);
			cout << leaf->value << " ";
		}
	}

	void postorderTraverse(){
		postorderTraverse(root);
	}
	
	void preorderTraverse(Node*leaf){
		if(leaf != nullptr){
			cout << leaf->value << " ";
			inorderTraverse(leaf->left);
			inorderTraverse(leaf->right);
		}
	}

	void preorderTraverse(){
		preorderTraverse(root);
	}
};

#endif