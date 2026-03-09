#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>

#define MIN 1000000

using namespace std;

void text_prepare(ifstream& f, unordered_map<string, int>& dict); // tokenizacja i tworzenie nowego słownika dla danego pliku
void display_menu(string fname); // wyświetlanie menu
void word_stats_minmax(const unordered_map<string, int>& dict);
void top_letters(const unordered_map<string, int>& dict);
void get_letters(const unordered_map<string, int>& dict);

int levenshtein(const string word1, const string word2);

int ASCII_TABLE[26] = {0};
bool ASCII_filled = false;

int main(int argc, char** argv){
	
	ifstream file;
	string file_name;
	int x;

	unordered_map<string, int> Dict;
	
	if(argc == 2){
		// plik podany jako parametr
		file.open(argv[1]);
		if (!file.is_open()){
        	cout << "Nie udało się otworzyć pliku." << endl;
        	return -1;
    	}
    	file_name = argv[1];
	} else { 
		cout << "Podaj ścieżkę do pliku: ";
		cin >> file_name;
		file.open(file_name);
		if (!file.is_open()){
        	cout << "Nie udało się otworzyć pliku." << endl;
        	return -1;
    	}
	}

	// funkcja z normalizacja + tokenizacja i gdzieś tu załadować słownik z tekstu
	text_prepare(file, Dict); 

	char action;
	string word;
	string input;
	bool active = true;
	int distance;

	// '4' słowa o najmniejszej odległosci mają się pokazać ( załóżmy, że do <= 2 )

	while(active){

		display_menu(file_name);

		cin >> action;

		switch(action){
		
			case '1':
				
				if(file.is_open()){ file.close(); }
				cout << "Podaj nazwe nowego pliku: "; cin >> file_name; 
				file.open(file_name);
				if (!file.is_open()){
        			cout << "Nie udało się otworzyć pliku. Brak zamiany" << endl;
        			return -1;
    			}
    			cout << "zmiana pliku udała się. Tworzę nowy słownik..." << endl;
    			text_prepare(file, Dict); 
				break;
				
			case '2':
				
				file.clear();
    			file.seekg(0, ios::beg);

    			cout << "\t --- WYŚWIETLENIE " << file_name << " ---" << endl;
    			cout << file.rdbuf();

				cout << endl << endl;
				break;
			case '3':

				cout << "Wyświetlone zostanie najczęściej i najrzadziej występujące słowo:" << endl;
				
				word_stats_minmax(Dict);

				cout << endl << "Top 3 najczęstszych znaków: " << endl;

				top_letters(Dict);

				cout << endl << "Wpisz słowo lub znak, żeby zobaczyć ilość występowań. \"0\" by wyjść." << endl;

				while(input != "0"){

					cin >> input;

					if(input.length() > 1){
						
						auto it = Dict.find(input);

						if(it != Dict.end()){
							cout << "ilość występowań: " << it->second << endl;
						} else { cout << "nie znaleziono." << endl; }

					} else if (input.length() == 1 and input != "0"){
						
						get_letters(Dict);

						if(input[0] >= 'a' and input[0] <= 'z'){
							cout << "Występowanie znaku: " << input[0] << " ( " << ASCII_TABLE[(int)input[0]-'a'] << " )" << endl;
						} 

					}
				}

				input = "";

				break;
			case '4':
				
				cout << "Wpisz frazę: "; cin >> input;

				cout << "Sugerowana poprawka/i: " << endl;

				// szukam po słowniku z levenshteinem

				for (auto& x : input) {
        			x = tolower(x);
    			}			

				for (auto i : Dict) { 

					word = i.first;

					distance = levenshtein(input,i.first);

					if(distance > 0 and distance < 3){
						cout << "czy miałeś na myśli... " << i.first << endl;
					}

				}

				cout << endl;

				input = "";

				break;
			case '5':
				cout << "zakończono prace programu" << endl;
				active = false;
				break;
			default:
				cout << "wybierz poprawną opcje |1|2|3|4|5|" << endl;
				break;
		
		}
		
	}

	if(file.is_open()){ file.close(); }

	return 0;

}

