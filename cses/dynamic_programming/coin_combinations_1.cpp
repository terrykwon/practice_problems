#include <iostream>
using namespace std;

const int MOD = 1'000'000'007;
const int N = 1'000'001;
int M[N] = {0};

int main() {
    int n, x;
    cin >> n >> x;
    
    int coins[n];
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
        M[coins[i]] = 1;
    }

    for (int i = 1; i <= x; i++) {
        int sum = M[i];
        for (int c : coins) {
            if (i - c < 1) {
                continue;
            }
            sum = (sum + M[i-c]) % MOD;
        }
        M[i] = sum;
    }

    cout << M[x] << endl;
}