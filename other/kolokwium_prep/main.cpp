
#include <iostream>
#include <string>
#include <fstream>
#include "ulamek.h"

int main(){

  std::ifstream liczby("liczby.txt");

  int n;

  ulamek test1(1,3);
  ulamek test2(1,3);

  test1 = test1 * test2;

  std::cout << "LOOK AT ME   " << test1 << std::endl;

  ulamek iloczyn(1,1);

  std::cout << test1[1] << std::endl;
  
  while(liczby >> n){

    for(int i = 0 ; i < n ; i++){
      std::string frac;
      liczby >> frac;

      char slash = frac.find('/');

      int a  = std::stoi(frac.substr(0, slash));
      int b = std::stoi(frac.substr(slash + 1));

      ulamek nowy(a,b);

      iloczyn = iloczyn * nowy;
      
      //std::cout << nowy << std::endl;
      
      //std::cout << a << " " << b << std::endl;
      
    }
    //std::cout << "NEW" << std::endl;
    std::cout << iloczyn << std::endl;
    iloczyn = ulamek(1,1);
  }

  ulamek t1(5,2);
  ulamek t2(3,2);

  //t1 > t2 -> true
  
  std::cout << (t1 < t2) << std::endl;
  std::cout << (t2 < t1) << std::endl;
  
  liczby.close();

  return 0;
}
