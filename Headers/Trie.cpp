#ifndef TRIE
#define TRIE

#include <iostream>
using namespace std;

#define CHAR_SIZE 128
 
class Trie{
public:
	bool isLeaf;
	Trie* character[CHAR_SIZE];
 
	Trie(){
		this->isLeaf = false;
 
		for(int i = 0; i < CHAR_SIZE; i++)
			character[i] = nullptr;
	}
 
	void insert(string key){
		Trie* current = this;
		for(int i = 0; i < key.length(); i++){
			if(current->character[key[i]] == nullptr)
				current->character[key[i]] = new Trie();
			current = current->character[key[i]]; //characters of string is considered as indexes for trie array.
		}
		current->isLeaf = true;
	}
	
	bool deletion(Trie *&current, string key){
		if(current == nullptr)
			return false;

		if(key.length()){
			if(current != nullptr && current->character[key[0]] != nullptr && deletion(current->character[key[0]], key.substr(1)) && current->isLeaf == false){
				if(!haveChildren(current)){
					delete current;
					current = nullptr;
					return true;
				}
				else{
					return false;
				}
			}
		}
	 
		if(key.length() == 0 && current->isLeaf){
			if(!haveChildren(current)){
				delete current;
				current = nullptr;
				return true;
			}	 
			else{
				current->isLeaf = false;
				return false;
			}
		}
	 
		return false;
	}
	
	bool search(string key){
		if(this == nullptr)
			return false;
	 
		Trie* current = this;
		for(int i = 0; i < key.length(); i++){
			current = current->character[key[i]];
			if(current == nullptr)
				return false;
		}
		
		return current->isLeaf;
	}
	
	bool haveChildren(Trie const* current){
		for(int i = 0; i < CHAR_SIZE; i++)
			if(current->character[i])
				return true;	 
		return false;
	}
};

#endif