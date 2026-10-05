using namespace std;

int levenshteinFullMatrix(const string& str1,
                        const string& str2)
{
    int m = str1.length();
    int n = str2.length();

    vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++) {
        dp[i][0] = i;
    }

    for (int j = 0; j <= n; j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = 1
                        + min(

                            // Insert
                            dp[i][j - 1],
                            min(

                                // Remove
                                dp[i - 1][j],

                                // Replace
                                dp[i - 1][j - 1]));
            }
        }
    }

    return dp[m][n];
}

// Drivers code
int main()
{
    string str1 = "kitten";
    string str2 = "sitting";

    // Function Call
    int distance = levenshteinFullMatrix(str1, str2);
    cout << "Levenshtein Distance: " << distance << endl;
    return 0;
}