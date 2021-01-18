//46-Greedy(ActivitySelection)
//Task: n activities are given with their start and finish times. 
//select maximum number of activities that can be performed by single person, 
//assuming that person can only work on single activity at time.
//Reference: greedy.
//Time Complexity: O(nlogn) if unsorted. O(n) if sorted.

#include<iostream>
using namespace std;

void print(int S[], int F[], int n){ //start time, finish time, number of activities.	

	cout << "Following activities are selected: ";
	
	int i = 0;
	int j = 0;
	cout << i << " "; //first activity. activities are sorted by their finish times.

	for(j = 1; j < n; j++){
		if (S[j] >= F[i]){ //finish time is greater than previous activity start time.
			cout << j << " ";
			i = j;
		}
	}
	cout << endl;
}

int main(){
	int s[] = {1, 3, 0, 5, 8, 5};
	int f[] = {2, 4, 6, 7, 9, 9};
	int n = sizeof(s)/sizeof(s[0]);	
	print(s, f, n);	
	return 0;
}