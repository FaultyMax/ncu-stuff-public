#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

enum WYBORY {
    WCZYTAJ = 1,
    ZAPISZ,
    DODAJ,
    USUN,
    ANALIZUJ,
    WYSWIETL,
    ZAKONCZ,
    EDYTUJ
};

struct Osoba {

    string imie;
    string nazwisko;
    string data_urodzenia;

    Osoba* rodzic;
    vector<Osoba*> dzieci;

    Osoba(string i, string n, string d, Osoba* r = nullptr)
        : imie(i), nazwisko(n), data_urodzenia(d), rodzic(r) {}
};

/* --- deklaracje --- */
void display_menu();

Osoba* find_person(Osoba* node, string imie, string nazwisko);
void edit_person(Osoba* p);
void print_tree(Osoba* node, int depth = 0);
void delete_tree(Osoba* node);
void save_tree(Osoba* node, ofstream& f);
void load_tree(Osoba*& root, string fname);
vector<Osoba*> path_to_root(Osoba* p);
int kinship_degree(Osoba* a, Osoba* b);

/* --- main --- */
int main() {

    Osoba* root = nullptr;
    bool active = true;
    int action;

    while (active) {

        display_menu();
        cin >> action;

        switch (action) {

            case WCZYTAJ: {
                string fname;
                cout << "Podaj nazwe pliku: ";
                cin >> fname;
                delete_tree(root);
                root = nullptr;
                load_tree(root, fname);
                break;
            }

            case ZAPISZ: {
                string fname;
                cout << "Podaj nazwe pliku: ";
                cin >> fname;
                ofstream f(fname);
                if (f.is_open()) {
                    save_tree(root, f);
                    f.close();
                }
                break;
            }

            case DODAJ: {
                if (!root) {
                    string i, n, d;
                    cout << "Tworzenie korzenia\n";
                    cout << "Imie: "; cin >> i;
                    cout << "Nazwisko: "; cin >> n;
                    cout << "Data: "; cin >> d;
                    root = new Osoba(i, n, d);
                } else {
                    string pi, pn;
                    cout << "Podaj rodzica\n";
                    cout << "Imie: "; cin >> pi;
                    cout << "Nazwisko: "; cin >> pn;

                    Osoba* parent = find_person(root, pi, pn);
                    if (parent) {
                        string i, n, d;
                        cout << "Dane dziecka\n";
                        cout << "Imie: "; cin >> i;
                        cout << "Nazwisko: "; cin >> n;
                        cout << "Data: "; cin >> d;
                        parent->dzieci.push_back(new Osoba(i, n, d, parent));
                    } else {
                        cout << "Nie znaleziono rodzica\n";
                    }
                }
                break;
            }

            case USUN: {
                string i, n;
                cout << "Imie: "; cin >> i;
                cout << "Nazwisko: "; cin >> n;

                Osoba* p = find_person(root, i, n);
                if (!p) break;

                if (!p->dzieci.empty()) {
                    cout << "Nie mozna usunac osoby z potomkami\n";
                    break;
                }

                if (p == root) {
                    delete root;
                    root = nullptr;
                } else {
                    Osoba* r = p->rodzic;
                    for (auto it = r->dzieci.begin(); it != r->dzieci.end(); ++it) {
                        if (*it == p) {
                            r->dzieci.erase(it);
                            delete p;
                            break;
                        }
                    }
                }
                break;
            }

            case ANALIZUJ: {
                string i1, n1, i2, n2;
                cout << "Pierwsza osoba\n";
                cin >> i1 >> n1;
                cout << "Druga osoba\n";
                cin >> i2 >> n2;

                Osoba* a = find_person(root, i1, n1);
                Osoba* b = find_person(root, i2, n2);

                if (a && b) {
                    cout << "Stopien pokrewienstwa: "
                         << kinship_degree(a, b) << endl;
                }
                break;
            }

            case WYSWIETL:
                print_tree(root);
                break;

            case ZAKONCZ:
                delete_tree(root);
                active = false;
                break;
            case EDYTUJ: {

                string imie, nazwisko;
                cout << "Podaj osobe do edycji\n";
                cout << "Imie: "; cin >> imie;
                cout << "Nazwisko: "; cin >> nazwisko;

                Osoba* p = find_person(root, imie, nazwisko);

                if (!p) {
                    cout << "Nie znaleziono osoby.\n";
                } else {
                    edit_person(p);
                }
                break;
            }

        }
    }
    return 0;
}

