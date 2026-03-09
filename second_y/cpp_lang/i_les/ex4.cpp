#include <iostream>
#include <vector>
#include <algorithm> // Dla std::sort
#include <random>    // Dla lepszego generowania liczb losowych

int main() {
    // 1. Inicjalizacja generatora liczb losowych
    std::random_device rd;  
    std::mt19937 gen(rd()); // Silnik Mersenne Twister
    std::uniform_int_distribution<> dist(1, 100); // Zakres od 1 do 100

    // 2. Tworzenie wektora i wypełnianie go losowymi liczbami
    std::vector<int> liczby;
    for (int i = 0; i < 10; ++i) {
        liczby.push_back(dist(gen));
    }

    // Wyświetlenie przed sortowaniem
    std::cout << "Przed sortowaniem: ";
    for (int n : liczby) std::cout << n << " ";
    std::cout << std::endl;

    // 3. Sortowanie wektora
    // std::sort standardowo sortuje rosnąco
    std::sort(liczby.begin(), liczby.end(), std::greater<int>());

    // Wyświetlenie po sortowaniu
    std::cout << "Po sortowaniu:    ";
    for (int n : liczby) std::cout << n << " ";
    std::cout << std::endl;

    return 0;
}