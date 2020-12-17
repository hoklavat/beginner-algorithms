//49-DivideConquerAlgorithms(Maximum)

#include <iostream>
using namespace std;

int DAC_Max(int a[], int i, int l);
int DAC_Min(int a[], int i, int l);

int DAC_Max(int a[], int i, int l){ //array, index, length.
	int max;
	
	if(i >= l-2){
		if(a[i] > a[i+1])
			return a[i];
		else
			return a[i+1];
	}
	
	max = DAC_Max(a, i+1, l);

	if(a[i] > max)
		return a[i];
	else
		return max;
}

int DAC_Min(int a[], int i, int l){
	int min;
	
	if(i >= l-2){
		if(a[i] < a[i+1])
			return a[i];
		else
			return a[i+1];
	}

	min = DAC_Min(a, i+1, l);

	if(a[i] < min)
		return a[i];
	else
		return min;
}

int main(){
	int min, max, N;
	int a[7] = {70, 250, 50, 80, 140, 12, 14};

	max = DAC_Max(a, 0, 7);
	min = DAC_Min(a, 0, 7);
	
	cout << "Maximum number in given array: " << max << endl;
	cout << "Minimum number in given array: " << min << endl;
	
	return 0;
}