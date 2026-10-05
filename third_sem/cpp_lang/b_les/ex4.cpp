
#include <iostream>
#include <string>

using namespace std;

int main(){
	
	string input;
	
	getline(cin,input);
	
	int len = 0;
	int point = 0;
	
	for(int i = 0 ; i < (int)input.length() ; i++){
	
		//cout << input.length() << " " << i << endl;
		
		if(input[i] != ' ' ){
			len++;
		} else {
			cout << input.substr(point,len) << endl;
			point = (i+1);
			len = 0; 
		}
		
		//cout << i << " ";
		
		if(i+1 == (int)input.length()){ cout << input.substr(point,len) << endl; }
	}
	
	return 0;
}
