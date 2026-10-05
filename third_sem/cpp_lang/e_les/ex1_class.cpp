#include <iostream>
#include <string>
#include <cstring>
#include "ex1_class.h"

using namespace std;

const int eng_a = ('z'-'a')+1;

Language::Language(){
  this->size = 3;
  this->characters = new char[size];
  this->characters[0] = 'a'; this->characters[1] = 'b'; this->characters[2] = 'c';
}

Language::Language(const Language &og){
  cout << "Tworze kopię..." << endl;
  this->size = og.size;
  this->characters = new char[size];
  for(int i = 0 ; i < size ; i++){
    
    this->characters[i] = og.characters[i];
    
  }
}

Language::Language(unsigned int value){

  this->size = value;
  
  if(size > eng_a){
    this->size = eng_a;
  }
  
  this->characters = new char[size];

  for(int i = 0 ; i < this->size ; i++){
    
    this->characters[i] = (char)('a'+i);
    
  }
   
}

Language::Language(const char* arr){

  int temp_tab[eng_a] = {0}; // chyba zgodne ze standardem, jeżeli eng_a to const?
  string temp = "";
  this->size = 0;
  
  for (int i = 0; i < strlen(arr); i++){
    temp_tab[arr[i]-'a'] += 1;
  }
  for(int i = 0 ; i < eng_a ; i++){
    if(temp_tab[i] >= 1){
      size++;
      temp += (char)(i+'a');
    }
  }

  this->characters = new char[size];
  for(int i = 0 ; i < this->size ; i++){
    
    this->characters[i] = temp[i];
    
  }
}

bool Language::testuj(string word){

  int temp_tab[eng_a] = {0};

  for(int i = 0 ; i < this->size ; i++){
    temp_tab[(characters[i]-'a')] = 1;
  }

  this->tested++;
    
  for(int i = 0 ; i < word.length() ; i++){
    if(temp_tab[word[i]-'a'] == 1 or word[i] == ' '){
      //cout << word[i] << " ";
    } else { return false; }
  } 
  return true;
}

void Language::display_chars(){

  cout << "CHARACTERS: ";
  for(int i = 0 ; i < size ; i++){
    cout << characters[i] << " ";
  }
  cout << endl;
}

Language::~Language(){

  delete[] characters; 

}

int Language::tested = 0;
