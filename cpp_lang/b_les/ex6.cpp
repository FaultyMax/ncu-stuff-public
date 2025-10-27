
#include <iostream>

using namespace std;

int** generate_matrix(int m, int n);

int main(){
	
	int m,n;
	
	cin >> m >> n;
	
	int** matrix = generate_matrix(m,n);
	
	for(int i = 0 ; i < m ; i++){
		for(int j = 0 ; j < n ; j++){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	
	for(int i = 0 ; i < m ; i++){ delete[] matrix[i]; }
	delete[] matrix;
	return 0;
}

int** generate_matrix(int m, int n){
	
	int** matrix = new int*[m];
	
	for(int i = 0 ; i < m ; i++){
	
		matrix[i] = new int[n];
		
	}
	
	for(int i = 0 ; i < m ; i++){
		for(int j = 0 ; j < n ; j++){
			if( i == j ){ matrix[i][j] = 0; }
			else{ matrix[i][j] = 1; }
		}
	}
	
	return matrix;
	
}
