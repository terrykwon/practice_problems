#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    char grid[n][n];   

    // use vector to initialize with 0's
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));  

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    if (grid[0][0] == '*') {
        cout << 0 << endl;
        return 0;
    } 

    dp[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if ((i == 1 & j == 1) || grid[i-1][j-1] == '*') {
                continue;
            }
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    }

    cout << dp[n][n] << endl;
}