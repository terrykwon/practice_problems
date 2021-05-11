#include <iostream>
#include <algorithm>
using namespace std;

/**
 * Find the value that minimizes the sum of absolute deviations from each point
 * to that value.
 * 
 * https://math.stackexchange.com/questions/113270/the-median-minimizes-the-sum-of-absolute-deviations-the-ell-1-norm
 */
int main() {
    int n;
    cin >> n;    
    long long arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n);
    long long sum_deviations = 0;
    long long median = arr[(n-1)/2];

    for (auto a : arr) {
        sum_deviations += abs(median - a);
    }

    cout << sum_deviations << endl;
}