/* --- funkcje --- */

void display_menu() {
    cout << "\n--- DRZEWO GENEALOGICZNE ---\n";
    cout << "1. wczytaj\n2. zapisz\n3. dodaj\n4. usun\n5. analizuj\n6. wyswietl\n7. zakoncz\n";
}

Osoba* find_person(Osoba* node, string imie, string nazwisko) {
    if (!node) return nullptr;
    if (node->imie == imie && node->nazwisko == nazwisko) return node;
    for (Osoba* d : node->dzieci) {
        Osoba* f = find_person(d, imie, nazwisko);
        if (f) return f;
    }
    return nullptr;
}

void print_tree(Osoba* node, int depth) {
    if (!node) return;
    for (int i = 0; i < depth; i++) cout << "  ";
    cout << node->imie << " " << node->nazwisko << " (" << node->data_urodzenia << ")\n";
    for (Osoba* d : node->dzieci)
        print_tree(d, depth + 1);
}

void delete_tree(Osoba* node) {
    if (!node) return;
    for (Osoba* d : node->dzieci)
        delete_tree(d);
    delete node;
}

void save_tree(Osoba* node, ofstream& f) {
    if (!node) return;
    if (node->rodzic)
        f << node->imie << ";" << node->nazwisko << ";" << node->data_urodzenia
          << ";" << node->rodzic->imie << ";" << node->rodzic->nazwisko << "\n";
    else
        f << node->imie << ";" << node->nazwisko << ";" << node->data_urodzenia
          << ";ROOT;ROOT\n";

    for (Osoba* d : node->dzieci)
        save_tree(d, f);
}

void load_tree(Osoba*& root, string fname) {
    ifstream f(fname);
    if (!f.is_open()) return;

    struct Temp { string i,n,d,pi,pn; };
    vector<Temp> data;

    while (!f.eof()) {
        Temp t;
        getline(f, t.i, ';');
        getline(f, t.n, ';');
        getline(f, t.d, ';');
        getline(f, t.pi, ';');
        getline(f, t.pn);
        if (!t.i.empty()) data.push_back(t);
    }
    f.close();

    for (auto& t : data)
        if (t.pi == "ROOT")
            root = new Osoba(t.i, t.n, t.d);

    for (auto& t : data)
        if (t.pi != "ROOT") {
            Osoba* p = find_person(root, t.pi, t.pn);
            if (p)
                p->dzieci.push_back(new Osoba(t.i, t.n, t.d, p));
        }
}

vector<Osoba*> path_to_root(Osoba* p) {
    vector<Osoba*> v;
    while (p) {
        v.push_back(p);
        p = p->rodzic;
    }
    return v;
}

int kinship_degree(Osoba* a, Osoba* b) {
    auto pa = path_to_root(a);
    auto pb = path_to_root(b);
    for (int i = 0; i < pa.size(); i++)
        for (int j = 0; j < pb.size(); j++)
            if (pa[i] == pb[j])
                return i + j;
    return -1;
}

void edit_person(Osoba* p) {

    if (!p) return;

    int choice;
    string input;

    cout << "\nEdytujesz: "
         << p->imie << " " << p->nazwisko
         << " (" << p->data_urodzenia << ")\n";

    cout << "1. zmien imie\n";
    cout << "2. zmien nazwisko\n";
    cout << "3. zmien date urodzenia\n";
    cout << "4. anuluj\n";

    cin >> choice;

    switch (choice) {

        case 1:
            cout << "Nowe imie: ";
            cin >> input;
            p->imie = input;
            break;

        case 2:
            cout << "Nowe nazwisko: ";
            cin >> input;
            p->nazwisko = input;
            break;

        case 3:
            cout << "Nowa data urodzenia: ";
            cin >> input;
            p->data_urodzenia = input;
            break;

        default:
            cout << "Anulowano edycje.\n";
            break;
    }
}
