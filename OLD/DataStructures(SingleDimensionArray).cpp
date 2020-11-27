//02-DataStructures(SingleDimensionArray)

#include <iostream>
#include <climits>
using namespace std;

class SingleDimensionArray{
private:
	int *data;
	int size;
	
public:
	SingleDimensionArray(): SingleDimensionArray(10){}

	SingleDimensionArray(int s){
		size = s;
		data = new int[size];
		for(int i = 0; i < size; i++){
			data[i] = INT_MIN; //data[index] = *(data+index)
		}		
	}
	
	~SingleDimensionArray(){
		delete data;
	}
	
	void Traverse(){
		cout << "[ ";
		for(int i = 0; i < size; i++){
			cout << data[i] << " ";
		}
		cout << " ]" << endl;
	}
	
	void Insert(int index, int value){
		if(data[index] != INT_MIN){
			cout << "Error(Insert): Index " << index << " is already occupied." << endl;
		}
		else{
			data[index] = value;
		}
	}
	
	int GetValue(int index){
		return data[index];
	}
	
	int SearchValue(int value){
		for(int i = 0; i < size; i++){
			if(data[i] == value)
				return i;
		}
		return -1;
	}
	
	void DeleteValue(int index){
		data[index] = INT_MIN;
	}
};

int main(){
	//Create
	SingleDimensionArray a{5};
	
	//Insert
	for(int i = 0; i < 5; i++)
		a.Insert(i, i*10);
	
	a.Insert(0, 10); //already occupied.
	
	//Traverse
	cout << "Contents of Array: ";
	a.Traverse();	
	
	//Access
	cout << "Value at Index 3: " << a.GetValue(3) << endl;
	
	//Search
	cout << "Index of Value 30 is: " << a.SearchValue(30) << endl;
	
	//Delete
	a.DeleteValue(3);
	cout << "Value at Index 3 after Deletion: " << a.GetValue(3) << endl;
	
	return 0;
}