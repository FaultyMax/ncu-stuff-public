#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

// --- 1. STRUKTURA DANYCH (bez metod) ---
// [cite: 6] Struktura reprezentująca osobę
struct Person {
    string name;
    string surname;
    string birthDate;

    Person* parent;             // Wskaźnik na rodzica
    vector<Person*> children;   // Lista wskaźników na dzieci
};

// --- 2. FUNKCJE POMOCNICZE (ALOKACJA) ---

// Funkcja tworząca nową osobę (alokacja pamięci)
Person* createPerson(string name, string surname, string birthDate) {
    Person* p = new Person;
    p->name = name;
    p->surname = surname;
    p->birthDate = birthDate;
    p->parent = nullptr;
    return p;
}

// --- 3. ALGORYTMY PRZESZUKIWANIA (DFS) ---
//  Implementacja DFS do znalezienia osoby w drzewie
Person* findPersonDFS(Person* current, string name, string surname) {
    if (current == nullptr) return nullptr;

    // Sprawdzenie czy to ta osoba
    if (current->name == name && current->surname == surname) {
        return current;
    }

    // Rekurencyjne przeszukiwanie dzieci
    for (Person* child : current->children) {
        Person* result = findPersonDFS(child, name, surname);
        if (result != nullptr) return result;
    }

    return nullptr;
}

// --- 4. EDYCJA I ZARZĄDZANIE DRZEWEM ---

// [cite: 6] Dodawanie osoby do drzewa
void addPerson(Person*& root, string pName, string pSurname, string name, string surname, string date) {
    if (root == nullptr) {
        // Jeśli drzewo jest puste, tworzymy korzeń (ignorujemy dane rodzica)
        root = createPerson(name, surname, date);
        cout << "Utworzono korzeń drzewa: " << name << " " << surname << endl;
        return;
    }

    // Szukamy rodzica
    Person* parent = findPersonDFS(root, pName, pSurname);
    if (parent != nullptr) {
        Person* child = createPerson(name, surname, date);
        child->parent = parent;
        parent->children.push_back(child);
        cout << "Dodano dziecko: " << name << " " << surname << endl;
    } else {
        cout << "Błąd: Nie znaleziono rodzica (" << pName << " " << pSurname << ")" << endl;
    }
}

// [cite: 9] Edycja danych osoby
void editPerson(Person* root, string oldName, string oldSurname) {
    Person* target = findPersonDFS(root, oldName, oldSurname);
    if (target != nullptr) {
        cout << "Podaj nowe imię: "; cin >> target->name;
        cout << "Podaj nowe nazwisko: "; cin >> target->surname;
        cout << "Podaj nową datę urodzenia: "; cin >> target->birthDate;
        cout << "Dane zaktualizowane." << endl;
    } else {
        cout << "Nie znaleziono osoby." << endl;
    }
}

// [cite: 10] Usuwanie osoby (tylko jeśli nie ma dzieci)
void removePerson(Person*& root, string name, string surname) {
    if (root == nullptr) return;

    // Przypadek specjalny: usuwanie korzenia
    if (root->name == name && root->surname == surname) {
        if (root->children.empty()) {
            delete root;
            root = nullptr;
            cout << "Usunięto korzeń. Drzewo jest puste." << endl;
        } else {
            cout << "Błąd: Nie można usunąć osoby posiadającej potomków!" << endl;
        }
        return;
    }

    Person* target = findPersonDFS(root, name, surname);
    if (target != nullptr) {
        // [cite: 10] Warunek liścia
        if (!target->children.empty()) {
            cout << "Błąd: Nie można usunąć osoby posiadającej potomków!" << endl;
            return;
        }

        // Usuwanie wskaźnika u rodzica
        Person* parent = target->parent;
        if (parent) {
            for (auto it = parent->children.begin(); it != parent->children.end(); ++it) {
                if (*it == target) {
                    parent->children.erase(it);
                    break;
                }
            }
        }
        delete target;
        cout << "Usunięto osobę." << endl;
    } else {
        cout << "Nie znaleziono osoby." << endl;
    }
}

// --- 5. ANALIZA POKREWIEŃSTWA ---

// Pomocnicza: Zwraca ścieżkę od węzła do korzenia
vector<Person*> getPathToRoot(Person* node) {
    vector<Person*> path;
    while (node != nullptr) {
        path.push_back(node);
        node = node->parent;
    }
    return path;
}

// [cite: 11] Obliczanie stopnia pokrewieństwa
void calculateKinship(Person* root, string name1, string surname1, string name2, string surname2) {
    Person* p1 = findPersonDFS(root, name1, surname1);
    Person* p2 = findPersonDFS(root, name2, surname2);

    if (!p1 || !p2) {
        cout << "Nie znaleziono jednej z osób." << endl;
        return;
    }

    if (p1 == p2) {
        cout << "To ta sama osoba!" << endl;
        return;
    }

    // Pobieramy ścieżki do korzenia
    vector<Person*> path1 = getPathToRoot(p1);
    vector<Person*> path2 = getPathToRoot(p2);

    // Szukamy najniższego wspólnego przodka (LCA)
    Person* lca = nullptr;
    int dist1 = 0, dist2 = 0;

    // Proste porównanie ścieżek
    bool found = false;
    for (int i = 0; i < path1.size(); i++) {
        for (int j = 0; j < path2.size(); j++) {
            if (path1[i] == path2[j]) {
                lca = path1[i];
                dist1 = i; // Odległość p1 do LCA
                dist2 = j; // Odległość p2 do LCA
                found = true;
                break;
            }
        }
        if (found) break;
    }

    if (lca) {
        cout << "Wspólny przodek: " << lca->name << " " << lca->surname << endl;
        cout << "Odległość w drzewie: " << (dist1 + dist2) << endl;
        if (dist1 == 0) cout << "Relacja: " << p1->name << " jest przodkiem " << p2->name << endl;
        else if (dist2 == 0) cout << "Relacja: " << p2->name << " jest przodkiem " << p1->name << endl;
        else cout << "Relacja: kuzynostwo lub rodzeństwo." << endl;
    } else {
        cout << "Brak wspólnego przodka (rozłączne drzewa?)" << endl;
    }
}

