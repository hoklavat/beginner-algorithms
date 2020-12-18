//53-DivideConquer(ZeroOneKnapsack)

#include <iostream>
using namespace std;

#define SIZE 4

int knapsackAux(int profits[], int weights[], int capacity, int index){	
	if(capacity <= 0 || index < 0 || index >= SIZE)
		return 0;
	
	int p1 = 0;
	if(weights[index] <= capacity)
		p1 = profits[index] + knapsackAux(profits, weights, capacity-weights[index], index+1);
	
	int p2 = knapsackAux(profits, weights, capacity, index+1);
	
	return max(p1, p2);
}

int knapsack(int profits[], int weights[], int capacity){
	return knapsackAux(profits, weights, capacity, 0);
}

int main(){
	int profits[SIZE] = {31, 26, 72, 17};
	int weights[SIZE] = {3, 1, 5, 2};
	int p = knapsack(profits, weights, 7); //knapsack capacity is 7. 1-26 and 5-72 is selected. 5+1 = 6 < 7.
	
	cout << "Maximum profit: " << p << endl; //26 + 72 = 98.
	
	return 0;
}