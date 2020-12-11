//23-DataStructures(SingleNode)

#include <iostream>
#include "Headers\SingleNode.cpp"
using namespace std;

int main(){
	SingleNode s1{10};
	SingleNode s2{20};
	
	s1.setNext(&s2);
	
	cout << "s1 Value: " << s1.getValue() << endl;
	cout << "s2 Value: " << s1.getNext()->getValue() << endl;
	
	return 0;
}