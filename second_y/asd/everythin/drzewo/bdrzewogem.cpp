#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

// --- STRUKTURA DANYCH ---
struct Osoba {
    string imie;
    string nazwisko;
    string data_urodzenia;

    Osoba* rodzic = nullptr;
    Osoba* wspolmalzonek = nullptr;
    vector<Osoba*> dzieci;

    Osoba(string i, string n, string d) : imie(i), nazwisko(n), data_urodzenia(d) {}
};

// --- DEKLARACJE FUNKCJI ---
void display_menu(string fname);
Osoba* findPerson(Osoba* root, string imie, string nazwisko);
void displayTree(Osoba* node, int level = 0);
void deleteTree(Osoba* node);
void saveTree(Osoba* root, string filename);
void loadTree(Osoba*& root, string filename);
void analyzeKinship(Osoba* root);

// --- FUNKCJE POMOCNICZE ---

// Rekurencyjne szukanie osoby w drzewie
Osoba* findPerson(Osoba* current, string imie, string nazwisko) {
    if (!current) return nullptr;
    if (current->imie == imie && current->nazwisko == nazwisko) return current;

    // Szukamy w dzieciach
    for (Osoba* dziecko : current->dzieci) {
        Osoba* found = findPerson(dziecko, imie, nazwisko);
        if (found) return found;
    }
    return nullptr;
}

// Funkcja pomocnicza do pobierania wszystkich węzłów (do zapisu/czyszczenia)
void getAllNodes(Osoba* node, vector<Osoba*>& nodes) {
    if (!node) return;
    nodes.push_back(node);
    for (Osoba* child : node->dzieci) {
        getAllNodes(child, nodes);
    }
}

// --- LOGIKA GŁÓWNA ---

