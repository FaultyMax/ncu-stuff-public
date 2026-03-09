#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
	
	string napis;
	
	ifstream plik("liczby.txt");
	
	int n;
	
	while(plik >> n)
    {
        
        float* wiersz = new float[n]; // a
        float min;
        
        for(int i = 0; i < n; i++){
			
			float value;
			plik >> value;
			
			if( i == 0 ) { min = value; } // b
			else{ if (min > value){ min = value; }}
			
			wiersz[i] = value;
			cout << i  << ": " << wiersz[i] << " ";
			
		}
        cout << endl << "Minimalna wartość: " << min << endl;
        
        delete[] wiersz;
    }
	
    plik.close();
	
}
