#include <iostream>

using namespace std;

class KontoBankowe{

  private:
    int kwota;

  public:

    KontoBankowe(){
      kwota = 0;
    }
    
    int sprawdzKwote(){
      return kwota;
    };
    void wplac(int kwota){
      this->kwota += kwota;
    };

    int wyplac(int kwota){
      kwota *= 1.05;
      if(this->kwota >= kwota){
        this->kwota -= kwota;
        return this->kwota;
      } else { return 0; }
    };
    
};

int main(){

  KontoBankowe mojeKonto;

  mojeKonto.wplac(50);

  cout << mojeKonto.sprawdzKwote() << endl;

  int wyplac = mojeKonto.wyplac(45);

  cout << mojeKonto.sprawdzKwote() << endl;
  cout << mojeKonto.wyplac(67) << " " << mojeKonto.sprawdzKwote() << endl;
  
  return 0;
}
