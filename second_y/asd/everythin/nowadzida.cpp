// Cpp program to Find Minimum Sum Path in a Triangle
// Using Tabulation
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> tab(n);

    for (int i = 0; i < n; i++)
        cin >> tab[i];

    // Obliczanie liczby wierszy
    int rows = 0;
    int tmp = n;
    while (tmp > 0) {
        rows++;
        tmp -= rows;
    }

    // Wyliczamy początek każdego rzędu
    vector<int> start(rows);
    int s = 0;
    for (int r = 0; r < rows; r++) {
        start[r] = s;
        s += r + 1;
    }

    // Dynamiczne liczenie od dołu do góry
    for (int r = rows - 2; r >= 0; r--) {
        int curr = start[r];        // początek wiersza r
        int next = start[r + 1];    // początek wiersza r+1

        for (int i = 0; i <= r; i++) {
            tab[curr + i] += max(tab[next + i], tab[next + i + 1]);
        }
    }

    cout << tab[0] << endl;
}


/*
#include <iostream>
#include <vector>
using namespace std;

int minSumPath(vector<vector<int> > &triangle) {
  
    int n = triangle.size();
  
  	// Dp array to store the result
    vector<vector<int>> dp(n, vector<int>(n));
    
    // Base Case: The last row will be the same as matrix
    for (int i = 0; i < n; i++) 
        dp[n-1][i] = triangle[n - 1][i]; 

    // Calculation of the remaining rows,
    // in bottom up manner
    for (int i = n - 2; i >= 0; i--) 
        for (int j = 0; j < triangle[i].size(); j++) 
            dp[i][j] = triangle[i][j] + max(dp[i + 1][j],
                                    dp[i + 1][j + 1]);

    return dp[0][0];
}

int main() {
    vector<vector<int> > triangle{{2},
                                {3, 9},
                                {1, 6, 7}};
    cout << minSumPath(triangle);
    return 0;
}
*/
