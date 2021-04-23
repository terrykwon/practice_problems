#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    long long sum = (n*n + n) / 2;
    long long x;
    for (int i = 0; i < n-1; i++) {
        cin >> x;
        sum -= x;
    }
    cout << sum << endl;
}