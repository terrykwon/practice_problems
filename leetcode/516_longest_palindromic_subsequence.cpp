#include <iostream>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        int M[1001][1001] = {0};
        pair<int, int> prev[1001][1001];
        char added[1001][1001];

        for (int i = 0; i < n; i++) {
            M[i][i] = 1;
            prev[i][i] = {-1, -1};
            added[i][i] = s[i];
        }

        for (int i = n-1; i >= 0; i--) {
            for (int j = i+1; j < n; j++) {
                if (s[i] == s[j]) {
                    M[i][j] = M[i+1][j-1] + 2;
                    prev[i][j] = {i+1, j-1};
                    added[i][j] = s[i];
                } else {
                    if (M[i+1][j] > M[i][j-1]) {
                        M[i][j] = M[i+1][j];
                        prev[i][j] = {i+1, j};
                    } else {
                        M[i][j] = M[i][j-1];
                        prev[i][j] = {i, j-1};
                    }
                    added[i][j] = '0';
                }
            }
        }

        pair<int, int> x = {0, n-1};
        int l = M[0][n-1];
        string subsequence = "";
        while (1) {
            pair<int, int> y = prev[x.first][x.second];
            if (y.first < 0 || y.second < 0) {
                break;
            }
            if (M[x.first][x.second] > M[y.first][y.second]) {
                subsequence += added[x.first][x.second];
            }
            x = y;
        }

        cout << subsequence << endl;

        return M[0][n-1];
    }
};