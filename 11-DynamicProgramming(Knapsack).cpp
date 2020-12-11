//10-DynamicProgramming(Knapsack)
//There is a set of N items, each has mass w and value v.
//Total mass in knapsack shouldn't exceed W.
//Make total value V large as possible.
//0-1 Knapsack Problem: Use each item only once. 
//Bounded Knapsack Problem: Multiple copies can be used up to a fixed limit.
//Unbounded Knapsack Problem: Multiple copies can be used infinitely.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Knapsack{
private:
	int numOfItems;
	int capacityOfKnapsack;
	int totalBenefit = 0;	
	vector<int> weights;
	vector<int> values;
	vector<vector<int>> knapsackTable; //table[i][j] maximum value of j-weight considering all values from 1 to i.
	
public:
	Knapsack(int numOfItems, int capacityOfKnapsack, const vector<int> &weights, const vector<int> &values);
	void operator()();
	void showResult();	
};

Knapsack::Knapsack(int _numOfItems, int _capacityOfKnapsack, const vector<int> &_weights, const vector<int> &_values):
numOfItems(_numOfItems), capacityOfKnapsack(_capacityOfKnapsack), weights(_weights), values(_values){
	knapsackTable.resize(numOfItems + 1);
	for(auto &item: knapsackTable)
		item.resize(capacityOfKnapsack + 1);
}


//Create two dimensional table.
//rows: index of items for referencing their weights and values.
//columns: all possible weights from 1 to W, incremented by 1.
//columns of 0th row filled with zeroes.
//start with first item. store its value in table if its weight fits into current weight column.
//table[row][column]: maximum value that can be obtained by selecting different combination of items while not exceeding current weight.
//value at last row and column gives result.
void Knapsack::operator()(){

	for(int i = 1; i < numOfItems + 1; i++){
		for(int w = 1; w < capacityOfKnapsack + 1; w++){
			
			//fill column. 
			int takingItem;
			if(weights[i] <= w){
				takingItem = values[i] + knapsackTable[i-1][w-weights[i]]; //how remaining part of weight will get filled in a best way?
			}
			else{
				takingItem = 0;
			}
			
			//don't fill column.
			int notTakingItem = knapsackTable[i-1][w]; //weight is too high, continue with previous best for current weight.
			
			knapsackTable[i][w] = max(notTakingItem, takingItem); //taking, not taking or 0.
		}
	}
	totalBenefit = knapsackTable[numOfItems][capacityOfKnapsack]; //value at last row-column gives solution.
}

void Knapsack::showResult(){
	cout << "Total Benefit: " << totalBenefit << '\n';
	for(int n = numOfItems, w = capacityOfKnapsack; n > 0; n--){
		if(knapsackTable[n][w] != 0 && knapsackTable[n][w] != knapsackTable[n-1][w]){
			cout << "We take item: #" << n << '\n';
			w = w - weights[n];
		}
	}
}

int main(){
	int numOfItems = 3; //total number of items.
	int capacityOfKnapsack = 5; //total weight of items can fit in knapsack.
	
	//weight for each item.
	vector<int> weightOfItems(4);
	weightOfItems[1] = 4;
	weightOfItems[2] = 2;
	weightOfItems[3] = 3;
	
	//value of each item.
	vector<int> profitOfItems(4);
	profitOfItems[1] = 10;
	profitOfItems[2] = 4;
	profitOfItems[3] = 7;
	
	Knapsack knapsack{numOfItems, capacityOfKnapsack, weightOfItems, profitOfItems};
	knapsack();
	knapsack.showResult();
	
	return 0;
}