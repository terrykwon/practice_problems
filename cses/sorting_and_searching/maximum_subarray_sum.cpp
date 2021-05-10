#include <iostream>
using namespace std;

/**
 * We can update the maximum sum attainable at each i from 0 ... n-1 in a single
 * pass.
 *
 * This can be done by observing that the maximum at (k+1) depends on the
 * maximum at k.
 */
int main() {
    int n;
    cin >> n;
    long long arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long max_sum = arr[0];
    long long current_sum = arr[0];
    for (int i = 1; i < n; i++) {
        current_sum = max(current_sum+arr[i], arr[i]);
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }
    cout << max_sum << endl;
}