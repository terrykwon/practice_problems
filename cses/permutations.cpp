#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 2 || n == 3) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    // print one of {even, odd} first in reverse order, then print the other.
    // then the only part we have to worry about is the boundary, which is
    // either largest_odd - smallest_even, or largest_even - smallest_odd.
    // for n=4, the former is 3-2=1, which doesn't work. Therfore the latter
    // is optimal.
    for (int i = n-1; i >= 1; i-=2) {
        cout << i << " ";
    }

    for (int j = n; j >= 1; j-=2) {
        cout << j << " ";
    }
    cout << endl;
}