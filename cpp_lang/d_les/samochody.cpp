#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class vehicle{

  public:
  
    string name;
    float avg_speed;
    float avg_consumpt;
    float current_fuel;
    float road_left;
    int trunk_size;
    int* trunk;
    
    vehicle(){
    
      name = "Auto";
      avg_speed = 15 + rand() % 91;
      avg_consumpt = 4 + rand() % 7;
      current_fuel = 5 + rand() % 46;
      road_left = 50 + rand() % 350;
      
      trunk_size = 5 + rand() % 16;
      trunk = new int[trunk_size];
      for(int i = 0 ; i < trunk_size ; i++){ trunk[i] = rand() % 11; /*cout << i << ": " << trunk[i] << endl;*/}
    };

    vehicle(string name){
    
      this->name = name;
      avg_speed = 15 + rand() % 91;
      avg_consumpt = 4 + rand() % 7;
      current_fuel = 5 + rand() % 46;
      road_left = 50 + rand() % 350;
      
      trunk_size = 5 + rand() % 16;
      trunk = new int[trunk_size];
      for(int i = 0 ; i < trunk_size ; i++){ trunk[i] = rand() % 11; /*cout << i << ": " << trunk[i] << endl;*/}
    };

    vehicle(string name, float avg_speed, float avg_consumpt, float current_fuel, float road_left, int trunk_size){
    
      this->name = name;
      this->avg_speed = avg_speed;
      this->avg_consumpt = avg_consumpt;
      this->current_fuel = current_fuel;
      this->road_left = road_left;

      if( trunk_size < 5 ){ this->trunk_size = 5; }
      else if( trunk_size > 20){ this->trunk_size = 20; }
      else{ this->trunk_size = trunk_size; }
      trunk = new int[this->trunk_size];
      for(int i = 0 ; i < this->trunk_size ; i++){ trunk[i] = rand() % 11; /*cout << i << ": " << trunk[i] << endl;*/}
    };
    
    ~vehicle(){ delete[] trunk; }

    void display(){
      cout << name << " " << avg_speed << " " << avg_consumpt << " " << current_fuel << " " << road_left << endl;
    };
    
    bool will_arrive(){
      
      if(((road_left * avg_consumpt) / 100) <= current_fuel){ return true; }
      return false;
    };
    float max_distance(){
      
      return (100 * (current_fuel / avg_consumpt));

    };
    float arrival_time(){

      if(will_arrive() == false){ return -1; }

      return (road_left/avg_speed);
    
    };
    bool check_if_space(int n){
      
      for(int i = 0 ; i < trunk_size ; i++){

        if(trunk[i] == 0){n--;}
        
      }
      
      if(n <= 0){return true;}
      return false;
      
    };
    float avg_trunk_weight(){

      int tmp = trunk_size;
      
      float sum = 0;
      
      for(int i = 0 ; i < trunk_size ; i++){
        if(trunk[i] != 0){ sum += trunk[i]; }
        else{ tmp--; }
      }
      
      if(tmp == 0) return 0;
      
      return (sum/tmp);
      
    };

    
};

string whos_first(vehicle* first, vehicle* second);

int main(){

  srand(time(0));
  
  vehicle* arr[20];

  for(int i = 0 ; i < 15 ; i++){
    string new_name = "Auto" + to_string(i+1);
    arr[i] = new vehicle(new_name);
    #ifdef DEBUG
      arr[i]->display();
    #endif
  }
  for(int i = 15 ; i < 20 ; i++){
    arr[i] = new vehicle();
    #ifdef DEBUG
      arr[i]->display();
    #endif
  }

  int count = 0;
  vehicle* fastest = arr[0];
  vehicle* shortest_path = arr[0];
  
  for(int i = 0 ; i < 20 ; i++){
    if (arr[i]->will_arrive() == true){
      cout << "Pojazd " << arr[i]->name << " dojedzie do celu." << endl; count++;
    } else { 
      cout << "Pojazd " << arr[i]->name << " nie dojedzie do celu." << endl;
    }
    if(fastest->avg_speed <= arr[i]->avg_speed){
      fastest = arr[i];
    }
    if(shortest_path->max_distance() >= arr[i]->max_distance()){
      shortest_path = arr[i];
    }
  }

  if( count < 2 ){ cout << "nie znaleziono dwóch aut które dojądą do celu. Program umiera ze smutku." << endl; return -1; }
  
  vehicle* lucky1;
  vehicle* lucky2;

  int rand1, rand2;

  while(true){

    rand1 = rand() % 20;
    rand2 = rand() % 20;

    //cout << rand1 << " " << rand2 << endl;
    
    if(arr[rand1]->will_arrive() and arr[rand2]->will_arrive() and (rand1 != rand2)){ lucky1 = arr[rand1]; lucky2 = arr[rand2]; break; }
  
  }

  cout << lucky1->name << " VS " << lucky2->name << " wygrało - " << whos_first(lucky1,lucky2) << endl;

  count = 0;
  
  for(int i = 0 ; i < 20 ; i++){
    if (arr[i]->check_if_space(3)){
      cout << "Znaleziono samochód z 3 wolnymi miejscami. Waga: " << arr[i]->avg_trunk_weight() << endl; count++; break;
    }
  }

  if(count == 0){ cout << "Nie znaleziono samochodu z 3 wolnymi miejscami." << endl; }

  cout << "Najszybszy samochód: " << fastest->name << " Speed: " << fastest->avg_speed << endl;
  cout << "Najkrótszy zasięg: " << shortest_path->name << " Distance: " << shortest_path->max_distance() << endl;

  cout << "Pojazdy które dotrą do celu w więcej niż godzine:" << endl;

  for(int i = 0 ; i < 20 ; i++){
    if(arr[i]->arrival_time() > 1.00 and arr[i]->will_arrive()){
      cout << arr[i]->name << " w czasie " << arr[i]->arrival_time() << endl;
    }
  }
  
  for(int i = 0 ; i < 20 ; i++){
    delete arr[i];
  }
  
  return 0;
  
}