int main(int argc, char** argv) {
    Osoba* root = nullptr; // Korzeń drzewa
    string file_name = "";

    // Obsługa argumentów startowych
    if (argc == 2) {
        file_name = argv[1];
        loadTree(root, file_name);
    }

    bool active = true;
    int action;
    string i, n, d, pi, pn; // zmienne pomocnicze do wczytywania danych

    while (active) {
        display_menu(file_name);
        cout << "Wybor: ";
        if (!(cin >> action)) { // Zabezpieczenie przed błędnym wejściem
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (action) {
        case 1: // Wczytaj plik
            cout << "Podaj nazwe pliku do wczytania: "; cin >> file_name;
            loadTree(root, file_name);
            break;

        case 2: // Zapisz plik
            if (file_name.empty()) {
                cout << "Podaj nazwe pliku do zapisu: "; cin >> file_name;
            }
            saveTree(root, file_name);
            break;

        case 3: // Wyświetl zawartość pliku (RAW)
            if (!file_name.empty()) {
                ifstream f(file_name);
                if (f.is_open()) {
                    cout << "\n--- ZAWARTOSC PLIKU " << file_name << " ---\n";
                    cout << f.rdbuf() << endl;
                    f.close();
                } else {
                    cout << "Blad otwarcia pliku." << endl;
                }
            } else {
                cout << "Nie wybrano pliku." << endl;
            }
            break;

        case 4: // Dodaj do drzewa
            cout << "\n--- DODAWANIE OSOBY ---\n";
            cout << "1. Dodaj dziecko / Korzen\n";
            cout << "2. Dodaj malzonka\nWybor: ";
            int subChoice; cin >> subChoice;

            if (subChoice == 1) {
                if (root == nullptr) {
                    cout << "Drzewo puste. Tworze korzen.\n";
                    cout << "Imie: "; cin >> i;
                    cout << "Nazwisko: "; cin >> n;
                    cout << "Data ur.: "; cin >> d;
                    root = new Osoba(i, n, d);
                } else {
                    cout << "Podaj imie RODZICA: "; cin >> pi;
                    cout << "Podaj nazwisko RODZICA: "; cin >> pn;
                    Osoba* rodzic = findPerson(root, pi, pn);
                    if (rodzic) {
                        cout << "Podaj imie DZIECKA: "; cin >> i;
                        cout << "Podaj nazwisko DZIECKA: "; cin >> n;
                        cout << "Data ur.: "; cin >> d;
                        Osoba* dziecko = new Osoba(i, n, d);
                        dziecko->rodzic = rodzic;
                        rodzic->dzieci.push_back(dziecko);
                        cout << "Dodano dziecko.\n";
                    } else {
                        cout << "Nie znaleziono rodzica.\n";
                    }
                }
            } else if (subChoice == 2) {
                if (!root) { cout << "Najpierw stworz korzen drzewa.\n"; break; }
                cout << "Podaj imie osoby, ktora bierze slub: "; cin >> pi;
                cout << "Podaj nazwisko osoby, ktora bierze slub: "; cin >> pn;
                Osoba* p1 = findPerson(root, pi, pn);
                if (p1) {
                    if (p1->wspolmalzonek != nullptr) {
                        cout << "Ta osoba ma juz malzonka!\n";
                    } else {
                        cout << "Podaj imie malzonka: "; cin >> i;
                        cout << "Podaj nazwisko malzonka: "; cin >> n;
                        cout << "Data ur.: "; cin >> d;
                        
                        // Sprawdzamy czy malzonek juz istnieje w drzewie (np. kuzyn)
                        // W prostym symulatorze zakładamy, że małżonek to nowa osoba "spoza" drzewa lub liść
                        Osoba* p2 = findPerson(root, i, n);
                        if (!p2) {
                            p2 = new Osoba(i, n, d); // Tworzymy nową osobę
                            // Uwaga: Nowy małżonek nie jest "dzieckiem" nikogo w tym drzewie (chyba że dodamy taką logikę)
                            // Aby nie "wisiał" w powietrzu przy usuwaniu pamięci, 
                            // w tym prostym modelu małżonek jest dostępny przez wskaźnik p1->wspolmalzonek
                        }
                        
                        p1->wspolmalzonek = p2;
                        p2->wspolmalzonek = p1;
                        cout << "Dodano malzonka.\n";
                    }
                } else {
                    cout << "Nie znaleziono osoby.\n";
                }
            }
            break;

        case 5: // Edytuj osobe
            cout << "Podaj imie osoby do edycji: "; cin >> i;
            cout << "Podaj nazwisko osoby do edycji: "; cin >> n;
            {
                Osoba* p = findPerson(root, i, n);
                // Musimy sprawdzić też czy to nie jest małżonek "doczepiony" (nie będący w strukturze dzieci)
                // W tym prostym modelu findPersonDFS szuka tylko po dzieciach.
                // Jeśli małżonek nie jest dzieckiem nikogo z drzewa, findPerson go nie znajdzie.
                // Rozwiązanie: findPerson powinien być bardziej zaawansowany lub upraszczamy model.
                // Uproszczenie: Edycja działa dla osób w głównej linii.
                if (p) {
                    cout << "Nowe imie: "; cin >> p->imie;
                    cout << "Nowe nazwisko: "; cin >> p->nazwisko;
                    cout << "Nowa data: "; cin >> p->data_urodzenia;
                    cout << "Zaktualizowano.\n";
                } else {
                    cout << "Nie znaleziono osoby (lub jest to malzonek spoza glownego drzewa).\n";
                }
            }
            break;

        case 6: // Usuń osobe
            cout << "Podaj imie do usuniecia: "; cin >> i;
            cout << "Podaj nazwisko do usuniecia: "; cin >> n;
            if (root && root->imie == i && root->nazwisko == n) {
                if (root->dzieci.empty()) {
                    delete root; root = nullptr; cout << "Usunieto korzen.\n";
                } else cout << "Nie mozna usunac osoby z potomstwem!\n";
            } else {
                Osoba* p = findPerson(root, i, n);
                if (p) {
                    if (!p->dzieci.empty()) {
                        cout << "Nie mozna usunac osoby z potomstwem!\n";
                    } else {
                        // Usuwanie
                        // 1. Odczep od rodzica
                        if (p->rodzic) {
                            auto& rodzenstwo = p->rodzic->dzieci;
                            rodzenstwo.erase(remove(rodzenstwo.begin(), rodzenstwo.end(), p), rodzenstwo.end());
                        }
                        // 2. Odczep od malzonka
                        if (p->wspolmalzonek) {
                            p->wspolmalzonek->wspolmalzonek = nullptr;
                        }
                        delete p;
                        cout << "Usunieto osobe.\n";
                    }
                } else {
                    cout << "Nie znaleziono.\n";
                }
            }
            break;

        case 7: // Analizuj pokrewieństwo
            analyzeKinship(root);
            break;

        case 8: // Wyświetl drzewo
            if (root) {
                cout << "\n--- STRUKTURA RODZINY ---\n";
                displayTree(root);
            } else {
                cout << "Drzewo jest puste.\n";
            }
            break;

        case 9:
            cout << "Konczenie pracy..." << endl;
            deleteTree(root); // Sprzątanie pamięci
            active = false;
            break;

        default:
            cout << "Wybierz poprawna opcje.\n";
        }
    }

    return 0;
}

void display_menu(string fname) {
    cout << "\n\t--- SYMULATOR DRZEWA GENEALOGICZNEGO ---" << endl;
    if (!fname.empty()) { cout << "Pracujemy na pliku: " << fname << endl; }
    else { cout << "Brak otwartego pliku (dane tylko w pamieci)." << endl; }
    cout << "1. Wczytaj plik (nadpisuje obecne drzewo)" << endl;
    cout << "2. Zapisz plik" << endl;
    cout << "3. Wyswietl zawartosc pliku (tekst)" << endl;
    cout << "4. Dodaj do drzewa (Osobe lub Malzonka)" << endl;
    cout << "5. Edytuj osobe" << endl;
    cout << "6. Usun osobe (tylko liscie)" << endl;
    cout << "7. Analizuj pokrewienstwo" << endl;
    cout << "8. Wyswietl drzewo (graficznie)" << endl;
    cout << "9. Zakoncz program" << endl;
}

// Wizualizacja drzewa
void displayTree(Osoba* node, int level) {
    if (!node) return;
    for (int i = 0; i < level; i++) cout << "    ";
    
    cout << node->imie << " " << node->nazwisko << " (" << node->data_urodzenia << ")";
    if (node->wspolmalzonek) {
        cout << " <==> Malzonek: " << node->wspolmalzonek->imie << " " << node->wspolmalzonek->nazwisko;
    }
    cout << endl;

    for (Osoba* child : node->dzieci) {
        displayTree(child, level + 1);
    }
}

// Sprzątanie pamięci
void deleteTree(Osoba* node) {
    if (!node) return;
    // Uwaga: rekurencyjne usuwanie jest trudne przy grafie z cyklami (małżeństwa).
    // W tej prostej implementacji usuwamy dzieci.
    // Małżonków "bocznych" (jeśli nie są w strukturze dzieci) trzeba by usuwać osobno,
    // albo zbierać wszystkie wskaźniki do vectora i usuwać liniowo.
    
    // Uproszczone czyszczenie (dla struktury drzewiastej)
    for (Osoba* child : node->dzieci) {
        deleteTree(child);
    }
    delete node;
}

// --- ZAPIS I ODCZYT ---

// Struktura pomocnicza do zapisu płaskiego
struct FileRecord {
    string i, n, d, pi, pn, mi, mn;
};

void saveTreeRecursive(Osoba* node, ofstream& file, vector<Osoba*>& visited) {
    if (!node) return;
    
    // Sprawdź czy już zapisaliśmy tę osobę (ważne przy grafach)
    for(auto v : visited) if(v == node) return;
    visited.push_back(node);

    string pi = "NONE", pn = "NONE";
    string mi = "NONE", mn = "NONE";

    if (node->rodzic) {
        pi = node->rodzic->imie;
        pn = node->rodzic->nazwisko;
    }
    if (node->wspolmalzonek) {
        mi = node->wspolmalzonek->imie;
        mn = node->wspolmalzonek->nazwisko;
    }

    file << node->imie << " " << node->nazwisko << " " << node->data_urodzenia << " "
         << pi << " " << pn << " " << mi << " " << mn << endl;

    // Zapisujemy małżonka, jeśli jeszcze nie był zapisany (i nie jest w drzewie jako dziecko)
    if (node->wspolmalzonek) {
        saveTreeRecursive(node->wspolmalzonek, file, visited);
    }

    for (Osoba* child : node->dzieci) {
        saveTreeRecursive(child, file, visited);
    }
}

void saveTree(Osoba* root, string filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Nie udalo sie otworzyc pliku do zapisu.\n";
        return;
    }
    vector<Osoba*> visited;
    saveTreeRecursive(root, file, visited);
    file.close();
    cout << "Zapisano drzewo do " << filename << endl;
}

