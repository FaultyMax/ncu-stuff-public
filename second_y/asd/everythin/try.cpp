#include <iostream>
#include <algorithm>

#define inf 100000000

using namespace std;

void display(int kwota, int* arr){

	for(int i = 0 ; i < kwota+1 ; i++){
		if(arr[i] == inf){ cout << "inf" << " "; }
		else{ cout << arr[i] << " "; }
	}
	cout << endl;
}

int main(){
	
	int kwota, n;
	int nominaly[1000] = {0};
	
	cin >> kwota >> n;
	
	for(int i = 0 ;  i < n ; i++){
		
		cin >> nominaly[i];
		
	}
	
	sort(nominaly,nominaly+n,greater<int>());
	
	int* D = new int[kwota+1]; D[0] = 0;
	int* P = new int[kwota+1]; P[0] = 0;
	
	for(int i = 1 ; i < kwota+1 ; i++){
		D[i] = inf;
		P[i] = 0;
	}
	
	for(int i = 0 ; i < n ; i++){
		for(int j = nominaly[i]; j <= kwota ; j += nominaly[i]){
			if(D[j] > D[j-nominaly[i]]+1){
				P[j] = nominaly[i];
			}
			D[j] = min(D[j],D[j-nominaly[i]]+1);
			//cout << D[j] << " " << D[j-nominaly[i]]+1 << endl;
			//cout << nominaly[i] << " " << j << endl;
			//display(kwota,D);
			//display(kwota,P);
		}
	}
	
	if(D[kwota] == inf){ cout << "NIE" << endl; }
	else{ 
		cout << D[kwota] << endl;
	}

	int tmp = kwota;
	if(!(D[kwota] == inf)){
		string monety_wynik;
		while(tmp != 0){
			int i = P[tmp];
			monety_wynik = to_string(P[i]) + " " + monety_wynik;
			tmp = tmp - P[i];
		}
		cout << monety_wynik << endl;
	}
	
	delete[] D; delete[] P;
	
	return 0;
}
