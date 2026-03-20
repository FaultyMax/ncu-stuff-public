#include <iostream>
#include <string>
#include "produkt.h"

Produkt::Produkt() : nazwa(""), cena(0.0), kategoria(kat1), id(0) {};

Produkt::Produkt(std::string n, double c, KATEGORIA k, int i) : nazwa(n), cena(c), kategoria(k), id(i) {}; 