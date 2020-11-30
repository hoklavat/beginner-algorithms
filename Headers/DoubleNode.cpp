#ifndef DOUBlE_NODE
#define DOUBLE_NODE

class DoubleNode{
private:
	int value;
	DoubleNode *next;
	DoubleNode *prev;
	
public:
	DoubleNode(): DoubleNode(0){}
	DoubleNode(int v): value(v), next(nullptr){}
	
	void setValue(int v){
		value = v;
	}
	
	int getValue(){
		return value;
	}
	
	void setNext(DoubleNode *n){
		next = new DoubleNode(); 
		next = n;
	}
	
	DoubleNode *getNext(){
		return next;
	}
	
	void setPrev(DoubleNode *n){
		prev = new DoubleNode(); 
		prev = n;
	}
	
	DoubleNode *getPrev(){
		return prev;
	}
};

#endif