//11- Data Structures (Linked List)
#include "LinkedList.h"

int main(){
	std::unique_ptr<List<int>> myLinkedList = std::make_unique<LinkedList<int>>();
	myLinkedList->insert(1);
	myLinkedList->insert(2);
	myLinkedList->insert(3);
	myLinkedList->insert(4);
	myLinkedList->traverseList();
	myLinkedList->remove(1);
	myLinkedList->traverseList();	
	return 0;
}
