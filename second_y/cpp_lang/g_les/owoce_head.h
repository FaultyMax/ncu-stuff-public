
#include <string>

#ifndef OWOCE
#define OWOCE

  enum gatunek_jablka{

    nieznany_jab,
    antonowka,
    delikates

  };
  
  enum odmiana_truskawki{

    nieznany_trus,
    honeoye,
    clery,
    albion

  };

class owoc{

  public:
  
    std::string kolor;

    owoc();
    owoc(std::string kolor);
    
    void wypisz();
};

class jablko : public owoc{

  public:

    gatunek_jablka gatunek;

    jablko();
    jablko(std::string kolor);
    jablko(std::string kolor,gatunek_jablka gatunek);
    
    void wypisz();
  
};

class cytrus : public owoc{

  public:

    cytrus();
    cytrus(std::string kolor);
    
    void wypisz();

};

class pomarancz : public cytrus{

  public:

    double witamina_C;

    pomarancz();
    pomarancz(std::string kolor);
    pomarancz(std::string kolor, double witamina);
    
    void wypisz();

};

class limonka : public cytrus{

  public:

    std::string z_regionu;

    limonka();
    limonka(std::string kolor);
    limonka(std::string kolor,std::string region);
    
    void wypisz();

};

class truskawka : public owoc{

  public:

    odmiana_truskawki odmiana;

    truskawka();
    truskawka(std::string kolor);
    truskawka(std::string kolor, odmiana_truskawki odmiana);
    
    void wypisz();

};

#endif 
