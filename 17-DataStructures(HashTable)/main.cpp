//17- Data Structures (Hash Table - Chaining Collision Prevention)
//Chaining: generate array index corresponding to input key by hash function, if same index calculated for different keys use linked-list to store values.
#include "HashTable.h"
#include <iostream>

int main(){
	HashTable hashTable{};
	hashTable.put(1, 1); //key = 1
	hashTable.put(11, 10); //key = 1
	hashTable.put(21, 100); //key = 1
	std::cout << hashTable.get(1) << ' ';
	std::cout << hashTable.get(11) << ' ';
	std::cout << hashTable.get(21) << ' ';
	return 0;
}