// --- 6. WIZUALIZACJA ---
// [cite: 12] Wyświetlanie tekstowe drzewa
void printTree(Person* node, int level = 0) {
    if (!node) return;
    for (int i = 0; i < level; i++) cout << "    "; // Wcięcie
    cout << "|-- " << node->name << " " << node->surname << " (" << node->birthDate << ")" << endl;

    for (Person* child : node->children) {
        printTree(child, level + 1);
    }
}

// --- 7. ZAPIS I ODCZYT ---

// Pomocnicza do zapisu (rekurencja preorder)
void saveToFileRec(Person* node, ofstream& file) {
    if (!node) return;
    
    string parentName = (node->parent) ? node->parent->name : "NONE";
    string parentSurname = (node->parent) ? node->parent->surname : "NONE";

    // Format: Imię Nazwisko Data ImięRodzica NazwiskoRodzica
    file << node->name << " " << node->surname << " " << node->birthDate << " " 
         << parentName << " " << parentSurname << endl;

    for (Person* child : node->children) {
        saveToFileRec(child, file);
    }
}

// [cite: 7] Zapis do pliku
void saveTree(Person* root, string filename) {
    ofstream file(filename);
    if (file.is_open()) {
        saveToFileRec(root, file);
        file.close();
        cout << "Zapisano do pliku " << filename << endl;
    } else {
        cout << "Błąd otwarcia pliku!" << endl;
    }
}

// Funkcja czyszcząca całą pamięć
void deleteTree(Person* node) {
    if (!node) return;
    for (Person* child : node->children) {
        deleteTree(child);
    }
    delete node;
}

// [cite: 7] Wczytywanie z pliku
void loadTree(Person*& root, string filename) {
    // Najpierw czyścimy obecne drzewo
    deleteTree(root);
    root = nullptr;

    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Błąd otwarcia pliku!" << endl;
        return;
    }

    string name, surname, date, pName, pSurname;
    while (file >> name >> surname >> date >> pName >> pSurname) {
        if (pName == "NONE") {
            addPerson(root, "", "", name, surname, date); // Tworzenie korzenia
        } else {
            addPerson(root, pName, pSurname, name, surname, date);
        }
    }
    file.close();
    cout << "Wczytano drzewo." << endl;
}

// --- 8. MENU GŁÓWNE ---
// [cite: 4, 18] Proste menu tekstowe
int main() {
    Person* root = nullptr;
    int choice;
    string n, s, d, pn, ps, n2, s2;
    string filename = "drzewo.txt";

    while (true) {
        cout << "\n=== SYMULATOR DRZEWA GENEALOGICZNEGO ===" << endl;
        cout << "1. Dodaj korzen (jesli puste) / Dodaj dziecko" << endl;
        cout << "2. Wyswietl drzewo" << endl;
        cout << "3. Usun osobe (tylko liscie)" << endl;
        cout << "4. Edytuj dane osoby" << endl;
        cout << "5. Analiza pokrewienstwa" << endl;
        cout << "6. Zapisz do pliku" << endl;
        cout << "7. Wczytaj z pliku" << endl;
        cout << "0. Wyjscie" << endl;
        cout << "Wybor: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (root == nullptr) {
                    cout << "Podaj imie korzenia: "; cin >> n;
                    cout << "Podaj nazwisko korzenia: "; cin >> s;
                    cout << "Podaj date ur.: "; cin >> d;
                    addPerson(root, "", "", n, s, d);
                } else {
                    cout << "Podaj imie RODZICA: "; cin >> pn;
                    cout << "Podaj nazwisko RODZICA: "; cin >> ps;
                    cout << "Podaj imie DZIECKA: "; cin >> n;
                    cout << "Podaj nazwisko DZIECKA: "; cin >> s;
                    cout << "Podaj date ur. DZIECKA: "; cin >> d;
                    addPerson(root, pn, ps, n, s, d);
                }
                break;
            case 2:
                printTree(root);
                break;
            case 3:
                cout << "Podaj imie do usuniecia: "; cin >> n;
                cout << "Podaj nazwisko do usuniecia: "; cin >> s;
                removePerson(root, n, s);
                break;
            case 4:
                cout << "Podaj imie osoby do edycji: "; cin >> n;
                cout << "Podaj nazwisko osoby do edycji: "; cin >> s;
                editPerson(root, n, s);
                break;
            case 5:
                cout << "Osoba 1 Imie: "; cin >> n;
                cout << "Osoba 1 Nazwisko: "; cin >> s;
                cout << "Osoba 2 Imie: "; cin >> n2;
                cout << "Osoba 2 Nazwisko: "; cin >> s2;
                calculateKinship(root, n, s, n2, s2);
                break;
            case 6:
                saveTree(root, filename);
                break;
            case 7:
                loadTree(root, filename);
                break;
            case 0:
                deleteTree(root);
                return 0;
            default:
                cout << "Nieprawidlowa opcja." << endl;
        }
    }
}