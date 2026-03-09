
#include <iostream>
#include "zesp.h"

int main(){
	
	complex c(2,5);
	complex cp(7,2);
	complex c2;
	
	c = c + cp;

	c2 = c2 + 3.0; c2 = 1.0 + c2;
	
	std::cout << c << " " << c2 << std::endl;

	complex cpp;
	
	std::cout << (++cpp) << " " << (cpp++) << " " << cpp << std::endl;

	cpp = 1.0 - cpp;
	cpp = cpp - 1.0;

	complex mul(3,6);
	complex mul2(5,2);
	mul = mul * mul2;
	mul = 5 * mul;
	std::cout << mul << std::endl;

	
	
};

/*
Napisz klasę reprezentującą liczby zespolone, która:

ma posiadać przynajmniej dwa konstruktory (w tym jeden bezargumentowy)
ma mieć przeciążone operatory:
+, - (jedno i dwuargumentowy), *, /, <, <=, >, >=, ==, != (wybierz sposób ustalania porządku liczb zespolonych i opisz go w komentarzu do funkcji)
operatory +, -, * i / mają pozwalać na zapis
zespolona X zespolona
zespolona X float
float X zespolona
float ma być traktowany jak liczba zespolona, której część rzeczywista = float, a urojona = 0.
niech przeciąża jeszcze operator [], tak, że liczba[0] zwróci część rzeczywistą, a liczba[1] część urojoną. W przypadku innej - niepoprawnej wartości niech zwraca wartość 0.
ma pozwalać na obliczanie następujących funkcji:
sprzężenie liczby zespolonej, moduł, normalizacja (normalizacja zwraca liczbę zespoloną o module == 1) 
ma przeciążać operator << dla std::cout i drukować liczbę zespoloną w postaci "a + bi"
Wszystkie funkcje i operatory, których wynikiem jest nowa liczba zespolona mają NIE modyfikować oryginalnego obiektu, a zwracać nowy z poprawnymi wartościami.

W funkcji main przetestuj działanie operacji na liczbach zespolonych.
*/
