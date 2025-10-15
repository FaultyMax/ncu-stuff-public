#include <iostream>
#include <string>

using namespace std;

int main(){
	
	int tab[26];
	
	for(int i = 0 ; i < 26 ; i++){
		
		tab[i] = 0;
		
	}
	
	string napis;
	
	cin >> napis;
	
	for(int i = 0; i < napis.length() ; i++){
		
		cout << napis[i] << endl;
	
		tab[(int)napis[i] - 'a']++;
		
		cout << tab[(int)napis[i] - 'a'] << endl;
		
	}
	
	
	
}
