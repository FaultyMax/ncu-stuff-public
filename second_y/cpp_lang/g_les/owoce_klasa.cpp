
#include <iostream>
#include <string>
#include "owoce_head.h"

using namespace std;

void owoc::wypisz(){
  cout << "owoc";
}

void jablko::wypisz(){
  owoc::wypisz();
  cout << "->jablko";
}

void cytrus::wypisz(){
  owoc::wypisz();
  cout << "->cytrus";
}

void pomarancz::wypisz(){
  cytrus::wypisz();
  cout << "->pomarancz";
}

void limonka::wypisz(){
  cytrus::wypisz();
  cout << "->limonka";
}

void truskawka::wypisz(){
  owoc::wypisz();
  cout << "->truskawka";
}

owoc::owoc(){

  this->kolor = "NULL";

}

owoc::owoc(string kolor){

  this->kolor = kolor;

};

jablko::jablko()
  : owoc()
{
  this->gatunek = gatunek_jablka::nieznany_jab;
}

jablko::jablko(string kolor)
  : owoc(kolor)
{
  this->gatunek = gatunek_jablka::nieznany_jab;
}

jablko::jablko(string kolor,gatunek_jablka gatunek)
  : owoc(kolor)
{
  this->gatunek = gatunek;
}

cytrus::cytrus()
  : owoc(){}

cytrus::cytrus(string kolor)
  : owoc(kolor){}

pomarancz::pomarancz()
  : cytrus()
{
  witamina_C = 0;
}

pomarancz::pomarancz(string kolor)
  : cytrus(kolor)
{
  witamina_C = 0;
}

pomarancz::pomarancz(string kolor,double witamina)
  : cytrus(kolor)
{
  witamina_C = witamina;
}

limonka::limonka()
  : cytrus()
{
  z_regionu = "NULL";
}

limonka::limonka(string kolor)
  : cytrus(kolor)
{
  z_regionu = "NULL";
}

limonka::limonka(string kolor, string region)
  : cytrus(kolor)
{
  z_regionu = region;
}

truskawka::truskawka()
  : owoc()
{
  odmiana = odmiana_truskawki::nieznany_trus;
}

truskawka::truskawka(string kolor)
  : owoc(kolor)
{
  odmiana = odmiana_truskawki::nieznany_trus;
}

truskawka::truskawka(string kolor, odmiana_truskawki odmiana)
  : owoc(kolor)
{
  this->odmiana = odmiana;
}
