#ifndef AVL_TREE
#define AVL_TREE

#include <iostream>
using namespace std;

class Node{
public:
	int key;
	int height;
	Node *left;
	Node *right;
};

class AVLTree{
private:
	Node *root;
	
	int height(Node *n){
		if (n == nullptr)
			return 0;
		return n->height;
	}
	
	int max(int a, int b){
		return (a > b)? a : b;
	}
	
	Node *newNode(int v){
		Node *n = new Node();
		n->key = v;
		n->height = 1; //increment by one for each sub level.
		n->left = nullptr; //initially there is no child.
		n->right = nullptr;
		return(n);
	}

	//right rotate node n.
	Node *rightRotate(Node *n){
		Node *x = new Node();
		Node *y = new Node();
		x = n->left;
		y = x->right;
		x->right = n;
		n->left = y;
		n->height = max(height(n->left), height(n->right)) + 1;
		x->height = max(height(x->left), height(x->right)) + 1;
		return x; //new root.
	}

	//left rotate node n.
	Node *leftRotate(Node *n){
		Node *x = new Node();
		Node *y = new Node();
		x = n->right;
		y = x->left;
		x->left = n;
		n->right = y;
		n->height = max(height(n->left), height(n->right)) + 1;
		x->height = max(height(x->left), height(x->right)) + 1;
		return x; //new root.
	}

	//balance factor of node n.
	int getBalance(Node *n){
		if (n == nullptr)
			return 0;
		return height(n->left) - height(n->right);
	}
	
	//insert key. return new root.
	Node* insert(Node *n, int k){
		if (n == nullptr)
			return(newNode(k));
		if (k < n->key)
			n->left = insert(n->left, k);
		else if (k > n->key)
			n->right = insert(n->right, k);
		else
			return n;

		n->height = max(height(n->left), height(n->right)) + 1;

		int b = getBalance(n);
		
		//left-left.
		if (b > 1 && k < n->left->key)
			return rightRotate(n);

		//right-right.
		if (b < -1 && k > n->right->key)
			return leftRotate(n);

		//left-right.
		if (b > 1 && k > n->left->key){
			n->left = leftRotate(n->left);
			return rightRotate(n);
		}

		//right-left.
		if(b < -1 && k < n->right->key){
			n->right = rightRotate(n->right);
			return leftRotate(n);
		}

		return n; //new root.
	}
	
	//print preorder traversal.
	void preOrder(Node *n)
	{
		if(n != nullptr){
			cout << n->key << " ";
			preOrder(n->left);
			preOrder(n->right);
		}
	}
	
	Node *minValueNode(Node *n){
		Node* c = n;
		while (c->left != NULL)
			c = c->left;	
		return c;
	}
	
	Node *deleteNode(Node *n, int k){
		//none.
		if(n == nullptr)
			return n;
	
		//look for left.
		if(k < n->key)
			n->left = deleteNode(n->left, k);

		//look for right.
		else if(k > n->key)
			n->right = deleteNode(n->right, k);
	
		//same.
		else{
			//node with only one child or no child.
			if((n->left == nullptr) || (n->right == nullptr)){
				Node *temp = new Node();
				temp = n->left ? n->left : n->right;

				//no child.
				if(temp == nullptr){
					temp = n;
					n = nullptr;
				}
				else
					*n = *temp; //one child.
					
				delete temp;
			}
			else
			{
				// node with two children. successor.
				Node* temp = new Node();
				temp = minValueNode(n->right);
				n->key = temp->key;
				n->right = deleteNode(n->right, temp->key);
			}
		}
	
		//only one node.
		if (n == nullptr)
		return n;

		n->height = 1 + max(height(n->left), height(n->right));
	
		int b = getBalance(n);
	
		//left-left.
		if (b> 1 &&	getBalance(n->left) >= 0)
			return rightRotate(n);
	
		//left-right.
		if (b > 1 && getBalance(n->left) < 0){
			n->left = leftRotate(n->left);
			return rightRotate(n);
		}
	
		//right-right.
		if (b < -1 && getBalance(n->right) <= 0)
			return leftRotate(n);
	
		//right-left.
		if (b < -1 && getBalance(n->right) > 0){
			n->right = rightRotate(n->right);
			return leftRotate(n);
		}
	
		return n;
	}

public:
	AVLTree(){
		root = nullptr;
	}
	
	void insert(int k){
		root = insert(root, k);
	}
	
	void preOrder(){
		preOrder(root);
		cout << endl;
	}
	
	void deleteNode(int k){
		root = deleteNode(root, k);
	}
};

#endif