#include <iostream>

using namespace std;

int main(){
	
	int n; cin >> n;
	
	for(int i = 0; i < n-1 ; i++){
		
		for(int m = 0; m < 2 ; m++){
		
			for(int j = 0 ; j < n-i-1 ; j++){
				cout << " ";
			}
			
			for(int k = 0 ; k < (2*i)+1 ; k++){
				cout << "*";
			}
			
			for(int l = 0 ; l < n-i-1 ; l++){
				cout << " ";
			}
			
			cout << endl;
			
		}
		
	}
	
	for(int k = 0 ; k < (2*n)-1 ; k++){
				cout << "*";
	}
	cout << endl;
	
	return 0;
}
