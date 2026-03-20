
#include <iostream>

using namespace std;

struct matrix{

	int rows;
	int columns;
	int** data;
	
};

matrix create(int rows, int columns);
void release(matrix* M);
void print(matrix M);

int main(){
	
	int m,n;
	
	cin >> m >> n;
	
	matrix test = create(m,n);
	
	print(test);
	
	release(&test);
	
	return 0;
}

matrix create(int rows, int columns){
	
	matrix new_m;
	
	if(rows <= 0 or columns <= 0){ 
	
		cout << "Invalid arguments! Empty matrix returned." << endl;
		
		new_m.rows = 0;
		new_m.columns = 0;
		new_m.data = nullptr;
		
		return new_m;
		
	}
	
	new_m.rows = rows;
	new_m.columns = columns;
	
	new_m.data = new int*[rows];
	
	for(int i = 0 ; i < rows ; i++){
		new_m.data[i] = new int[columns];
	}
	
	for(int i = 0; i < rows ; i++){
		for(int j = 0 ; j < columns ; j++){
			new_m.data[i][j] = 1+i+j;
			//cout << new_m.data[i][j] << " ";
		}
		//cout << endl;
	}

	cout << "Generating " << rows << " by " << columns << " matrix." << endl;
	
	return new_m;
	
}

void release(matrix* M){
	
	cout << "releasing memory..." << endl;
	
	for(int i = 0 ; i < M->rows ; i++){
		delete[] M->data[i];
	}
	delete[] M->data;
	
	M->rows = 0;
	M->columns = 0;
	M->data = nullptr;
	
}

void print(matrix M){
	
	for(int i = 0 ; i < M.rows ; i++){
		for(int j = 0 ; j < M.columns ; j++){
			cout << M.data[i][j] << " ";
		}
		cout << endl;
	}
	
}
