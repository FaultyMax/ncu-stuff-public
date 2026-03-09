
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct osoba{

  int wiek;
  int pesel;
  char plec;

};

void list_info(osoba& person);

int main(){

  osoba array[100];
  
  srand(time(0));

  for(int i = 0 ; i < 100 ; i++){
    array[i].wiek = rand() % 50 + 15;
    array[i].pesel = rand() %  897561365 + 1000505000;
    if( rand() % 100 > 50 ){ array[i].plec = 'F'; }
    else{ array[i].plec = 'M'; }
  }

  list_info(array[45]);
  list_info(array[85]);

  osoba* tmp = nullptr;
  int max_age = 0;
  
  for(int j = 0 ; j < 100 ; j++){

    if(array[j].plec == 'F'){ if(array[j].wiek >= max_age){ max_age = array[j].wiek; tmp = &array[j]; }}
  }

  if(tmp == 0){ cout << "Brak kobiet!" << endl; }
  else{ list_info(*tmp); }
  
  return 0;
  
}

void list_info(osoba& person){

  cout << person.plec << "_" << person.pesel << "_" << person.wiek << endl;

}

