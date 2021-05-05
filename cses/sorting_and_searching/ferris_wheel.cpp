#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Maximum number of subsets of 1 <= size <= 2 whose sum is at most X.
 */
int main() {
    int n, x;
    cin >> n >> x;

    int children[n];
    for (int i = 0; i < n; i++) {
        cin >> children[i];
    }
    sort(children, children+n);

    int l = 0;
    int r = n - 1;
    int count = 0;

    while (l <= r) {
        if (children[l] + children[r] > x) {  // take right only
            r--;
        } else {  // take two
            l++;
            r--;
        }
        count ++;
    } 

    cout << count << endl;
}