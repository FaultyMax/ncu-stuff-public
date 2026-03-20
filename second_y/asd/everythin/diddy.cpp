#include <iostream>
#include <algorithm>

#define inf 100000000

using namespace std;

void display(int k, int* arr){

	for(int i = 0 ; i < k+1 ; i++){
		if(arr[i] == inf){ cout << "inf" << " "; }
		else{ cout << arr[i] << " "; }
	}
	cout << endl;
}

int main(){
	
	int k, n;
	int nom[1000] = {0};
	
	cin >> k >> n;
	
	for(int i = 0 ;  i < n ; i++){
		
		cin >> nom[i];
		
	}
	
	sort(nom,nom+n,greater<int>());
	
	int* D = new int[k+1]; D[0] = 0;
	int* P = new int[k+1]; P[0] = 0;
	
	for(int i = 1 ; i < k+1 ; i++){
		D[i] = inf;
		P[i] = 0;
	}
	
	for(int i = 0 ; i < n ; i++){
		for(int j = nom[i]; j <= k ; j += nom[i]){
			if(D[j] > D[j-nom[i]]+1){
				P[j] = nom[i];
			}
			D[j] = min(D[j],D[j-nom[i]]+1);
			//cout << D[j] << " " << D[j-nom[i]]+1 << endl;
			//cout << nom[i] << " " << j << endl;
			//display(k,D);
			//display(k,P);
		}
	}
	
	if(D[k] == inf){ cout << "NIE" << endl; }
	else{ 
		cout << D[k] << endl;
	}

	int tmp = k;
	if(!(D[k] == inf)){
		string res;
		while(tmp != 0){
			int i = P[tmp];
			res = to_string(P[i]) + " " + res;
			tmp = tmp - P[i];
		}
		cout << res << endl;
	}
	
	delete[] D; delete[] P;
	
	return 0;
}

// 6		5
// 2		2 
// 2 5		2 4

// 19
// 4
// 9 6 5 1
