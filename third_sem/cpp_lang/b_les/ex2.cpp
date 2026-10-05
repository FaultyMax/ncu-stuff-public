
#include <iostream>

using namespace std;

void func(float &a,float b){

	a += b;
	
}

int main(){

	float a,b;
	
	a = 2.5;
	b = 0.5;
	
	cout << a << " " << b << endl;
	
	func(a,b);
	
	cout << a << " " << b << endl;
	
	return 0;
}
