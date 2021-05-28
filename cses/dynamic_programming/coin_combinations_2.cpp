#include <iostream>
using namespace std;

const int MOD = 1'000'000'007;
const int N = 1'000'001;
int M[N] = {0};

/**
 * Count the number of unordered combinations that sum to X.
 * 
 * This can be done simply by thinking of the recursion
 * F(k, i) = the number of *unordered* ways to obtain sum k using only the 
 * coins 1 ... i. Then F(k, i+1) would not overcount, since the it is the first
 * time the (i+1)th coin has been used.
 */
int main() {
    int n, x;
    cin >> n >> x;
    
    int coins[n];
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    M[0] = 1;

    for (int c : coins) {
        for (int i = 0; i <= x; i++) {
            int sum = M[i];
            if (i - c < 0) {
                continue;
            }
            sum = (sum + M[i-c]) % MOD;
            M[i] = sum;
        }
    }

    cout << M[x] << endl;
}