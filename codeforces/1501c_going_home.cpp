#include <iostream>
#include <algorithm>  // sort
#include <vector>
using namespace std;


const int N = 5000005;  // maximum sum of pairs


int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // A lookup table for sums
    pair<int, int> sums[N];

    for (int a = 0; a < n-1; a++) {
        for (int b = a+1; b < n; b++) {
            int sum = arr[a] + arr[b];

            if (sums[sum].first == 0 && sums[sum].second == 0) {
                sums[sum].first = a;
                sums[sum].second = b;
            } else if ((sums[sum].first != a && sums[sum].second != b) 
                    && (sums[sum].first != b && sums[sum].second != a)) {
                cout << "YES" << endl;
                // Array starts from 1
                printf("%d %d %d %d\n", a+1, b+1, 
                        sums[sum].first+1, sums[sum].second+1);
                return 0;
            }
        }
    }
    cout << "NO" << endl;

    // check initial value of pair array
    // for (int i = 0; i < 5; i++) {
    //     cout << sums[i].first << " " << sums[i].second << endl;
    //     // outputs 0, 0
    // }

}