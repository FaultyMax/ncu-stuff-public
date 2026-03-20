
#include <iostream>
#include <string>
#include <vector>

#include "produkt.h"
#include "enum.h"

using namespace std;

struct Produkty{

	Produkt prod;
	int ilosc;

};

class koszyk{

public:

	vector<Produkty> zawartosc;

	koszyk() {}

	koszyk(vector<Produkty> p) : zawartosc(p) {};

	void dodaj(Produkt p, int ilosc){

		Produkty n;

		n.prod = p;
		n.ilosc = ilosc;

		for (int i = 0 ; i < zawartosc.size() ; i++){
			if(p.nazwa == zawartosc[i].prod.nazwa){
				cout << "ten produkt jest juz dodany" << endl;
			} else{
				zawartosc.push_back(n);
				cout << "dodano " << p.nazwa << endl;
				break;
			}
		}

		if(zawartosc.size() == 0){
			zawartosc.push_back(n);
			cout << "dodano " << p.nazwa << endl;
		}

	};

};

int main(){

	koszyk nowy;

	Produkt jablko("jablko",1.2,kat1,1000);
	Produkt jablko2("jablko",7.2,kat2,2000);
	Produkt inny("inne",13.2,kat3,2500);

	nowy.dodaj(jablko,12);
	nowy.dodaj(jablko2,6);
	nowy.dodaj(inny,2);

	return 0;
}