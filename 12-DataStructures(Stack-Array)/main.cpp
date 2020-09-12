//12- Data Structures (Stack - Array)
#include <iostream>
#include <string>
#include "Stack.h"
using std::string;
using std::cout;

int main(){
	Stack<string> stack;
	stack.push("Adam");
	stack.push("Eve");
	cout << stack.size() << '\n';
	cout << stack.pop() << '\n';
	cout << stack.size() << '\n';
	cout << stack.pop() << '\n';	
	return 0;
}
