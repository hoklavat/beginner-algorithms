//29-DataStructures(Stack)

#include <iostream>
using namespace std;

#include "Headers\Stack.cpp"

int main(){
	StackArray sa{10}; //fixed size stack.
	StackList sl; //dynamically sized stack.
	
//StackArray Test
	//push.
	cout << "Push into Stack: ";
	for(int i = 0; i < 10; i++){
		sa.push(i*10);
		cout << sa.getTop() << " ";
	}
	cout << endl;
	
	//overflow.
	sa.push(100);
	
	//peek.
	cout << "Top of Stack: " << sa.getTop() << endl;
	
	//pop.
	cout << "Pop from Stack: ";
	for(int i = 0; i < 10; i++){
		cout << sa.pop() << " ";
	}
	cout << endl;
	
	//underflow.
	sa.pop();
	
	//delete.
	sa.deleteStack();
	
	cout << endl;

//StackList Test
	cout << "Push into Stack: ";
	for(int i = 0; i < 10; i++){
		sl.push(i*10);
		cout << sl.getTop() << " ";
	}
	cout << endl;	
	
	cout << "Top of Stack: " << sl.getTop() << endl;
	cout << "Size of Stack: " << sl.getSize() << endl;
	
	cout << "Pop from Stack: ";
	while(!sl.isEmpty()){
		cout << sl.pop() << " ";
	}
	cout << endl;
	
	//underflow.
	sl.pop();
	
	//delete.
	sl.deleteStack();
	
	return 0;
}