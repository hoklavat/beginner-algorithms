//06-Recursion(HanoiTowers)

#include <iostream>
using namespace std;

void HanoiTowers(int n, char rodFrom, char middleRod, char rodTo){
	if(n == 1){
		cout << "Plate 1 from " << rodFrom << " to " << rodTo << endl;
		return;
	}
	HanoiTowers(n - 1, rodFrom, rodTo, middleRod);
	cout << "Plate " << n << " from " << rodFrom << " to " << rodTo << endl;
	HanoiTowers(n - 1, middleRod, rodFrom, rodTo);
}

int main(){		
	cout << "- Towers of Hanoi with 3 Disks -" << endl;
	HanoiTowers(3, 'A', 'B', 'C');
	
	return 0;
}