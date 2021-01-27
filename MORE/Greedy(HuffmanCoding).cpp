//Greedy(HuffmanCoding)
//Task: generate huffman codes for given array of unique characters where each character has specific frequency of occurence.
//each binary code is unique for single character and may be of variable length. 
//bitstream code should only be expressed in one single combination of characters.
//Reference: greedy, prefix code, huffman coding, huffman tree, heap, priority queue, bitstream.
//Time Complexity: O(nlogn). n number of characters.

#include <iostream>
using namespace std;

#define MAX_TREE_HT 100 //maximum tree height.

struct MinHeapNode{
	char data;
	unsigned freq;
	MinHeapNode *left;
	MinHeapNode *right;
};

struct MinHeap{
	unsigned size;
	unsigned capacity;
	MinHeapNode** arr;
};

MinHeapNode* newNode(char data, unsigned freq){
	MinHeapNode* temp = (MinHeapNode*)malloc(sizeof(MinHeapNode));
	temp->left = NULL;
	temp->right = NULL;
	temp->data = data;
	temp->freq = freq;
	return temp;
}

MinHeap* createMinHeap(unsigned capacity){
	MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
	minHeap->size = 0;
	minHeap->capacity = capacity;
	minHeap->arr = (MinHeapNode**)malloc(minHeap->capacity * sizeof(MinHeapNode*));
	return minHeap;
}

void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b){
	MinHeapNode* t = *a;
	*a = *b;
	*b = t;
}

void minHeapify(MinHeap* minHeap, int idx){
	int smallest = idx;
	int left = 2*idx + 1;
	int right = 2*idx + 2;
	if(left < minHeap->size && minHeap->arr[left]->freq < minHeap->arr[smallest]->freq) smallest = left;
	if(right < minHeap->size && minHeap->arr[right]->freq < minHeap->arr[smallest]->freq) smallest = right;
	if(smallest != idx){
		swapMinHeapNode(&minHeap->arr[smallest], &minHeap->arr[idx]);
		minHeapify(minHeap, smallest);
	}
}

int isSizeOne(MinHeap* minHeap){
	return(minHeap->size == 1);
}

MinHeapNode* extractMin(MinHeap* minHeap){
	MinHeapNode* temp = minHeap->arr[0];
	minHeap->arr[0] = minHeap->arr[minHeap->size - 1];
	--minHeap->size;
	minHeapify(minHeap, 0);
	return temp;
}

void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode){
	++minHeap->size;
	int i = minHeap->size - 1;
	while(i && minHeapNode->freq < minHeap->arr[(i-1)/2]->freq){
		minHeap->arr[i] = minHeap->arr[(i-1)/2];
		i =(i - 1) / 2;
	}
	minHeap->arr[i] = minHeapNode;
}

void buildMinHeap(struct MinHeap* minHeap){
	int n = minHeap->size - 1;
	int i;
	for(i =(n - 1) / 2; i >= 0; --i)
		minHeapify(minHeap, i);
}

void printArr(int arr[], int n){
	int i;
	for(i = 0; i < n; ++i)
		cout << arr[i];
	cout << endl;
}

int isLeaf(MinHeapNode* root){
	return !(root->left) && !(root->right);
}

struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size){
	MinHeap* minHeap = createMinHeap(size);
	
	for(int i = 0; i < size; ++i)
		minHeap->arr[i] = newNode(data[i], freq[i]);

	minHeap->size = size;
	buildMinHeap(minHeap);
	
	return minHeap;
}

struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size){
	MinHeapNode *left, *right, *top;
	MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);

	while(!isSizeOne(minHeap)){
		left = extractMin(minHeap);
		right = extractMin(minHeap);
		top = newNode('$', left->freq + right->freq);
		top->left = left;
		top->right = right;
		insertMinHeap(minHeap, top);
	}
	
	return extractMin(minHeap);
}

void printCodes(struct MinHeapNode* root, int arr[], int top){
	if(root->left){
		arr[top] = 0;
		printCodes(root->left, arr, top + 1);
	}

	if(root->right){
		arr[top] = 1;
		printCodes(root->right, arr, top + 1);
	}

	if(isLeaf(root)){
		std::cout << root->data << ": ";
		printArr(arr, top);
	}
}

void HuffmanCodes(char data[], int freq[], int size){
	struct MinHeapNode* root = buildHuffmanTree(data, freq, size);
	int arr[MAX_TREE_HT], top = 0;
	printCodes(root, arr, top);
}

int main(){
	char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
	int freq[] = {5, 9, 12, 13, 16, 45};

	int size = sizeof(arr)/sizeof(arr[0]);

	HuffmanCodes(arr, freq, size);

	return 0;
}
