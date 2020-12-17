//46-GreedyAlgorithms(ActivitySelection)

#include<iostream>
using namespace std;

void printMaxActivities(int s[], int f[], int n){ //start time, finish time, number of activities.	

	cout << "Following activities are selected: ";
	
	int i = 0, j;
	cout << i << " "; //first activity.

	for (j = 1; j < n; j++){
		if (s[j] >= f[i]){ //finish time is greater than previous activity start time.
			cout << j << " ";
			i = j;
		}
	}
	cout << endl;
}

int main(){
	int s[] = {1, 3, 0, 5, 8, 5};
	int f[] = {2, 4, 6, 7, 9, 9}; //activities are already sorted by their finish times.
	int n = sizeof(s)/sizeof(s[0]);
	
	printMaxActivities(s, f, n);
	
	return 0;
}