//Math(Power)
//Task: create power function without using multiplication(*) and division(/) operators.
//only positive numbers.

#include <iostream>
using namespace std;

int pow(int a, int b){
	if(b == 0) return 1;
	int answer = a;
	int increment = a;
	int i, j;
	for(i = 1; i < b; i++){
		for(j = 1; j < a; j++){
			answer += increment;
		}
		increment = answer;
	}
	return answer;
}

//Recursive Method.
int multiply(int x, int y){
	if(y) return(x + multiply(x, y-1));
	else return 0;
}

int powR(int a, int b){
	if(b) return multiply(a, powR(a, b-1));
	else return 1;
}

int main(){
	cout << pow(5, 3) << endl;
	cout << powR(5, 3) << endl;
	return 0;
}