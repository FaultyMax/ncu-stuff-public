
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

enum WYBORY{

	WCZYTAJ = 1,
	ZAPISZ,
	WYSWIETL_PLIK,
	DODAJ,
	USUN,
	EDYTUJ,
	ANALIZUJ,
	WYSWIETL_DRZEWO,
	ZAKONCZ

};

struct Osoba{

	string imie;
	string nazwisko;
	string data_urodzenia;

	Osoba* rodzic;
	vector<Osoba*> dzieci;

	Osoba(string i, string n, string d, Osoba* r = nullptr) : imie(i), nazwisko(n), data_urodzenia(d), rodzic(r) {}

};

void display_menu(string fname);
Osoba* find_person(Osoba* node, string name, string surname);
vector<Osoba*> path_to_root(Osoba* p);

bool load_tree(Osoba*& root, string fname);
void delete_tree(Osoba* node);
void save_tree(Osoba* node, ofstream& savefile);

void print_tree(Osoba* node, int depth = 0);

int kinship(Osoba* p1, Osoba* p2);

int main(int argc, char** argv){

	string fname = "";

	bool active = true;
	int action;
	Osoba* root = nullptr;

	string name, surname, data, pname, psurname;

	while(active){

		display_menu(fname);
		cin >> action;

		switch(action){
		
		case WCZYTAJ : {
			cout << "Podaj nazwe pliku do wczytania: "; cin >> fname; 
			delete_tree(root);
			root = nullptr;
			bool loaded = load_tree(root, fname);
			if (!loaded) { fname = "";}
			break;
		}

		case ZAPISZ : {
			cout << "Podaj nazwe pliku do zapisu: "; cin >> fname;
			ofstream sfile(fname);
			if(sfile.is_open()){
				save_tree(root, sfile);
				sfile.close();
			}
			break;
		}

		case WYSWIETL_PLIK : {
			if(!fname.empty()){
				ifstream showfile(fname);
				if(showfile.is_open()){
					cout << endl << "--- ZAWARTOŚĆ PLIKU " << fname << " ---" << endl;
					cout << endl << showfile.rdbuf() << endl;
					showfile.close();
				} else {
					cout << "nie udało się otworzyć pliku." << endl;
				}
			}
			break;
		}

		case DODAJ : {
				
			if(!root){

				cout << "Tworze korzeń..." << endl;
				cout << "Podaj imię i nazwisko korzenia: ";
				cin >> name >> surname;
				cout << "Podaj datę urodzenia: "; cin >> data;

				root = new Osoba(name, surname, data);

			} else {

				cout << "Podaj imie i nazwisko rodzica: ";
				cin >> pname >> psurname;

				Osoba* parent = find_person(root, pname, psurname);
				if(parent){

					cout << "Podaj imie i nazwisko dziecka: ";
					cin >> name >> surname;
					cout << "Podaj datę urodzenia: "; cin >> data;
					parent->dzieci.push_back(new Osoba(name, surname, data, parent));

				} else {
					cout << "Nie znaleziono rodzica." << endl;
				}
			}

			break;
		}

		case USUN : {
			
			cout << "Podaj imię i nazwisko liścia: ";
			cin >> name >> surname;

			Osoba* person = find_person(root, name, surname);
			if (!person) { cout << "nie znaleziono!" << endl; break; }

			if (!person->dzieci.empty()){
				cout << "Osoba nie jest liściem ( ma potomków )" << endl;
				break;
			}

			if(person == root){
				delete root;
				root = nullptr;
			} else {
				Osoba* parent = person->rodzic;
				for(auto it = parent->dzieci.begin() ; it != parent->dzieci.end() ; it++){
					if(*it == person){
						parent->dzieci.erase(it);
						delete person;
						break;
					}
				}
			}
			cout << "Usunięcie powiodło się." << endl;
			break;
		}

		case EDYTUJ : {
			
			cout << "Podaj osobę (imie i nazwisko) do edycji: ";
			cin >> name >> surname;

			Osoba* person = find_person(root, name, surname);

			if (!person) { cout << "Nie znaleziono!" << endl; }
			else {
				cout << "Podaj nowe imię i nazwisko: ";
				cin >> name >> surname;
				cout << "Podaj nową datę urodzenia: "; cin >> data;
				person->imie = name;
				person->nazwisko = surname;
				person->data_urodzenia = data;
			}


			break;
		}

		case ANALIZUJ : {
			
			string n1, s1, n2, s2;
			cout << "Podaj pierwszą osobe: "; cin >> n1 >> s1;
			cout << "Podaj drugą osobe: "; cin >> n2 >> s2;

			Osoba* p1 = find_person(root, n1, s1);
			Osoba* p2 = find_person(root, n2, s2);

			if(p1 and p2){
				cout << "Stopien pokrewiensta: " << kinship(p1, p2) << endl;
			} else {
				cout << "Nie znaleziono takiej pary osób." << endl;
			}

			break;
		}

		case WYSWIETL_DRZEWO : {
			print_tree(root);
			break;
		}

		case ZAKONCZ :
			cout << "zakończono prace programu." << endl;
			delete_tree(root);
			active = false;
			break;
		default:
			cout << "wybierz poprawną opcje |1|2|3|4|5|6|7|8|9|" << endl;
		}
	}

	return 0;
}