string whos_first(vehicle* first, vehicle* second){

  if(first->arrival_time() < second->arrival_time()){ return first->name;}
  else if(first->arrival_time() > second->arrival_time()){ return second->name;}
  else{ return "---REMIS---"; }
}



/*

Utwórz klasę reprezentującą samochód (w trakcie podróży) zawierającą pola:

nazwa - string
średnia prędkość w km/h - float
średnie spalanie / 100km - float
aktualna ilość paliwa - float
pozostały do przejechania dystans w km - float
rozmiar bagażnika - int o losowej wartości z zakresu [5; 20], mówi o tym ile rzeczy zmieści się w bagażniku
bagażnik reprezentowany przez dynamicznie zaalokowaną tablicę intów.
Rozmiar tablicy jest równy rozmiarowi bagażnika z poprzedniego punktu zadania.
Każde pole tej tablicy ustaw na losową wartość z zakresu [0; 10].
Każde pole oznacza wagę jednego przedmiotu w bagażniku. 0 oznacza brak przedmiotu w danym miejscu.
Oraz metody, które mają zrealizować następujące zadania:

Sprawdzić, czy na aktualnej ilości paliwa auto może dojechać do celu oraz zwrócić true jeśli tak, i false jeśli nie
Zwrócić dystans (w kilometrach) jaki może pokonać auto na aktualnej ilości paliwa
Zwrócić w jakim czasie auto dojedzie do celu. Jeśli nie jest to możliwe ze względu na brak paliwa zwróć -1
Sprawdzić, czy w bagażniku jest przynajmniej n wolnych miejsc; n ma zostać przekazane jako parametr metody. Metoda zwraca true jeśli są wolne miejsca i false, jeśli nie.
Obliczyć średnią wagę rzeczy z bagażnika (uwaga, pamiętaj, że wartość 0 oznacza brak przedmiotu w bagażniku!)
Ponadto utwórz konstruktory:

Przyjmujący parametr nazwa - pozostałe zmienne przydziel losowo (zadbaj o poprawność losowych danych, na przykład, żeby wartości nie były ujemne, albo prędkość była > 0).
Bezargumentowy, działający tak jak powyższy, z tą różnicą, że nazwa samochodu ma być ustawiona na "Auto".
Przyjmujący parametry nazwa, średnia prędkość, średnie spalanie, aktualna ilość paliwa, pozostały do przejechania dystans i rozmiar bagażnika.
(jeśli bagażnik będzie miał rozmiar spoza zakresu [5; 20] ustaw go na najbliższą poprawną wartość [np. rozmiar = 3 zostanie ustawiony na 5, rozmiar = 1034 zostanie ustawiony na 20])
Pamiętaj, żeby konstruktory utworzyły bagażnik!

Zwalnianiem pamięci przeznaczonej na bagażnik ma zająć się destruktor.

Nazwy pól i metod są dowolne. Proszę zadbać o to, żeby ich nazwy reprezentowały zadanie, które mają realizować oraz żeby dobrać poprawne typy zmiennych do realizacji zadań.

--------------------

Utwórz funkcję (ale nie metodę klasy!) która przyjmie za argumenty dwa wskaźniki na obiekty klasy samochód i zwróci nazwę samochodu, który jako pierwszy dojedzie do celu.
W przypadku remisu zwróć słowo "---REMIS---".

--------------------

W funkcji main:

Utwórz tablicę 20-tu wskaźników na samochód.
15 z nich utwórz pierwszym konstruktorem, pozostałe drugim (operator new zwraca wskaźnik)
Dla każdego z samochodów wypisz informacje czy dojedzie do celu
Wybierz parę samochodów, które dojadą do celu i sprawdź, który dojedzie szybciej (dowolnie obsłuż brak takiej pary)
Znajdź samochód o 3 pustych miejscach w bagażniku, jeśli nie ma takiego, wypisz stosowną informację, Jeśli jest, wypisz jego średnią wagę bagażu.
Znajdź najszybszy samochód
Znajdź samochód o najmniejszym zasięgu (taki, który może przejechać najkrótszy dystans)
Wypisz samochody, które dojadą do celu w czasie dłuższym niż 1 godzina.
Pamiętaj aby zwolnić pamięć (każdy samochód osobno!)
Wskazówka:

Pracuj na tablicy wskaźników na samochód. Praca z tablicą obiektów tak jak na zajęciach (Film filmy[100]) prawdopodobnie spowoduje, że program zakończy swoją pracę błędem. 
*/