void loadTree(Osoba*& root, string filename) {
    // 1. Wyczyść stare drzewo
    // (W uproszczeniu pomijamy pełne deleteTree żeby nie komplikować kodu, w prod. należy zwolnić pamięć)
    root = nullptr; 

    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Nie udalo sie otworzyc pliku lub plik nie istnieje.\n";
        return;
    }

    // 2. Wczytaj wszystkie rekordy do pamięci tymczasowej
    vector<FileRecord> records;
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        FileRecord r;
        ss >> r.i >> r.n >> r.d >> r.pi >> r.pn >> r.mi >> r.mn;
        records.push_back(r);
    }
    file.close();

    // 3. Utwórz wszystkie obiekty (bez powiązań)
    vector<Osoba*> allPeople;
    for (const auto& r : records) {
        allPeople.push_back(new Osoba(r.i, r.n, r.d));
    }

    if (allPeople.empty()) return;

    // 4. Połącz obiekty (Rodzice i Małżonkowie)
    // Musimy znaleźć odpowiednie wskaźniki w wektorze allPeople
    for (size_t k = 0; k < records.size(); k++) {
        Osoba* current = allPeople[k];
        FileRecord r = records[k];

        // Ustawianie rodzica
        if (r.pi != "NONE") {
            for (Osoba* kandydat : allPeople) {
                if (kandydat->imie == r.pi && kandydat->nazwisko == r.pn) {
                    current->rodzic = kandydat;
                    kandydat->dzieci.push_back(current);
                    break;
                }
            }
        } else {
            // Jeśli nie ma rodzica i nie jest małżonkiem kogoś kto ma rodzica... to może być korzeń
            // (W uproszczeniu: pierwsza osoba bez rodzica to korzeń)
            if (root == nullptr) root = current;
        }

        // Ustawianie małżonka
        if (r.mi != "NONE" && current->wspolmalzonek == nullptr) {
            for (Osoba* kandydat : allPeople) {
                if (kandydat->imie == r.mi && kandydat->nazwisko == r.mn) {
                    current->wspolmalzonek = kandydat;
                    kandydat->wspolmalzonek = current;
                    break;
                }
            }
        }
    }
    
    // Jeśli root nadal null (np. same pary małżeńskie bez dzieci), weź pierwszego z brzegu
    if (root == nullptr && !allPeople.empty()) root = allPeople[0];

    cout << "Wczytano drzewo z pliku.\n";
}

