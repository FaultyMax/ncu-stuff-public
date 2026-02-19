#ifndef _PRODUKT_
#define _PRODUKT_

#include <string>
#include "enum.h"

class Produkt{

public:

	std::string nazwa;
	double cena;
	KATEGORIA kategoria;
	int id;

	Produkt();
	Produkt(std::string n, double c, KATEGORIA k, int i);

};

#endif