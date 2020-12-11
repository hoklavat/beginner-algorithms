//24-DataStructures(SingleLinkedList)

#include <iostream>
using namespace std;

#include "Headers\SingleLinkedList.cpp"

int main(){
	//create.
	SingleLinkedList sl(40);
	
	cout << "Head Value: " << sl.getHead()->getValue() << endl;
	cout << "Tail Value: " << sl.getTail()->getValue() << endl;
	cout << "Size: " << sl.getSize() << endl;
	
	//insert at the beginning.
	sl.insert(10, 0);
	cout << "\nHead Value: " << sl.getHead()->getValue() << endl;
	cout << "Tail Value: " << sl.getTail()->getValue() << endl;
	cout << "Size: " << sl.getSize() << endl;
	
	//insert at tail.
	sl.insert(30, sl.getSize());
	cout << "\nHead Value: " << sl.getHead()->getValue() << endl;
	cout << "Tail Value: " << sl.getTail()->getValue() << endl;
	cout << "Size: " << sl.getSize() << endl;
	
	//insert at middle.
	sl.insert(20, 2);
	cout << "\nHead Value: " << sl.getHead()->getValue() << endl;
	cout << "Tail Value: " << sl.getTail()->getValue() << endl;
	cout << "Size: " << sl.getSize() << endl;
	
	//traverse.
	sl.traverse();
	
	//search.
	cout << "Location of 20: " << sl.search(20) << endl;
	
	//delete node.
	cout << "\nAfter Deletion";
	sl.deleteNode(3);
	sl.traverse();	
	
	//delete linked list.
	sl.deleteList();
	
	return 0;
}