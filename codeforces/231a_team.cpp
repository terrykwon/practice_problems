#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int p, v, c;
        cin >> p >> v >> c;
        if (p + v + c >= 2) ans++; 
    }
    cout << ans << endl;
}