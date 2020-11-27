//05-Recursion(BinarySearch)

#include <iostream>
using namespace std;

int BinarySearch(int nums[], int val, int low, int high){
	if(low > high) return -1;
	int middle = low + (high-low)/2;
	if(val == nums[middle]) return middle;
	if(val < nums[middle]) return BinarySearch(nums, val, low, middle-1);
	if(val > nums[middle]) return BinarySearch(nums, val, middle+1, high);
}

int main(){
	int nums[11] = {1, 5, 7, 9, 13, 16, 35, 67, 78, 109, 167};
	cout << "Index of 16 in array: " << BinarySearch(nums, 16, 0, 11) << endl;
	cout << "Index of 7 in array: " << BinarySearch(nums, 7, 0, 11) << endl;
	cout << "Index of 167 in array: " << BinarySearch(nums, 167, 0, 11) << endl;
	return 0;
}