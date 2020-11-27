//02- Numeric Tree

#include <iostream>
using namespace std;

struct numeric_tree{
    int value;
    numeric_tree* left;
    numeric_tree* right;
};
numeric_tree* root = nullptr;

void add(int v, numeric_tree** pp){
    *pp = new numeric_tree;
    (*pp)->value = v;
    (*pp)->left = (*pp)->right = nullptr;
}

void delete_tree(numeric_tree* item){
    if (item == nullptr)
        return;    
    else{
        delete_tree(item->left);
        delete_tree(item->right);
        cout << "deleting " << item->value << endl;
        delete item;
    }
}

numeric_tree** find(int v, numeric_tree** pp){
    if (*pp == nullptr)
       return pp;
	   
    else if (v < (*pp)->value)
        return find(v, &((*pp)->left));
		
    else
        return find(v, &((*pp)->right));
}

void print(numeric_tree* item){
    if (item == nullptr)
        return;
    else{
        print(item->left);
        cout << item->value << " ";
        print(item->right);
    }
}

int main(){
    int insert_order[] {4, 2, 1, 3, 6, 5, 10, 9, 7, 8};
    for (int i = 0; i < 10; ++i){
        int v = insert_order[i];
        add(v, find(v, &root)); //small one to the left, large one to the right
    }
    
    print(root);
    cout << endl;    
    delete_tree(root);

    return 0;
}