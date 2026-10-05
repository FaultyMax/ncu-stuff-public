
#include <iostream>

using namespace std;

void merge(int tab[], int m_point, int l_point, int r_point);
void sort(int tab[], int l_point, int r_point);

int main(){
	
	int n;
	
	int tab[1000];
	
	cin >> n;
	
	for(int i = 0 ; i < n ; i++){ cin >> tab[i]; }
	
	sort(tab,0,n-1);
	
	for(int i = 0 ; i < n ; i++){
		
		if( i == n-1 ){ cout << tab[i]; }
		else{
			cout << tab[i] << ", ";
		}
	}
	
	return 0;

}

void sort(int tab[], int l_point, int r_point){
	
	if (l_point >= r_point) { return; } 
	
	int m_point = l_point + (r_point-l_point)/2;
	
	sort(tab,l_point,m_point);
	sort(tab,m_point+1,r_point);
	
	merge(tab, m_point, l_point, r_point);
	
	//cout << size << " " << l_point << " " << r_point << endl; 
	
}

void merge(int tab[], int m_point, int l_point, int r_point){
	
	int first = m_point-l_point+1;
	int second = r_point-m_point;
	
	int L[first], R[second];
	
	for(int i = 0 ; i < first; i++){ L[i] = tab[l_point+i];}
	for(int i = 0 ; i < second; i++){ R[i] = tab[m_point+1+i];}
	
	int i = 0, j = 0;
	int k = l_point;
	
	while(i < first and j < second){
		
		if(L[i] <= R[j]){
			tab[k] = L[i];
			i++;
		}
		else{
			tab[k] = R[j];
			j++;
		}
		k++;
	}
	
	while( i < first ){
		tab[k] = L[i];
		i++; k++;
	}
	
	while( j < second ){
		tab[k] = R[j];
		j++; k++;
	}
	
}
