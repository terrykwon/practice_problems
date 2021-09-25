#include <iostream>
using namespace std;

/**
 * The 0-1 knapsack problem
 */ 

// Max value with the first i items and constraint k
int M[1001][100001];

int main() {
    int n, x;
    cin >> n >> x;    

    // In DP problems, the table often requires index 0 for empty values,
    // so 1-indexing all array might be more convenient!
    int h[n+1];
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    int s[n+1];
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    M[0][0] = 0;

    // IMPORTANT: switching the loop order will cause far slower execution
    // due to memory access, and cause TLE. Even if the answer correct, pay
    // attention to the table row and column structure and iterate innermost
    // on columns!
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= x; w++) {
            if (h[i] > w) {  // prevents negative index access for [w-h[i]]
                M[i][w] = M[i-1][w];
            } else {
                // (1) don't take current item, (2) take current item
                M[i][w] = max(M[i-1][w], M[i-1][w-h[i]] + s[i]);
            }
        }
    }
    cout << M[n][x] << endl;
}
