#include <iostream>
#include <numeric>
using namespace std;


/**
 * Partition set into two subsets such that the difference between their sums
 * is minimal.
 * 
 * Naive iteration over all 2^n subsets. 
 * 
 * Polynomial time is impossible: the subset sum problem (whether there exists
 * a subset that sums to T) is NP-complete.
 * 
 * References: 
 * - https://en.wikipedia.org/wiki/Partition_problem
 * - https://en.wikipedia.org/wiki/Pseudopolynomial_time_number_partitioning
 */ 
long long iterate_min(long long* arr, int n, int current, long long sum, long long total) {
    if (current == n) {
        return llabs(2 * sum - total);
    } 

    long long include = iterate_min(arr, n, current+1, sum+arr[current], total);
    long long exclude = iterate_min(arr, n, current+1, sum, total);

    return min(include, exclude);
}


int main() {
    int n;
    cin >> n;
    long long p[n];    

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    long long total = 0;
    total = accumulate(p, p+n, total);

    long long min = iterate_min(p, n, 0, 0, total);

    cout << min << endl;
}