//10- Data Structures (Array)
#include <iostream>
using namespace std;

int main(){
	const int SIZE = 10;
	int nums[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	cout << nums[2] << '\n';
	nums[2] = 100;
	cout << nums[2] << '\n';
	
	for(int i = 0; i < SIZE; i++){ //O(N) linear search time	
		if(nums[i] == 8)
			cout << "index for value 8 is " << i << ".\n";
	}
	
	nums[2] = 0;
	for(int i = 2; i < SIZE; i++)
		nums[i] = nums[i + 1];
	for(int i = 0; i < SIZE; i++)
		cout << nums[i] << " ";
	cout << '\n';
	
	return 0;
}
