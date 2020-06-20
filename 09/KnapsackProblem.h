#ifndef KnapsackProblem_h
#define KnapsackProblem_h

#include <vector>
using std::vector;

class Knapsack{
	int numOfItems;
	int capacityOfKnapsack;
	vector<vector<int>> knapsackTable;
	int totalBenefit = 0;
	vector<int> weights;
	vector<int> values;
public:
	Knapsack(int numOfItems, int capacityOfKnapsack, const vector<int> &weights, const vector<int> &values);
	void operator()();
	void showResult();	
};

#endif