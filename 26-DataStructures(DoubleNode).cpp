//25-DataStructures(DoubleNode)

#include <iostream>
using namespace std;

#include "Headers\DoubleNode.cpp"

int main(){
	DoubleNode *d1, *d2, *d3;
	d1 = new DoubleNode(10);
	d2 = new DoubleNode(20);
	d3 = new DoubleNode(30);
	
	d2->setPrev(d1);
	d2->setNext(d3);
	
	cout << "d1 Value: " << d2->getPrev()->getValue() << endl;
	cout << "d2 Value: " << d2->getValue() << endl;
	cout << "d3 Value: " << d2->getNext()->getValue() << endl;
	
	return 0;
}