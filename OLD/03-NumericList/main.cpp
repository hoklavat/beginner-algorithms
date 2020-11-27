//03- Numeric List

#include <iostream>
using namespace std;

struct numeric_item{
    int value;
    numeric_item* next;
};

class numeric_list{
    numeric_item* head;
public:
    numeric_list(): head(nullptr){}
   ~numeric_list();
    void print();
    void add(int v);
    numeric_item* find(int v);
};

numeric_list::~numeric_list(){
   while(head != nullptr){
       numeric_item* p = head;
       head = head->next;
       cout << "deleting " << p->value << endl;
       delete p;
   }
}

void numeric_list::print(){
   for (numeric_item* p = head; p != nullptr; p = p->next){
       cout << p->value << " ";
   }
   cout << endl;
}

void numeric_list::add(int v){
    numeric_item* newp = new numeric_item;
    newp->value = v;
    newp->next = head;
    head = newp;
}

numeric_item* numeric_list::find(int v){
    for (numeric_item* p = head; p != nullptr; p = p->next){
        if (p->value == v) 
            return p;
    }
    return nullptr;
}

int main(){
    numeric_list l;
    for (int i = 1; i < 6; ++i){
        l.add(i);
    }
    l.print();
   
    numeric_item* p = l.find(4);
    if (p != nullptr)
        cout << "found numeric_item 4" << endl;
   
    return 0;
}

