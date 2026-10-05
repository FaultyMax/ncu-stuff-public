#include <iostream>

using namespace std;

enum species{

  DOG,
  CAT,
  MONKEY

};

class Animal{

  private:
    float weight;

  public:
    string name;
    int age;
    species kind;
    Animal* parent;

    Animal(){
      weight = 0;
      name = "bez nazwy";
      age = 0;
      kind = (species)0;
      parent = nullptr;
    };
    Animal(string name,int age,float weight,species kind,Animal* parent){
      this->name = name;
      this->age = age;
      this->weight = weight;
      this->kind = kind;
      this->parent = parent;
    };
    ~Animal(){
      cout << name << " " << age << endl;
    }
    void set_weight(float weight){
      this->weight = weight;
    };

    float show_weight(){ return weight; };
    
};

class Zoo{

  private:
    Animal* arr;
    int cap;
    int current_index;
  public:
    Zoo(int cap){
      current_index = 0;
      this->cap = cap;
      arr = new Animal[cap];
    };
    ~Zoo(){
      delete[] arr;
    };

    void add_animal(string name,int age,float weight,species kind,Animal* parent){
      if(current_index < cap){
        arr[current_index] = Animal(name,age,weight,kind,parent);
        current_index++;
      } else {
        cout << "Brak miejsca w Zoo!!" << endl;
      }
    };

    void add_animal(string name,int age,float weight,species kind,int index){
      if(current_index < cap){
        if(index >= 0 and index < cap and index < current_index){
          arr[current_index] = Animal(name,age,weight,kind,&arr[index]);
          current_index++;
        } else { cout << "Niepoprawny index." << endl; }
      } else {
        cout << "Brak miejsca w Zoo!!" << endl;
      }
    };
    
};

int main(){

  Zoo* noweZoo;
  noweZoo = new Zoo(5);
  noweZoo->add_animal("Mark",67,3.14,CAT,nullptr);
  noweZoo->add_animal("Bark",13,1.563,DOG,nullptr);
  noweZoo->add_animal("Dark",88,7.6,CAT,3);
  noweZoo->add_animal("Park",2,1.13,MONKEY,nullptr);
  noweZoo->add_animal("!!!",21,1.2121,DOG,1);
  noweZoo->add_animal("???",0,0,MONKEY,nullptr);
  noweZoo->add_animal("no space for you",3,3,CAT,nullptr);

  delete noweZoo;
  
  return 0;
}

/*
Utwórz klasę Zoo:
a. Prywatne pola
i. Dynamicznie alokowana tablica Zwierząt.
ii. Maksymalna liczba zwierząt w Zoo.
b. Publiczne metody:
i. Konstruktor przyjmujący maksymalną liczbę zwierząt w Zoo. Konstruktor ma
ustawiać poczatkowe wartości i alokować tablicę.
ii. Dodającą zwierzę do Zoo: utwórz dwa warianty tej funkcji:
1. Przyjmujący argumenty: nazwę, wiek, wagę, gatunek i wskaźnik na rodzica
2. Przyjmujący argumenty: nazwę, wiek, wagę, gatunek i indeks w Zoo.
Obie funkcje mają tworzyć obiekt Zwierzęcia na podstawie przekazanych parametrów
(jeśli zostanie wywołany wariant z indeksem zwierzęcia, to należy ustawić za rodzica zwierzę spod odpowiedniego indeksu). 
Jest tu dużo miejsca na obsługę błędów!
Jeśli nie ma miejsca na nowe zwierzę, wypisz stosowny komunikat i zakończ pracę metody.
iii. Destruktor poprawnie zwalniający pamięć. Przetestuj usunięcie tablicy za
pomocą operatora delete i delete[]. Jaka jest różnica?

5.

W funkcji main utwórz obiekt klasy Zoo. Następnie dodaj do niego kilka zwierząt. Spróbuj
dodać więcej zwierząt niż Zoo może pomieścić.
a. Wypisz informacje o zwierzętach (nazwa i wiek) – ponieważ tablica jest polem
prywatnym musisz w jakiś sposób rozwinąć klasę.

*/
