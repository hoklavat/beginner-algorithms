//27-DataStructures(SingleCircularLinkedList)

#include <iostream>
using namespace std;

#include "Headers\SingleCircularLinkedList.cpp"

int main(){
	SingleCircularLinkedList sc{30};
	
	//insert at beginning.
	sc.insert(20, 0);
	sc.insert(10, 0);
	sc.traverse();
	
	//insert at middle.
	sc.insert(40, 3);
	
	//insert at last.
	sc.insert(50, 4);
	sc.insert(60, 70);
	sc.traverse();
	
	//next node of tail is head.
	cout << "Value of Tail Node: " << sc.getTail()->getValue() << endl;
	cout << "Value of Next Node of Tail Node: " << sc.getTail()->getNext()->getValue() << endl;
	
	//search.
	cout << "Position of 50 in List: " << sc.search(50) << endl;
	
	//delete all nodes from last.
	while(sc.getSize() > 0){
		sc.traverse();		
		sc.deleteNode(sc.getSize()-1);
	}
	
	//existance.
	cout << boolalpha << "Linked List Exists: " << sc.exists() << endl;
	sc.deleteList();
	cout << boolalpha << "Linked List Exists: " << sc.exists() << endl;
	
	return 0;
}