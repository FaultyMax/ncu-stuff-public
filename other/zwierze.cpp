#include <iostream>

using namespace std;

class Zwierze{
private:
    int waga;
public:
    enum gatunek{
        nieznany,
        zwykly,
        niezwykly,
        wiejski,
        miejski,
        dubajski,
        twojegostarego
    };
    string imie;
    gatunek gtnk;
    int wiek;
    Zwierze *rodzic=nullptr;

    Zwierze(){
        imie="Bez Nazwy";
        gtnk=nieznany;
        wiek=0;
        waga=0;
        rodzic=nullptr;
    }

    Zwierze(string imie, gatunek gtnk, int wiek, int waga, Zwierze *rodzic){
        this->imie=imie;
        this->gtnk=gtnk;
        this->wiek=wiek;
        this->waga=waga;
        this->rodzic=rodzic;
    }

    void ustawieniewagi(int nowaWaga){
        waga = nowaWaga;
    }

    int zwracaniewagi(){
        return waga;
    }

    ~Zwierze() {
        cout << "DESTRUKCJA KNURA!!!\n\n";
        cout << "Imie knura: " << imie << endl << "Wiek knura: " << wiek << endl;
    }

    void wypiszDane() {
        cout << "Imie: " << imie << endl;
        cout << "Wiek: " << wiek << endl;
        cout << "Waga: " << waga << "kg" << endl;
        cout << "Gatunek: " << gtnk << endl;
        if(rodzic != nullptr) {
            cout << "Rodzic: " << rodzic->imie << endl;
        }
    }
};

class Zoo{
private:
    Zwierze *tab;
    int maks;

public:
    Zoo(int maks){
        this->maks=maks;
        tab=new Zwierze[maks];
        if(tab==nullptr){
            cerr << "B³¹d alokacji tablicy";
            this->maks=0;
        }
    }

    void dodanie1(string nazwa, int wiek, int waga, Zwierze::gatunek gtnk, Zwierze *rodzic){
        int i = znajdzWolneMiejsce();
        if (i == -1) {
            cout << "Brak miejsca w zoo!" << endl;
            return;
        }
        tab[i].imie = nazwa;
        tab[i].wiek = wiek;
        tab[i].ustawieniewagi(waga);
        tab[i].gtnk = gtnk;
        tab[i].rodzic = rodzic;
    }

    void dodanie2(string nazwa, int wiek, int waga, Zwierze::gatunek gtnk, int indeks){
        int i = znajdzWolneMiejsce();
        if (i == -1) {
            cout << "Brak miejsca w zoo!" << endl;
            return;
        }

        tab[i].imie = nazwa;
        tab[i].wiek = wiek;
        tab[i].ustawieniewagi(waga);
        tab[i].gtnk = gtnk;
        if (indeks >= 0 && indeks < maks) {
            tab[i].rodzic = &tab[indeks];
        } else {
            tab[i].rodzic = nullptr;
        }
    }

    int znajdzWolneMiejsce() {
        for (int j = 0; j < maks; j++) {
            if (tab[j].imie == "Bez Nazwy") {
                return j;
            }
        }
        return -1;
    }

    void wypiszNazwyIWiek() {
    cout << "=== Zwierzêta w Zoo (nazwa i wiek) ===" << endl;
    for (int i = 0; i < maks; i++) {
        if (tab[i].imie != "Bez Nazwy") {
            cout << "Zwierze " << i+1 << ": " << tab[i].imie << " (" << tab[i].wiek << " lat)" << endl;
        }
    }
}

    ~Zoo(){
        cout << "Destrukcja ZOO!";
        if(tab){
            delete[] tab;
        }
    }
};

int main(){
    Zoo *tab = new Zoo(5);

    tab->dodanie1("Sama", 21, 2137, Zwierze::wiejski, nullptr);

    for (int i=0; i<5; i++){
        tab->dodanie1("Zwierze_"+to_string(i), rand()%15, rand()%100+10, Zwierze::zwykly, NULL);
    }

    tab->wypiszNazwyIWiek();

    delete tab;

    return 0;
}
