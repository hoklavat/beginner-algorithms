//06-Recursion(HanoiTowers)
//three rods, many disks with different sizes. smaller disk should always be placed on larger. 
//establish same settlement on last rod by moving uppermost disk on any rod.

#include <iostream>
using namespace std;

int i = 1;
void HanoiTowers(int n, char rodFrom, char middleRod, char rodTo){
	if(n == 1){
		cout << i++ << ": Plate 1 from " << rodFrom << " to " << rodTo << " (*)"<< endl;
		return;
	}
	HanoiTowers(n-1, rodFrom, rodTo, middleRod);
	cout << i++ << ": Plate " << n << " from " << rodFrom << " to " << rodTo << endl;
	HanoiTowers(n-1, middleRod, rodFrom, rodTo);
}

int main(){		
	cout << "- Towers of Hanoi with 3 Disks -" << endl;
	HanoiTowers(3, 'A', 'B', 'C');	
	return 0;
}