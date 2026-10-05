#include <iostream>
#include <algorithm>

using namespace std;

struct les{

	int beg;
	int end;
	
};

bool check(les a, les b);

bool compare(les a, les b){
	return a.end < b.end;
}

int main(){
	
	int n;
	les tab[100];
	
	cin >> n;
	
	if( n == 0 ){ cout << 0 << endl; return 0; }
	
	int a,b;

	for(int i = 0 ; i < n ; i++){
		
		cin >> a >> b;
		tab[i].beg = a; tab[i].end = b;
		
	}
	
	sort(tab,tab+n,compare);
	
	int current = 1;
	int tmp_indx = 0;
	
	for(int i = 0 ; i < (n-1) ; i++){
		if(check(tab[tmp_indx],tab[i+1])){
			tmp_indx = i+1; current++;
		}
		
	}
	
	cout << current << endl;
	
	return 0;
}

bool check(les a, les b){
		
	if(b.beg >= a.end){
		//cout << b.beg << " >= " << a.end << endl;
		return true;
	}
	//cout << b.beg << " < " << a.end << endl;
	return false;
}

// 100 200 
// 600 730
// 700 1000
// 730 1200

// 0 | 1 | 1
// 1 | 2 | 2
//

// 300 500
// 600 700
// 550 1200
// 700 1000
