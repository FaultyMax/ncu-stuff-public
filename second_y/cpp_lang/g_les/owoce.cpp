
#include <iostream>
#include "owoce_head.h"

using namespace std;

int main(){

  owoc fruit;
  jablko apple;
  pomarancz orange;
  truskawka straw;
  
  fruit.wypisz(); cout << endl;

  apple.wypisz(); cout << endl;

  //cout << apple.kolor << " " << apple.gatunek << endl;

  orange.wypisz(); cout << endl;

  //cout << orange.kolor << " " << orange.witamina_C << endl;
  
  straw.wypisz(); cout << endl;

  limonka lime("zielony","Indonezja");

  lime.wypisz(); cout << endl;

  cout << lime.kolor << " " << lime.z_regionu << endl;
  
  return 0;

}
