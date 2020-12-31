#ifndef SINGLE_NODE
#define SINGLE_NODE

class SingleNode{
private:
	int value;
	SingleNode *next;
	
public:
	SingleNode(): SingleNode(0){}
	SingleNode(int v): value(v), next(nullptr){}
	
	void setValue(int v){
		value = v;
	}
	
	int getValue(){
		return value;
	}
	
	void setNext(SingleNode *n){
		next = new SingleNode(); 
		next = n;
	}
	
	SingleNode *getNext(){
		return next;
	}
};

#endif