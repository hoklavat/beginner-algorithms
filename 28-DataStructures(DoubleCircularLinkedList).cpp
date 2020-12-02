//27-DataStructures(SingleCircularLinkedList)

#include <iostream>
using namespace std;

#include "Headers\DoubleCircularLinkedList.cpp"

int main(){
	DoubleCircularLinkedList dc{30};
	
	//insert.
	dc.insert(20, 0);
	dc.insert(10, 0);
	dc.insert(40, 3);
	dc.insert(50, 10);
	
	//traverse.
	dc.traverse();	
	
	//delete.
	dc.deleteNode(0);
	cout << "First element is deleted." << endl;
	dc.traverse();
	
	//search.
	cout << "Position of 40 in Linked List: " << dc.search(40) << endl;
	
	//reverse traverse.
	dc.traverseReverse();
	
	//delete list.
	dc.deleteList();
	dc.traverse();
	
	return 0;
}