//37-DataStructures(AVLTree)

#include<iostream>>
using namespace std;

#include "Headers/AVLTree.cpp"

int main() {
	AVLTree a;
	a.insert(9);
    a.insert(5);
    a.insert(10);
    a.insert(0);
    a.insert(6);
    a.insert(11);
    a.insert(-1);
    a.insert(1);
    a.insert(2);
	
	cout << "Preorder Traversal: ";
	a.preOrder();
	
	a.deleteNode(10);
	cout << "Preorder Traversal: ";
	a.preOrder();
	
	return 0;
} 