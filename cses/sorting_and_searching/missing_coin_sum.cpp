#include <iostream>
#include <algorithm>
using namespace std;

/** 
 * Keep track of the maximum value such that 1 ... max can all be produced.
 * If we sort the array and iterate through, then at iteration k+1, the previous
 * max is at least k. Then arr[k+1] can be any of 1 ... max+1, and now all of
 * max + arr[k+1] can be produced!
 * 
 * This can be proved by induction on k.
 */
int main() {
    int n;
    cin >> n;
    long long arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);

    long long max = 0;

    for (int i = 0; i < n; i++) {
        // We want to make i+1
        if (i+1 <= max) {
            if (arr[i] <= max+1) {
                max += arr[i];
            }
            continue;
        }
        if (arr[i] <= i+1) {  // at this point, max=i
            max += arr[i];
            continue;
        }
        cout << i+1 << endl;
        return 0;
    }
    cout << max+1 << endl;
}