// --- ANALIZA ---
void analyzeKinship(Osoba* root) {
    string i1, n1, i2, n2;
    cout << "Osoba 1 (Imie Nazwisko): "; cin >> i1 >> n1;
    cout << "Osoba 2 (Imie Nazwisko): "; cin >> i2 >> n2;

    Osoba* p1 = findPerson(root, i1, n1);
    // Jeśli nie znaleziono w głównej linii, spróbuj znaleźć jako małżonka
    if(!p1 && root) {
         // Tutaj należałoby przeszukać wszystkich małżonków, w uproszczeniu:
         // findPerson szuka tylko po dzieciach.
         // Zakładamy, że user pyta o osoby w drzewie.
    }
    Osoba* p2 = findPerson(root, i2, n2);

    if (!p1 || !p2) {
        cout << "Nie znaleziono jednej z osob.\n";
        return;
    }

    if (p1 == p2) { cout << "To ta sama osoba.\n"; return; }
    
    if (p1->wspolmalzonek == p2) { cout << "RELACJA: Malzenstwo.\n"; return; }
    
    if (p1->rodzic == p2) { cout << "RELACJA: " << p2->imie << " jest rodzicem " << p1->imie << endl; return; }
    if (p2->rodzic == p1) { cout << "RELACJA: " << p1->imie << " jest rodzicem " << p2->imie << endl; return; }

    if (p1->rodzic && p1->rodzic == p2->rodzic) { cout << "RELACJA: Rodzenstwo.\n"; return; }

    cout << "Inna relacja (dalsza rodzina lub brak bezposredniej relacji w prostym algorytmie).\n";
}