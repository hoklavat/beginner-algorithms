#ifndef HashTable_h
#define HashTable_h

#include <vector>
#include <list>
using std::vector;
using std::list;

class HashTable{
	static constexpr int TABLE_SIZE = 10;
	struct HashItem{
		int key = 0;
		int value = 0;
	};
	vector<list<HashItem>> hashTable;
public:
	HashTable();
	int get(int key);
	void put(int key, int value);
private:
	static int hash(int key);
};

#endif