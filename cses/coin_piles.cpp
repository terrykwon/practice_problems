#include <iostream>
using namespace std;


// Why does this work???
// Can prove by induction on the total number of coins (which must be divisible
// by 3). 3 coins can be added only by adding (1,2) or (2,1).
void solve() {
    long long a, b;
    cin >> a >> b;

    if ((a + b) % 3 != 0 || a > b*2 || b > a*2) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

int main() {
    int t;
    cin >> t;    
    for (int i = 0; i < t; i++) {
        solve();
    }
}