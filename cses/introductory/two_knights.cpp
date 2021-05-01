#include <iostream>
using namespace std;

/**
 * Interesting counting problem.
 * Observe that we can easily count the number of 2x3 or 3x2 squares in the
 * grid.
 */
int main() {
    long long n;
    cin >> n;

    long long all_possibilities;
    long long fighting_knights;

    for (long long k = 1; k <= n; k++) {
        all_possibilities = ((k*k) * (k*k-1)) / 2;
        fighting_knights = 4*(k-1)*(k-2);
        cout << all_possibilities - fighting_knights << endl;
    }
}