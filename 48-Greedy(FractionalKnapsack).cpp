//48-GreedyAlgorithms(FractionalKnapsack)

#include <iostream>
#include <algorithm>
using namespace std;

struct Item{
	int value;
	int weight;
	Item(int v, int w): value(v), weight(w){}
};

bool ratioCompare(struct Item a, struct Item b){
	double r1 =(double)a.value/(double)a.weight;
	double r2 =(double)b.value/(double)b.weight;
	return r1 > r2;
}

double fractionalKnapsack(int W, struct Item I[], int n){ //maximum weight, items, number of items.
	sort(I, I+n, ratioCompare); //ratio from largest to smallest.
	
	cout << "Value\tWeight\tRatio" << endl;
	for(int i = 0; i < n; i++)
		cout << I[i].value << "\t" << I[i].weight << "\t" << ((double)I[i].value/I[i].weight) << endl;

	int curWeight = 0; //current weight in knapsack.
	double finalvalue = 0.0; //result value in knapsack.

	for(int i = 0; i < n; i++){
		if(curWeight + I[i].weight <= W){
			curWeight += I[i].weight;
			finalvalue += I[i].value;
		}
		else{
			int remain = W - curWeight;
			finalvalue += I[i].value * ((double)remain/(double)I[i].weight);
			break;
		}
	}
	
	return finalvalue;
}

int main(){
	int W = 50;
	Item I[] = {{60, 10}, {100, 20}, {120, 30}};
	int n = sizeof(I)/sizeof(I[0]);
	
	int r = fractionalKnapsack(W, I, n);
	cout << "Maximum Value: " << r << endl;
	
	return 0;
}