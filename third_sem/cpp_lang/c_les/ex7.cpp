#include <iostream>

using namespace std;

enum cechy{

  GRA_KOOPERACYJNA = 1,
  GRA_STRATEGICZNA = 2,
  GRA_KARCIANA = 4,
  GRA_Z_FIGURKAMI = 8,
  GRA_IMPREZOWA = 16,
  GRA_DLA_DZIECI = 32,

};

void wypisz(int zestaw);
void usun(int& zestaw, cechy cecha);

int main(){

    int zestawcech = 0;

    zestawcech += cechy::GRA_KARCIANA+cechy::GRA_IMPREZOWA+cechy::GRA_KOOPERACYJNA;

    wypisz(zestawcech);

    usun(zestawcech,cechy::GRA_IMPREZOWA);

    wypisz(zestawcech);
    
  return 0;
}

void wypisz(int zestaw){

  // pytanie czy tzeba wypisać je na ekran?
  // jesli tak to potrzebujemy wielu ifów z ( zestaw & cechy::NAZWA ){ ... }
  // ale mi sie nie chce

  for(int i = 0 ; i < 32 ; i++){

    cout << ((zestaw >> i) & 1) << " ";
    
  }
  cout << endl;
}

void usun(int& zestaw, cechy cecha){

  zestaw = zestaw & ~cecha;

}

/*
Utwórz enum reprezentujący zestaw cech gry planszowej. Cechy te mogą występować w
dowolnej kombinacji. Przykładowe cechy to: gra_kooperacyjna, gra_strategiczna,
gra_karciana, gra_z_figurkami itd. Każda cecha ma być reprezentowana przez unikalną liczbę,
której reprezentacja bitowa zawiera dokładnie jeden bit ustawiony na 1.
a. Utwórz zmienną typu int reprezentującą zestaw cech gry, a następnie przypisz jej trzy
wybrane cechy, ustawiając odpowiednie bity na 1.
b. Utwórz funkcję przyjmującą int i wypisującą wszystkie zakodowane w niej cechy na
ekran.
c. Utwórz funkcję, która przyjmie int i cechę, a następnie usunie tą cechę z inta (czyli
ustawi odpowiedni bit na 0).
*/
