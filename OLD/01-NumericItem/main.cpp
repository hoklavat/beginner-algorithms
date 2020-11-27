//01- Numeric Item
//creates sequential data structure, each one holds the address of next one

#include <iostream>
using namespace std;

struct numeric_item{
	int value;
    numeric_item* next;
};
numeric_item* head = nullptr;

//create new numeric_item with value v, that stores the address of numeric_item at input
void add(int v, numeric_item** pp){
    numeric_item* newp = new numeric_item; //create new numeric_item
    newp->value = v; //value is equal to v
    newp->next = *pp; //next now holds address of numeric_item in the input
    *pp = newp; //address of current numeric_item is now newly created one's
}

numeric_item** find(int v, numeric_item** pp){
    while((*pp) != nullptr && (*pp)->value != v) 
		pp = &((*pp)->next);
    return pp;
}

void print(){
   for (numeric_item* p = head; p != nullptr; p = p->next)
	   cout << p->value << " ";
   cout << endl;
}

int main(){
	
   for (int i = 1; i < 10; i = i + 2)
	   add(i, &head);
   print();
   
   numeric_item** pp;
   pp = find(7, &head);
   add(8, pp);
   print();
   
   add(0, find(-1, &head)); //not found so added to end
   print();
   
   while (head != nullptr){
       numeric_item* p = head;
       head = head->next;
       cout << "deleting " << p->value << endl;
       delete p;
   }

   return 0;
}