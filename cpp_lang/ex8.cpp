
#include <iostream>

using namespace std;

int main(){

	int liczba = 21;
	
	if( liczba >= -20 and liczba <= 30 ){
		cout << "malo" << endl;
	} else if( liczba >= 50 and liczba <= 75 ){
		cout << "duzo" << endl;
	} else { cout << "error" << endl;}
	
	return 0;
}
