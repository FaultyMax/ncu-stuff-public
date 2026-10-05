#include <iostream>

using namespace std;

enum Species{

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
    Species kind;
    Animal* parent;

    Animal(){
      weight = 0;
      name = "bez nazwy";
      age = 0;
      kind = (Species)0;
      parent = nullptr;
    };
    Animal(string name,int age,float weight,Species kind,Animal* parent){
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

int main(){

  

  return 0;
}

/*
Utwórz klasę Zwierze
a. Prywatne pola:
i. Reprezentujące wagę.
b. Publiczne pola:
i. Reprezentujące imię i wiek.
ii. Enum reprezentujący gatunek
iii. Wskaźnik na obiekt klasy Zwierze wskazujący na rodzica zwierzęcia. Jeśli jest
nieznany to powinien mieć wartość nullptr.
c. Publiczne metody:
i. Konstruktor bezargumentowy, tworzący zwierze o nazwie „bez nazwy” z
wyzerowanymi pozostałymi argumentami.
ii. Konstruktor przyjmujący wszystkie wymagane argumenty, tj nazwę, wiek,
wagę, gatunek i wskaźnik na rodzica.
iii. Ustawiającą wagę.
iv. Zwracającą wagę.
v. Destruktor wypisujący imię i wiek zwierzęcia.
*/
