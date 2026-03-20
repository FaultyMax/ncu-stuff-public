
#include <iostream>
#include "ulamek.h"

ulamek::ulamek(){

  licznik = 0;
  mianownik = 1;
  
}

ulamek::ulamek(int a, int b){

  licznik = a;
  if(b == 0){ // traktujemy to jakby ulamek rownal sie zero.
    licznik = 0;
    mianownik = 1; 
  }else{
  mianownik = b; 
  }
}

ulamek::ulamek(const ulamek &og){

  this->licznik = og.licznik;
  this->mianownik = og.mianownik;

}

ulamek ulamek::operator*(ulamek inny){
  return ulamek(this->licznik * inny.licznik,this->mianownik * inny.mianownik);
}

int& ulamek::operator[](int i){
  if (i == 0){ return licznik; }
  else if (i == 1){ return mianownik; }
  return licznik;
}

bool ulamek::operator<(const ulamek n2){

  bool val;

  if( this->licznik > n2.licznik ){
    val = 0;
  }
  else if ( n2.licznik > this->licznik ) { val = 1; }
  return val;
}

std::ostream& operator<<(std::ostream &stream, const ulamek &og){

  stream << og.licznik << "/" << og.mianownik;
  return stream;

}
