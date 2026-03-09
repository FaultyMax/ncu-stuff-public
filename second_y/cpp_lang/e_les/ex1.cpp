#include <iostream>
#include <string>
#include "ex1_class.h"

using namespace std;

int main(){

  Language basic(8);
  
  basic.display_chars();

  Language copy = basic;

  copy.display_chars();

  Language my_dict("abcyeafaokz");

  my_dict.display_chars();
  cout << my_dict.testuj("faktyczne slowo") << endl;
  cout << copy.testuj("aa b") << endl;
  cout << basic.testuj("aa bewsacz") << endl;
  cout << basic.testuj("aa eeeffgg g") << endl;

  cout << basic.tested << endl;
  
  /*
  Language int_dict(10);
  int_dict.display_chars();

  Language int_dict2(26);
  int_dict2.display_chars();

  Language int_dict3(50);
  int_dict3.display_chars();
  */
  return 0;
}


/*
a. prywatną, dynamicznie alokowaną tablicę charów.
b. Konstruktor kopiujący poprawnie zarządzający pamięcią
c. Konstruktor konwertujący z int – ma alokować tablicę o danym rozmiarze i
wypełnić ją kolejnymi literami angielskiego alfabetu od a-z. Jeśli podany int jest za
duży, skróć go do poprawnej wartości.
d. Konstruktor konwertujący z const char * – ma alokować tablicę o rozmiarze
przekazanego napisu i wypełniać go przekazanymi znakami. Akceptujemy
wszystkie znaki przekazane w napisie.
WE AINT DOING THAT, GIMME i.
i. Wariant trudniejszy – zaakceptuj tylko te znaki, które się nie powtarzają,
na przykład Jezyk(”abcaaaaa”) ma utworzyć 3-elementową tablicę
przechowującą znaki ‘a’, ‘b’ i ‘c’.
e. Metodę „testuj” przyjmującą string i zwracającą true, jeśli z liter w słowniku da
się utworzyć napis lub false w przeciwnym wypadku.
Ponadto funkcja „testuj” ma zliczać za pomocą publicznej zmiennej ile testów
zostało wykonanych przez WSZYSTKIE utworzone słowniki.
f. Destruktor
W funkcji main utwórz trzy słowniki – każdy innym konstruktorem (konwertujący z
int, konwertujący z const char* i kopiującym) i przetestuj w nich kilka słów.
Na koniec wypisz ile porównań zostało wykonanych.
*/
