//38-DataStructures(Trie)

#include<iostream>> 
using namespace std; 

#include "Headers/Trie.cpp"

int main(){
	Trie *head = new Trie();
	
	head->insert("hello");	
	cout << "hello: " << head->search("hello") << endl;
	
	head->insert("lello");
	cout << "hello: " << head->search("hello") << endl;
	cout << "lello: " << head->search("lello") << endl;
	
	head->insert("lorenzo");
	cout << "lorenzo: " << head->search("lorenzo") << endl;
	
	head->deletion(head, "lello");
	cout << "lello: " << head->search("lello") << endl;
	cout << "lorenzo: " << head->search("lorenzo") << endl;
	
	head->deletion(head, "lorenzo");
	head->deletion(head, "hello");
	
	if(head == nullptr){
		cout << "Trie is empty." << endl;
	}
 
	return 0;
}