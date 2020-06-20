//09- Dynamic Programming (Knapsack Problem)
//set of N items, each has mass w and value v. total mass in knapsack shouldn't exceed W. make total value V large as possible.
//knapsack with weight capacity x, number of items y, each item has a value v, obtain maximum possible value without exceeding x.
#include <iostream>
#include <vector>
#include "KnapsackProblem.h"
using namespace std;

int main(){
	int numOfItems = 3;
	int capacityOfKnapsack = 5;
	vector<int> weightOfItems(4);
	weightOfItems[1] = 4;
	weightOfItems[2] = 2;
	weightOfItems[3] = 3;
	vector<int> profitOfItems(4);
	profitOfItems[1] = 10;
	profitOfItems[2] = 4;
	profitOfItems[3] = 7;
	Knapsack knapsack{numOfItems, capacityOfKnapsack, weightOfItems, profitOfItems};
	knapsack();
	knapsack.showResult();
	return 0;
}
