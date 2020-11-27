//03-DataStructures(TwoDimensionArray)

#include <iostream>
#include <climits>
using namespace std;

class TwoDimensionArray{
private:
	int *data;
	int rows;
	int columns;
	
public:
	TwoDimensionArray(): TwoDimensionArray(5, 5){}

	TwoDimensionArray(int rows, int columns){
		this->data = new int[rows * columns];
		this->rows = rows;
		this->columns = columns;
		for(int r = 0; r < rows; r++){
			for(int c = 0; c < columns; c++){
				*(data + r*rows + c) = INT_MIN;
			}
		}
	}
	
	~TwoDimensionArray(){
		delete data;
	}
	
	void Traverse(){
		for(int r = 0; r < rows; r++){
			for(int c = 0; c < columns; c++){
				cout << r << ":" << c << "(" << *(data + r*rows + c) << "), ";
			}
			cout << endl;
		}
		cout << endl;
	}
	
	void Insert(int r, int c, int value){
		if(*(data + r*rows + c) == INT_MIN) *(data + r*rows + c) = value;
	}
	
	int GetValue(int r, int c){
		return *(data + r*rows + c);
	}
	
	int* Search(int value){
		int *loc = new int[2];;
		for(int r = 0; r < rows; r++){
			for(int c = 0; c < columns; c++){
				if(*(data + r*rows + c) == value) {
					loc[0] = r;
					loc[1] = c;
					return loc;
				}
			}
		}
		loc[0] = -1;
		loc[1] = -1;
		return loc;
	}
	
	void Delete(int r, int c)
	{
		if(*(data + r*rows + c) != INT_MIN) *(data + r*rows + c) = INT_MIN;
	}

};

int main(){
	//Create
	TwoDimensionArray a{5, 5};
	
	//Insert
	a.Insert(3, 3, 10);
	
	//Traverse
	a.Traverse();
	
	//Access
	cout << "Before Delete -> Value at Row 3 and Column 3: " << a.GetValue(3, 3) << endl;
	
	//Delete
	a.Delete(3, 3);
	cout << "After Delete -> Value at Row 3 and Column 3: " << a.GetValue(3, 3) << endl << endl;
	
	//Search
	a.Insert(4, 4, 20);
	a.Traverse();		
	int *l = a.Search(20);
	cout << "Location of 20: (" << l[0] << ", " << l[1] << ")" << endl;
	
	return 0;
}