// funkcje

void display_menu(string fname){

	cout << endl << "\t--- SYMULATOR DRZEWA GENEALOGICZNEGO ---" << endl << endl;
	if(!fname.empty()){ cout << "pracujemy na pliku: " << fname << endl; }
	else{ cout << "Brak otwartego pliku. Dane w pamięci." << endl; }
	cout << "1. wczytaj plik" << endl;
	cout << "2. zapisz plik" << endl;
	cout << "3. wyświetl zawartość pliku" << endl;
	cout << "4. dodaj do drzewa" << endl;
	cout << "5. usuń osobe" << endl;
	cout << "6. edytuj osobe" << endl;
	cout << "7. analizuj pokrewieństwo" << endl;
	cout << "8. wyświetl drzewo" << endl;
	cout << "9. zakończ program" << endl;
}

Osoba* find_person(Osoba* node, string name, string surname) {

	if(!node){ return nullptr; }

	if(node->imie == name and node->nazwisko == surname){ return node; }

	for(Osoba* child : node->dzieci){
		Osoba* found = find_person(child, name, surname);
		if (found) { return found; }
	}
	return nullptr;
}

vector<Osoba*> path_to_root(Osoba* p){
	vector<Osoba*> v;
	while(p){
		v.push_back(p);
		p = p->rodzic;
	}
	return v;
}

bool load_tree(Osoba*& root, string fname) {

	ifstream loadfile(fname);

	if(!loadfile.is_open()){
		cout << "Nie udało się otworzyć pliku." << endl;
		return false;
	}

	struct Temp { string i,n,d,pi,pn; };
	vector<Temp> ldata;

	while(!loadfile.eof()){

		Temp t;
		getline(loadfile, t.i, ';');
		getline(loadfile, t.n, ';');
		getline(loadfile, t.d, ';');
		getline(loadfile, t.pi, ';');
		getline(loadfile, t.pn);

		if (!t.i.empty()) { ldata.push_back(t); }
	}
	loadfile.close();

	for( auto& t : ldata ){
		if(t.pi == "ROOT"){
			root = new Osoba(t.i, t.n, t.d);
		}
	}

	for ( auto& t : ldata ){
		if(t.pi != "ROOT"){
			Osoba *p = find_person(root, t.pi, t.pn);
			if(p){
				p->dzieci.push_back(new Osoba(t.i, t.n, t.d, p));
			}
		}
	}

	return true;
}

void delete_tree(Osoba* node) {

	if (!node) { return; }
	for(Osoba* child : node->dzieci){
		delete_tree(child);
	}
	delete node;
}

void save_tree(Osoba* node, ofstream& savefile) {

	if (!node) { return; }
	if (node->rodzic){
		savefile << node->imie << ";" << node->nazwisko << ";" << node->data_urodzenia
		<< ";" << node->rodzic->imie << ";" << node->rodzic->nazwisko << "\n";
	} else {
		savefile << node->imie << ";" << node->nazwisko << ";" << node->data_urodzenia
		<< ";ROOT;ROOT\n";
	}

	for(Osoba* child : node->dzieci){
		save_tree(child,savefile);
	}
}

void print_tree(Osoba* node, int depth) {

    if (!node) { return; }
    
    for (int i = 0 ; i < depth ; i++) { cout << "  "; }
    cout << node->imie << " " << node->nazwisko << " (" << node->data_urodzenia << ")" << endl;
	for (Osoba* child : node->dzieci) { print_tree(child, depth+1); }
}


int kinship(Osoba* p1, Osoba* p2){
	auto path_1 = path_to_root(p1);
	auto path_2 = path_to_root(p2);
	for(int i = 0 ; i < path_1.size() ; i++){
		for(int j = 0 ; j < path_2.size() ; j++){
			if ( path_1[i] == path_2[j]){
				return i + j;
			}
		}
	}
	return -1;
}

