class Solution {
public:
    int M[101][101] = {0};
    int uniquePaths(int m, int n) {
        for (int i = 1; i <= m; i++) {
            M[i][1] = 1;
            for (int j = 2; j <= n; j++) {
                M[i][j] = M[i-1][j] + M[i][j-1];  // Only down or right
            }
        } 
        return M[m][n];
    }
};