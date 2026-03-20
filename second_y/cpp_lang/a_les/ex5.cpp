
#include <iostream>

using namespace std;

int main(){
	
	int j = 0;
	
	for(int i = 0 ; i < 5 ; i++){
		
		cout << j++ << " ";
		
	}
	
	cout << endl; j = 0;
	
		for(int i = 0 ; i < 5 ; i++){
		
		cout << ++j << " ";
		
	}
	
	// ten kod mniej więcej tłumaczy różnice.
	
	// x++ -> użyj zmiennej, potem inkrementuj
	// ++x -> inkrementuj, potem użyj zmiennej
	
}
