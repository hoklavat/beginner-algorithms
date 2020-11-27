//04- Recursion (Sum, Factorial, Tail/Head/Taylor Recursion, Fibonacci, Binary Search, Towers of Hanoi)
#include <iostream>
using namespace std;

int Sum(int n){
	if(n == 1) return 1; //base case
	return n + Sum(n-1);
}

int Factorial1(int n){
	if(n == 1) return 1;
	return n * Factorial1(n - 1); //stack
}

int Factorial2(int n, int accumulator){
	if(n == 1) return accumulator;
	return Factorial2(n - 1, n * accumulator); //no stack, memory efficient
}

void Tail(int n){
	if(n == 0) return;
	cout << n << " ";
	Tail(n - 1);
}

void Head(int n){
	if(n == 0) return;	
	Head(n - 1);
	cout << n << " ";
}

int Fibonacci1(int n){
	if(n == 0) return 0;
	if(n == 1) return 1;
	int fib1 = Fibonacci1(n - 1); //head recursion
	int fib2 = Fibonacci1(n - 2);
	return  fib1 + fib2; //1, 1, 2, 3, 5, 8, ...
}

int Fibonacci2(int n){
	if(n == 0) return 0;
	if(n == 1) return 1;
	return Fibonacci2(n - 1) + Fibonacci2(n - 2); //1, 1, 2, 3, 5, 8, ...
}

int Fibonacci3(int n, int a, int b){ //Tail
    if(n==0) return a;
    if(n==1) return b;
    return Fibonacci3(n - 1, b, a + b);
}

int BinarySearch(int nums[], int low, int high, int num){
	if(low > high) return -1;
	int middle = low + (high + low) / 2;
	if(nums[middle] == num) return middle;
	if(num < nums[middle]) return BinarySearch(nums, low, middle - 1, num);
	else return BinarySearch(nums, middle + 1, high, num);
}

void HanoiTowers(int n, char rodFrom, char middleRod, char rodTo){
	if(n == 1){
		cout << "Plate 1 from " << rodFrom << " to " << rodTo << endl;
		return;
	}
	HanoiTowers(n - 1, rodFrom, rodTo, middleRod);
	cout << "Plate " << n << " from " << rodFrom << " to " << rodTo << endl;
	HanoiTowers(n - 1, middleRod, rodFrom, rodTo);
}

int main(){
	
	cout << "**Sum and Factorial**" << endl;
	cout << Sum(5) << endl;	
	cout << Factorial1(5) << endl;
	cout << Factorial2(5, 1) << endl;
	
	cout << "\n**Head and Tail Recursion**" << endl;
	Tail(5);
	cout << endl;
	Head(5);
	cout << endl;
	
	cout << "\n**Fibonacci Number**" << endl;
	cout << Fibonacci1(10) << endl;	
	cout << Fibonacci2(10) << endl;
	cout << Fibonacci3(10, 0, 1) << endl;
	
	int nums[] = {1, 2, 3, 4, 5, 10, 20, 30, 40, 50, 100};
	int size = sizeof(nums)/sizeof(nums[0]);
	cout << "\n**Binary Search**" << endl;
	cout << BinarySearch(nums, 0, size, 10) << endl;
	
	cout << "\n**Towers of Hanoi**" << endl;
	HanoiTowers(3, 'A', 'B', 'C');
	
	return 0;
}
