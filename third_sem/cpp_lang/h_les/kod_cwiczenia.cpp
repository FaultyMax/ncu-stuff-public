#include <iostream>
#include <string>


class Zwierze{
public:
    std::string imie;
    virtual std::string dajGlos()=0;

    virtual void spij(short int x){
        std::cout << "Zwierze spi " << x << " sekund" << std::endl;
    }

    Zwierze(){
        imie = "jakies zwierze";
    }
    Zwierze(std::string imie) {
        this->imie = imie;
    }

    virtual ~Zwierze() {
        std::cout << "Destruktor zwierze" << std::endl;
    }
};

class Kot : public Zwierze{
public:
    std::string dajGlos(){
        return std::string("Miau");
    }

    void spij(short int x) override{
        std::cout << "Kot spi " << x << " sekund" << std::endl;
    }

    Kot() : Zwierze("jakis kot"){ }
    Kot(std::string imie) : Zwierze(imie){ }

    ~Kot() {
        std::cout << "Destruktor kot" << std::endl;
    }
};

class KotBrytyjski : public Kot{
public:
    std::string dajGlos(){
        return std::string("Brytyjskie miau");
    }

    void spij(short int x) override{
        std::cout << "Kot brytyjski spi " << x << " sekund" << std::endl;
    }

    KotBrytyjski() : Kot("jakis kot brytyjski"){ }
    KotBrytyjski(std::string imie) : Kot(imie){ }

    ~KotBrytyjski() {
        std::cout << "Destruktor kot brytyjski" << std::endl;
    }
};

class Pies : public Zwierze{
public:
    std::string dajGlos(){
        return std::string("Hau");
    }

    Pies() : Zwierze("jakis pies"){ }
    Pies(std::string imie) : Zwierze(imie){ }
};

using namespace std;

int main()
{
//    Kot kot("Filemon");
//    Kot* kptr = &kot;
//    Zwierze* zptr = &kot;
//    Zwierze& zref = kot;

    //Zwierze z;

    Zwierze* arr[6];
    for(int i = 0; i < 6; i++){
        if(i < 3)
            arr[i] = new Kot("Kot " + std::to_string(i+1));
        else
            arr[i] = new Pies("Pies " + std::to_string(i+1));
    }

    for(int i = 0; i < 6; i++){
        std::cout << arr[i]->imie << ": " << arr[i]->dajGlos() << std::endl;
        arr[i]->spij(10);
    }

//    std::cout << kptr->imie << ": " << kptr->dajGlos() << std::endl;
//    std::cout << zptr->imie << ": " << zptr->dajGlos() << std::endl;
//    std::cout << zref.imie << ": " << zref.dajGlos() << std::endl;

    for(int i = 0; i < 6; i++){
        delete arr[i];
    }

    Kot k = KotBrytyjski();
    std::cout << k.imie << ": " << k.dajGlos() << std::endl;
    return 0;
}
