
#include <iostream>
#include <cstdlib>

using namespace std;

struct dtab{

	int n;
	int* data;
	
};

dtab create();
void append();
void remove();
void insert();
void print();
void sort();
void clear();

int main(){
	
	dtab first = create();
	
	cout << first.n << endl;
	
	return 0;
}

dtab create(int n){
	
	dtab created;
	
	created.data = new int[n];
	
	return created;
	
};
