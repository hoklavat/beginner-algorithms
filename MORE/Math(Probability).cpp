//Math(Probability)
//Task: write function that generates one of 3 numbers according to given probabilities.

#include <iostream>
using namespace std;

int generate(int x, int y, int z, int px, int py, int pz){ //px is probability of x.
	int r = rand()%100+1;
	if (r <= px) return x;
	if (r <= (px+py)) return y;
	else return z;
}

int main(){
	int cx{}, cy{}, cz{};
	
	for(int i = 0; i < 1000; i++){
		switch(generate(1, 2, 3, 15, 60, 25)){ //px + py + pz = 100. 3 events in sample space.
			case 1: cx++; break;
			case 2: cy++; break;
			case 3: cz++; break;
			default: break;
		}
	}
	
	std::cout << "Occurences -> x:" << cx << ", y:" << cy << ", z:" << cz << std::endl; 
}
