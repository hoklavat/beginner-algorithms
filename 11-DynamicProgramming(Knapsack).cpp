//11-DynamicProgramming(Knapsack)
//given weights and values of n items, put these items in knapsack of capacity W to get maximum total value in knapsack.
//0-1 knapsack. you cannot break item. either pick complete item only once or don’t pick it.
//bounded knapsack: multiple copies can be used up to fixed limit.
//unbounded knapsack: multiple copies can be used infinitely.

#include <iostream>
using namespace std;

int max(int a, int b){
	return(a>b)?a:b; 
}

//0-1 Knapsack Problem.
//W: total weight capacity, w: weights of items, v: values of items, n: number of items.
int knapSack(int W, int w[], int v[], int n){
	if(n == 0 || W == 0) return 0; //run out of items or completely filled.
	if(w[n-1] > W) return knapSack(W, w, v, n-1); //weight of current item exceeds limit.
	else return max(v[n-1]+knapSack(W-w[n-1], w, v, n-1), knapSack(W, w, v, n-1)); //current item included or not.
}

int main(){
	int v[] = {60, 100, 120}; //values of items.
	int w[] = {10, 20, 30}; //weights of items.
	int W = 50; //capacity of knapsack.
	int n = sizeof(v)/sizeof(v[0]); //number of items.
	cout << "Maximum value that can be achieved is " << knapSack(W, w, v, n) << endl; //20+30=50 -> 100+120=220.
	return 0;
}