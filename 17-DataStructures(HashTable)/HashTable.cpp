#include "HashTable.h"
#include <iostream>
using std::cout;

HashTable::HashTable(){
	hashTable.resize(TABLE_SIZE);
}

int HashTable::get(int key){
	int generatedArrayIndex = hash(key);
	list<HashItem> &items = hashTable[generatedArrayIndex];
	if(hashTable[generatedArrayIndex].empty())
		return -1;
	for(HashItem const &item: items){ //O(N)
		if(item.key == key)
			return item.value;
	}
	return -1;
}

void HashTable::put(int key, int value){
	int hashArrayIndex = hash(key);
	list<HashItem> &items = hashTable[hashArrayIndex];
	if(items.empty()){
		cout << "No collision simple insertion...\n";		
	}
	else{
		cout << "Collision when inserting with key " << key << '\n'; //more collision, more item, slower
		for(HashItem &item: items){
			if(item.key == key){
				cout << "Item is already inserted...\n";
				return;
			}
		}
	}
	items.push_back(HashItem{key, value});
	cout << "Size of the list is " << items.size() << '\n';
}

int HashTable::hash(int key){ //use prime numbers for effective solution
	return key % TABLE_SIZE;
}