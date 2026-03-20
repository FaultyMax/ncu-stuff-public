#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("liczby.txt"); // otwieramy plik

    if (!file.is_open()) {
        cerr << "Nie udalo sie otworzyc pliku!" << endl;
        return 1;
    }

    int n; // ile liczb w wierszu
    while (file >> n) { // czytamy pierwszą liczbę z wiersza
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int value;
            if (!(file >> value)) { // zabezpieczenie gdy plik jest krótszy niż n
                cerr << "Za malo liczb w wierszu!" << endl;
                return 1;
            }
            sum += value;
        }
        cout << "Suma wiersza: " << sum << endl;
    }

    file.close();
}
