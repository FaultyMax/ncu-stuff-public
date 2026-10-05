
#include <iostream>
#include <string>

using namespace std;

int point(string &input);

int main(){
	
	int max = 0;
	string winner;
	string napis;
	
	for(int i = 0 ; i < 4 ; i++){
		
		cin >> napis;
		
		int out = point(napis);
		
		if(out > max){
			max = out;
			winner = napis;
		}
		
	}
	
	cout << winner << endl;
	
}

int point(string &input){
	
	int output = 0;
	
	for(int i = 0 ; i < (int)input.length() ; i++){
		
		output += input[i];
		
	}
	
	return output;	
}
