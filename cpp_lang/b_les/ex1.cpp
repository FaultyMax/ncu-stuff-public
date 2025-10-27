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
	
	for(int i = 0; i < (int)napis.length() ; i++){
		
		int ascii = napis[i];
		
		if(ascii >= 'A' and ascii <= 'Z'){
			tab[ascii-'A']++;
		} else if ( ascii >= 'a' and ascii <= 'z'){
			tab[ascii-'a']++;
		}
	}
	
	int max = 0;
	int index = 0;
	char output = 0;
	
	for(int i = 0 ; i < 26 ; i++){
		
		if(tab[i] > max){ max = tab[i]; index = i; }
		
	}
	
	output += index+'a';
	
	cout << (char)output << endl;
	
}
