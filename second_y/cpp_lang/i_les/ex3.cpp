#include <iostream>
#include <string>

// Klasa szablonowa z dwoma różnymi typami
template <typename T1, typename T2>
class Para {
public:
    T1 pierwszy;
    T2 drugi;

    // Konstruktor inicjalizujący oba elementy
    Para(T1 p, T2 d) : pierwszy(p), drugi(d) {}

    // Metoda do wyświetlania zawartości
    void wyswietl() const {
        std::cout << "Element 1: " << pierwszy << ", Element 2: " << drugi << std::endl;
    }
};

int main() {
    // Para przechowująca int oraz string
    Para<int, std::string> para1(1, "Programowanie");
    para1.wyswietl();

    // Para przechowująca double oraz char
    Para<double, char> para2(3.14, 'A');
    para2.wyswietl();

    return 0;
}

// not mine btw