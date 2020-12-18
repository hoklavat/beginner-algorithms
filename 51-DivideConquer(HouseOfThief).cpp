//51-DivideConquer(HouseOfThief)

#include <iostream>
using namespace std;

int maxLoot(int *h, int n){
	if (n == 0) return 0;
	if (n == 1) return h[0];
	if (n == 2) return max(h[0], h[1]);

	int d[n]; //maximum value so far.
	d[0] = h[0];
	d[1] = max(h[0], h[1]);

	for(int i = 2; i < n; i++) 
		d[i] = max(h[i]+d[i-2], d[i-1]);

	return d[n-1];
}

//more efficient.
int maxLoot2(int *h, int n){
    if (n == 0) return 0;
 
    int v1 = h[0];
    if (n == 1) return v1;
 
    int v2 = max(h[0], h[1]);
    if (n == 2) return v2;
 
    int m; //maximum value.
    for (int i = 2; i < n; i++){
        m = max(h[i]+v1, v2);
        v1 = v2;
        v2 = m;
    }
 
    return m;
}

int main(){
	int h[] = {6, 7, 1, 3, 8, 2, 4};
	int n = sizeof(h)/sizeof(h[0]);
	
	cout << "Maximum loot possible : " << maxLoot(h, n) << endl;
	cout << "Maximum loot possible : " << maxLoot(h, n) << endl;
	
	return 0;
}