
#include <iostream>
#include <algorithm>
#include <vector>

class Butelka{

public:

	float pojemnosc;
	float p_zapelnienia;

	Butelka(float p, float pr) : pojemnosc(p), p_zapelnienia(pr) {} 

};

bool porownajObjetosc(const Butelka& a, const Butelka& b) {
    return a.p_zapelnienia > b.p_zapelnienia;
}

int main(){

	std::vector<Butelka> Butelki;

	Butelki.push_back(Butelka(15,50));
	Butelki.push_back(Butelka(6.5,20));
	Butelki.push_back(Butelka(3,70));
	Butelki.push_back(Butelka(12,23.64));

	for(const auto& b : Butelki){
		std::cout << b.pojemnosc << " " << b.p_zapelnienia << std::endl;
	}

	std::sort(Butelki.begin(), Butelki.end(), porownajObjetosc);

	for(const auto& b : Butelki){
		std::cout << b.pojemnosc << " " << b.p_zapelnienia << std::endl;
	}

	return 0;
}