void display_menu(string fname){

	cout << "\t--- ANALIZATOR TEKSTU ---" << endl << endl;
	cout << "pracujemy na pliku: " << fname << endl;

	cout << "1. zmień plik" << endl;
	cout << "2. wyświetl zawartość" << endl;
	cout << "3. statystyki tekstu" << endl;
	cout << "4. sugeruj poprawki" << endl;
	cout << "5. zakończ program" << endl;

}

void text_prepare(ifstream& f, unordered_map<string, int>& dict){

	// być może wyświetlanie najmniej powtarzającego się słowa nie ma sensu
	// trudno niech zostanie

	string word;

	dict.clear();
	for (int& x : ASCII_TABLE) {x = 0;}
	ASCII_filled = false;

	while(f >> word){

		for(int i = 0 ; i < word.length() ; i++){
			if(word[i] >= 'A' and word[i] <= 'Z'){
				word[i] += 32;
			}
		}

		for(int i = 0 ; i < word.length();){
			if(!(word[i] >= 'a' and word[i] <= 'z')){
				word.erase(i,1);
			} else {
				i++;
			}
		}

		if (!word.empty()) {
            dict[word]++;  
        }
	}

	//for (auto i : dict) {
    //   cout << i.first << ": " << i.second << endl; }

}

// wszystkie funckje do sugerowania

int levenshtein(const string word1, const string word2){

	int m = word1.length(); int n = word2.length();

	vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

	for(int i = 0 ; i <= m ; i++){ dp[i][0] = i; }
	for(int i = 0 ; i <= n ; i++){ dp[0][i] = i; }

	for(int i = 1 ; i <= m ; i++){
		for(int j = 1 ; j <= n ; j++) {
			if(word1[i-1] == word2[j-1]){
				dp[i][j] = dp[i-1][j-1]; // znaki takie same
			}
			else {
				dp[i][j] = 1 + min(
					dp[i][j-1], // insert
					min(
						dp[i-1][j], // remove
						dp[i-1][j-1] // replace
				));
			}
		}
	}

	return dp[m][n];

}

// wszystkie funkcje do analizy tekstu

void word_stats_minmax(const unordered_map<string, int>& dict){

	string max_word;
	string min_word;

	int max_count = 0;
	int min_count = MIN;

	for (auto i : dict) {
		//cout << i.first << ": " << i.second << endl; 
		string word = i.first;
		int count = i.second;

		if(count > max_count){
			max_count = count;
			max_word = word;
		}

		if(count < min_count){
			min_count = count;
			min_word = word;
		}
	}

	cout << "Najczęstsze słowo: " << max_word << " ( ilość: " << max_count << " )" << endl;
	cout << "Najrzadsze słowo: " << min_word << " ( ilość: " << min_count << " )" << endl;

}

void top_letters(const unordered_map<string, int>& dict){

	char top1 = 0, top2 = 0, top3 = 0;
	int max1 = 0, max2 = 0, max3 = 0;

	get_letters(dict);

	for (int i = 0; i < 26; i++) {

	    int count = ASCII_TABLE[i];
	    char letter = 'a' + i;

	    if (count > max1) {
	        max3 = max2; top3 = top1;
	        max2 = max1; top2 = top1;
	        max1 = count; top1 = letter;
	    }
	    else if (count > max2) {
	        max3 = max2; top3 = top2;
	        max2 = count; top2 = letter;
	    }
	    else if (count > max3) {
	        max3 = count; top3 = letter;
	    }
	}

	cout << "TOP 1 -> " << top1 << " (ilość " << max1 << " )" << endl;
	cout << "TOP 2 -> " << top2 << " (ilość " << max2 << " )" << endl;
	cout << "TOP 3 -> " << top3 << " (ilość " << max3 << " )" << endl;

}

void get_letters(const unordered_map<string, int>& dict){

	if(ASCII_filled == false){

		for (auto i : dict) {
		
			string word = i.first;
			int count = i.second;

			for(int i = 0 ; i < word.length() ; i++){
				ASCII_TABLE[(int)word[i]-'a'] += count;
			}

		}

		ASCII_filled = true;

	}

}