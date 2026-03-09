
#include <iostream>

using namespace std;

int main(){
	
	int n; cin >> n;
	
	int *tab = new int [n];
	
	if(n < 2){return 0;}
	
	tab[0] = 2; tab[1] = 5;
	
	for(int i = 2; i < n; i++){
	
		tab[i] = tab[i-2] + tab[i-1];
		
	}
	
	for( int i = (n-1) ; i >= 0 ; i-- ) { 
	
		cout << tab[i] << endl;
		
	}
	
	delete[] tab;
	
	return 0;
	
}
