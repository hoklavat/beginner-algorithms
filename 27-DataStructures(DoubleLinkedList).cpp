//26-DataStructures(DoubleLinkedList)

#include <iostream>
using namespace std;

#include "Headers\DoubleLinkedList.cpp"

int main(){
	DoubleLinkedList dl{20};
	
	cout << "Initial Size: " << dl.getSize() << endl;
	dl.traverse();
	
	//insert at beginning.
	dl.insert(10, 0);
	dl.traverse();
	
	//insert at end.
	dl.insert(40, 10);
	dl.traverse();
	
	//insert at middle.
	dl.insert(30, 2);
	dl.traverse();
	
	//reverse traverse.
	dl.traverseReverse();
	
	//search.
	cout << "Position of 30: " << dl.search(30) << endl;
	
	//delete.
	dl.deleteNode(4);
	dl.traverse();
	
	//delete list.
	dl.deleteList();
	
	return 0;
}