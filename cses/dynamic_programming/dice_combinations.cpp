#include <iostream>
using namespace std;


const int N = 1000001;
int M[N] = {0};
const int mod = 1'000'000'007;

/**
 * Recursive DP solution.
 */
int f(int x) {
    if (M[x] != 0) {
        return M[x];
    }

    int y = 0;
    for (int i = 1; i <= 6; i++) {
        if (x-i < 0) {
            break;
        }
        y = (y + f(x-i)) % mod;
    }
    M[x] = y;
    return y;
}

int main() {
    int n;
    cin >> n;

    M[0] = 1;
    M[1] = 1;

    int ans = f(n);
    cout << ans << endl;
}