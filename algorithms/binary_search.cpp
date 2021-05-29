#include <iostream>
#include <numeric>  // iota
#include <vector>
using namespace std;


/**
 * How to make this work on any list-like data type?
 */
int binary_search(vector<int> arr, int target) {
    int l = 0;
    int r = arr.size() - 1;
    int m;

    while (l <= r) {
        m = (l+r) / 2;
        if (arr[m] < target) {
            l = m + 1;
        } else if (arr[m] > target) {
            r = m - 1;
        } else {
            return m;
        }
    }

    return -1;
}

int main() {
    vector<int> sorted(10);
    iota(sorted.begin(), sorted.end(), 0);

    for (auto i : sorted) {
        cout << i << " ";
    }
    cout << endl;

    for (int i = 0; i < 10; i++) {
        cout << binary_search(sorted, i) << " ";
    }
    cout << endl;

    vector<int> small = {0, 1};
    cout << binary_search(small, 0) << endl;
    cout << binary_search(small, 1) << endl;
    
    vector<int> smaller = {0};
    cout << binary_search(smaller, 0) << endl;
}