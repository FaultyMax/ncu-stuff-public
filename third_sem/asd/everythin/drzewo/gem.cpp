#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Struktura reprezentująca pojedynczą osobę (Węzeł drzewa)
struct Person {
    // Dane wymagane przez projekt [cite: 6]
    string name;
    string surname;
    string birthDate;

    // Wskaźniki budujące strukturę drzewa [cite: 6, 19]
    Person* parent;             // Wskaźnik na rodzica (ułatwia nawigację w górę)
    vector<Person*> children;   // Lista wskaźników na dzieci (drzewo n-arne)

    // Konstruktor dla wygody
    Person(string n, string s, string b, Person* p = nullptr) 
        : name(n), surname(s), birthDate(b), parent(p) {}
};

class FamilyTree {
private:
    Person* root; // Przodek (korzeń drzewa)

    // Metoda pomocnicza do szukania osoby (można tu użyć DFS/BFS )
    Person* findPerson(Person* current, const string& name, const string& surname) {
        if (!current) return nullptr;
        if (current->name == name && current->surname == surname) return current;

        for (Person* child : current->children) {
            Person* found = findPerson(child, name, surname);
            if (found) return found;
        }
        return nullptr;
    }

public:
    FamilyTree() : root(nullptr) {}

    // --- TWORZENIE DRZEWA (Dodawanie) [cite: 6] ---
    void setRoot(string name, string surname, string birthDate) {
        if (!root) {
            root = new Person(name, surname, birthDate);
        } else {
            cout << "Drzewo ma już korzeń!" << endl;
        }
    }

    void addChild(string pName, string pSurname, string cName, string cSurname, string cDate) {
        Person* parent = findPerson(root, pName, pSurname);
        if (parent) {
            // Tworzymy nowe dziecko i przypisujemy mu rodzica
            Person* newChild = new Person(cName, cSurname, cDate, parent);
            parent->children.push_back(newChild);
            cout << "Dodano: " << cName << " " << cSurname << endl;
        } else {
            cout << "Nie znaleziono rodzica!" << endl;
        }
    }

    // --- EDYCJA DANYCH [cite: 9] ---
    void editPerson(string oldName, string oldSurname, string newName, string newSurname, string newDate) {
        Person* target = findPerson(root, oldName, oldSurname);
        if (target) {
            target->name = newName;
            target->surname = newSurname;
            target->birthDate = newDate;
            cout << "Zaktualizowano dane." << endl;
        } else {
            cout << "Osoba nie istnieje." << endl;
        }
    }

    // --- USUWANIE (Z OGRANICZENIEM) [cite: 9, 10] ---
    void removePerson(string name, string surname) {
        if (!root) return;

        // Specjalny przypadek: usuwanie korzenia
        if (root->name == name && root->surname == surname) {
            if (root->children.empty()) {
                delete root;
                root = nullptr;
                cout << "Usunięto korzeń drzewa." << endl;
            } else {
                // Blokada usuwania, jeśli są potomkowie 
                cout << "Błąd: Nie można usunąć osoby posiadającej potomków!" << endl;
            }
            return;
        }

        Person* target = findPerson(root, name, surname);
        if (target) {
            // Sprawdzenie warunku z PDF: tylko osoby bez potomków (liście) 
            if (!target->children.empty()) {
                cout << "Błąd: Nie można usunąć osoby posiadającej potomków!" << endl;
                return;
            }

            // Usuwanie wskaźnika z listy dzieci rodzica
            Person* parent = target->parent;
            if (parent) {
                auto& siblings = parent->children;
                // Lambda do znalezienia i usunięcia wskaźnika z wektora
                siblings.erase(std::remove(siblings.begin(), siblings.end(), target), siblings.end());
            }
            
            delete target; // Zwolnienie pamięci 
            cout << "Usunięto osobę: " << name << " " << surname << endl;
        } else {
            cout << "Nie znaleziono osoby." << endl;
        }
    }
    
    // Prosta wizualizacja (rekurencyjna) [cite: 12]
    void printTree(Person* node, int level = 0) {
        if (!node) return;
        for (int i = 0; i < level; i++) cout << "  "; // Wcięcie zależne od poziomu
        cout << "- " << node->name << " " << node->surname << " (" << node->birthDate << ")" << endl;
        
        for (Person* child : node->children) {
            printTree(child, level + 1);
        }
    }
    
    Person* getRoot() { return root; }
};

int main() {
    FamilyTree tree;

    // 1. Tworzenie korzenia (np. Pradziadek)
    tree.setRoot("Jan", "Kowalski", "1950-01-01");

    // 2. Dodawanie dzieci [cite: 6]
    tree.addChild("Jan", "Kowalski", "Adam", "Kowalski", "1980-05-12");
    tree.addChild("Jan", "Kowalski", "Ewa", "Nowak", "1982-03-20");

    // 3. Dodawanie wnuka
    tree.addChild("Adam", "Kowalski", "Piotr", "Kowalski", "2005-07-07");

    cout << "\n--- Struktura Drzewa ---" << endl;
    tree.printTree(tree.getRoot());

    // 4. Próba niepoprawnego usunięcia (Adam ma syna Piotra) 
    cout << "\n--- Próba usunięcia Adama (ma dziecko) ---" << endl;
    tree.removePerson("Adam", "Kowalski");

    // 5. Poprawne usunięcie (Piotr jest liściem) 
    cout << "\n--- Próba usunięcia Piotra (jest liściem) ---" << endl;
    tree.removePerson("Piotr", "Kowalski");
    
    // Ponowne wyświetlenie
    cout << "\n--- Struktura po usunięciu ---" << endl;
    tree.printTree(tree.getRoot());

    return 0;
}