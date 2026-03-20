#include <iostream>
#include <string>

#define inf 100000000

using namespace std;

string nawiasowanie(int** s, int i, int j);

int main(){

    int n; cin >> n;

    int* tab = new int[n+1];
    
    for(int i = 0 ; i < n+1 ; i++){
        cin >> tab[i];
    }

    int** m = new int*[n+1];
    int** s = new int*[n+1];

    for(int i = 0 ; i < n+1 ; i++){
        m[i] = new int[n+1];
        s[i] = new int[n+1];
    }

    // pseudo
    
    for (int i = 1 ; i <= n ; i++){ m[i][i] = 0; }

    for (int l = 2; l <= n; l++) {
        for (int i = 1 ; i <= (n-l+1) ; i++) { // begin 

            int j = i+l-1;
            m[i][j] = inf;
             
            for (int k = i ; k <= (j-1) ; k++) { // begin
                int q = m[i][k] + m[k+1][j] + tab[i-1] * tab[k] * tab[j];
                if (q < m[i][j]) {
                    //cout << m[i][j] << endl;
                    m[i][j] = q;
                    s[i][j] = k;
                    //cout << m[i][j] << endl;
                }
            }
        }
    }
    
    string out = nawiasowanie(s, 1, n);
    if(n == 1){ out = "A1"; }
    else{ out = out.substr(1,out.length()-2); }
    
    cout << m[1][n] << endl << out << endl;
    
    for(int i = 0 ; i < n+1 ; i++){ delete[] m[i]; delete[] s[i]; }
    delete[] m;
    delete[] s;
    delete[] tab;
    
    return 0;
}

string nawiasowanie(int** s, int i, int j) {
    if (i == j) {
        return "A" +to_string(i);
    }

    string left = nawiasowanie(s, i, s[i][j]);
    string right = nawiasowanie(s, s[i][j] + 1, j);

    return "(" + left + right + ")";
    
} 

// Ai = p[i-1] x p[i]
//
// A1A2 m[1][2]
// A1A2A3 m[1][3]
//
// 3
// 10
// 100
// 5
// 50

// 12 10 20 3 14 5 8 19 22 3 10 11 100 5
