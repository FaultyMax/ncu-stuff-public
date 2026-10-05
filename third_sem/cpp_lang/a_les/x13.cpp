
#include <iostream>

using namespace std;

// na bieżąco? 

int main(){
	
	char input;
	
	do { 
	
		cin >> input;
	
		cout << (int)input << endl;
		
	} while ( input != 'Q' );
	
	return 0;
}
