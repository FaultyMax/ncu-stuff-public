#include <iostream>

using namespace std;

class movie{

  public:

    string title;
    int release_date;
    int length;
    float* ptr;

    movie(){
      release_date = 2000;
      ptr = new float[release_date];
    };
    movie(string name){
      title = name;
      release_date = 2000;
      ptr = new float[release_date];
    };
    movie(string name,int date, int len){
      title = name;
      release_date = date;
      length = len;
      ptr = new float[release_date];
    };
    ~movie(){ delete[] ptr;};
    
    bool zXXIwieku(){
      if(release_date > 2000) return true;
      return false;
    };

    void wypiszDane(){
      cout << "TYTUŁ:  " << title << endl;
      cout << "PREMIERA:  " << release_date << endl;
      cout << "DŁUGOŚĆ:  " << length << endl;
    }
  
};

int main(){

  movie* arr[20];

  for(int i = 0 ; i < 20 ; i++){

    string name = "Film_" + to_string(i);
    arr[i] = new movie(name);
    cout << arr[i]->title << endl;
  }

  for(int i = 0 ; i < 20 ; i++){

    delete arr[i];
    
  }
  
  return 0;
}

/*

Utwórz klasę reprezentującą film. Ma ona posiadać następujące elementy:
a. publiczne pola:
i. string tytul
ii. rok premiery
iii. czas trwania w minutach
iv. wskaźnik na float
b. publiczne metody:
i. bool zXXIwieku(), która zwróci true, jeśli film powstał po 2000 roku.
ii. void wypiszDane(), która wypisze na ekran wszystkie informacje o filmie.
iii. Trzy konstruktory, bezparametrowy; przyjmujący tylko tytuł; przyjmujący trzy
parametry.
1. Jeśli nie jest to podane, konstruktory mają ustawiać domyślny rok
premiery na 2000.
2. Każdy konstruktor alokuje dynamiczmie tablicę floatów o takim
samym rozmiarze jak rok premiery i przypisuje ją do wskaźnika na
float.
iv. Destruktor poprawnie zwalniający pamięć
c. W funkcji main:
i. Utwórz wskaźnik na obiekty typu Film i zaalokuj miejsce na 20 obiektów
ii. Korzystając z dowolnego konstruktora utwórz 20 obiektów. Filmy niech
nazywają się Film_i, gdzie i to indeks w tablicy.
iii. Usuń tablicę za pomocą operatora delete i delete[]. Jaka jest różnica?

*/
