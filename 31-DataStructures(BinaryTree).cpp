//31-DataStructures(BinaryTree)

#include <iostream>
using namespace std;

#include "Headers\BinaryTree.cpp"

int main(){
	BinaryTree *tree = new BinaryTree();
	
	tree->insert(9);
	tree->insert(4);
	tree->insert(2);
	tree->insert(10);
	tree->insert(1);
	tree->insert(8);
	tree->insert(3);
	tree->insert(6);
	tree->insert(7);
	tree->insert(5);
	
	cout << "Preorder Traverse: ";
	tree->preorderTraverse();
	cout << endl;
	
	cout << "Inorder Traverse: ";
	tree->inorderTraverse();
	cout << endl;
	
	cout << "Postorder Traverse: ";
	tree->postorderTraverse();
	cout << endl;

	delete tree;
}