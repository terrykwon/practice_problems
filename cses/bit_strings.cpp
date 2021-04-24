#include <iostream>
using namespace std;

// use property of modulo
// (a*b) mod m = (a mod m) * (b mod m) mod m 
int main() {
    int n;
    cin >> n;

    long long ans = 1;
    long long mod = (long long)1e9 + 7;
    // cout << mod << endl;
    for (int i = 0; i < n; i++) {
        ans = (ans * 2) % mod;
    }
    cout << ans << endl;
}