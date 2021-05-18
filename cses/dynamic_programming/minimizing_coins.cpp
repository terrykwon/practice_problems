#include <iostream>
using namespace std;

const int N = 1'000'001;
const int MAX_COINS = 1'000'001;
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
        if (M[i] == 1) {
            continue;
        }
        int min_coins = MAX_COINS;
        for (int c : coins) {
            if (i-c >= 1 && M[i-c] > 0) {
                min_coins = min(min_coins, M[i-c]+1);                
            }
        }

        if (min_coins == MAX_COINS) {
            M[i] = -1;
        } else {
            M[i] = min_coins;
        }
    }

    cout << M[x] << endl;
}