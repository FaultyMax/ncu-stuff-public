
#include <iostream>

using namespace std;

int main(){
	
	int x;
	
	cin >> x;
	
	for(int i = 1 ; i <= x ; i++){
		
		if (i % 3 == 0 or i % 5 == 0) { cout << i << endl; }
		
	}
	
	return 0;
}
