#ifndef HASH
#define HASH

#include <iostream>
#include <list>
using namespace std;

class Hash{
private:
	list<int> *data;
	int size; //number of buckets/keys
	
public:
	Hash(int s){
		size = s;
		data = new list<int>[size];
	}
	
	//simple hash function that calculates index for given value.
	int hashFunction(int v){
		return (v%size);
	}
	
	void insertItem(int v){
		int i = hashFunction(v);
		data[i].push_back(v);
	}
	
	void deleteItem(int v){
		int i = hashFunction(v);
		list<int>::iterator it;
	
		for(it = data[i].begin(); it != data[i].end(); it++){
			if (*it == v) break;
		}

		if (it != data[i].end())
			data[i].erase(it);
	}
	
	void displayHash(){
		for(int i = 0; i < size; i++){
			cout << i;
			for(auto x : data[i])
				cout << ":" << x;
		cout << endl;
		}
	}
};

#endif