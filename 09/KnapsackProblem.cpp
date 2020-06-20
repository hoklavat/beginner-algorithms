#include "KnapsackProblem.h"
#include <iostream>
#include <algorithm>

Knapsack::Knapsack(int _numOfItems, int _capacityOfKnapsack, const vector<int> &_weights, const vector<int> &_values):
numOfItems(_numOfItems), capacityOfKnapsack(_capacityOfKnapsack), weights(_weights), values(_values){
	knapsackTable.resize(numOfItems + 1);
	for(auto &item: knapsackTable)
		item.resize(capacityOfKnapsack + 1);
}

void Knapsack::operator()(){
	for(int i = 1; i < numOfItems + 1; i++){
		for(int w = 1; w < capacityOfKnapsack + 1 ; w++){
			int notTakingItem = knapsackTable[i-1][w];
			int takingItem = 0;
			if(weights[i] <= w){
				takingItem = values[i] + knapsackTable[i-1][w-weights[i]];
			}
			knapsackTable[i][w] = std::max(notTakingItem, takingItem);
		}
	}
	totalBenefit = knapsackTable[numOfItems][capacityOfKnapsack];
}

void Knapsack::showResult(){
	std::cout << "Total Benefit: " << totalBenefit << '\n';
	for(int n = numOfItems, w = capacityOfKnapsack; n > 0; n--){
		if(knapsackTable[n][w] != 0 && knapsackTable[n][w] != knapsackTable[n-1][w]){
			std::cout << "We take item: #" << n << '\n';
			w = w - weights[n];
		}
	}
}