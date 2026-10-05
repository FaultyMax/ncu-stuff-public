
#include <iostream>

using namespace std;

int main(){
	
	int wynik = 0;
	int input;
	
	for(int i = 0 ; i < 10 ; i++){
		cin >> input;
		wynik += input;
	}
	
	cout << wynik << endl;
	
	return 0;
}
