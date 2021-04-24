#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    long long x, y;
    long long ans;
    for (int i = 0; i < t; i++) {
        cin >> y >> x;

        if (y >= x) {
            if (y % 2) {  // odd
                ans = (y-1)*(y-1) + x;
            } else {
                ans = y*y - x + 1;
            }
        } else {
            if (x % 2) {  // odd
                ans = x*x - y + 1;
            } else {
                ans = (x-1)*(x-1) + y;
            }
        } 
        cout << ans << endl;
    } 
}