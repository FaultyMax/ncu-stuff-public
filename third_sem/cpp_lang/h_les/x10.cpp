#include <iostream>
#include <cmath>

class Obliczalny{

	public:

		virtual float potega() = 0;

		virtual float pierwiastek() = 0;

		virtual float bezwzgledna() = 0;

};

class Rzeczywista : public Obliczalny{

	public:

		int a;

		float potega() override{
			return a*a;
		}

		float pierwiastek() override{
			return sqrt(a);
		}

		float bezwzgledna() override{
			return abs(a);
		}

		Rzeczywista(){
			a = 3;
		}

		Rzeczywista(int a){
			this->a = a;
		}

};

int main(){

	Obliczalny* ptr;

	Rzeczywista liczba;
	Rzeczywista liczba2(5);

	ptr = &liczba;

	std::cout << ptr->potega() << std::endl;
	ptr = &liczba2;
	std::cout << ptr->potega() << std::endl;

	return 0;
}