
#include <iostream>

using namespace std;

void sort_wstaw(int tab[], int n);
void swap(int* a, int* b); 

int main(){
	
	int tab[1000];
	
	int n;
	
	int input;
	
	cin >> n;
	
	for(int i = 0 ; i < n ; i++){
		
		cin >> input;
		
		tab[i] = input;
		
	}
	
	// jakies sortowanie elo
	
	sort_wstaw(tab,n);
	
	for(int i = 0 ; i < n ; i++){
		
		if( i == n-1 ){ cout << tab[i]; }
		else{
			cout << tab[i] << ", ";
		}
	}
	
	return 0;
}

void swap(int* a, int* b){
	
	int tmp = *a;
	*a = *b;
	*b = tmp;
	
}

void sort_wstaw(int tab[], int n){

	if ( n == 1 ) { return; }
	
	sort_wstaw(tab,n-1);
	
	// wstaw tab[n-1] na wlasciwe miejsce

	for(int i = n-1 ; i > 0 ; i--){
		
		if(tab[i] < tab[i-1]){
			swap(&tab[i],&tab[i-1]);
		}
		
	} 
	
}

// 5
// -3 0 6 10 2

/*

	-3 0 6 10 2
	



*/











