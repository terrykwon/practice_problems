#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long n, x;
    cin >> n >> x;
    vector<pair<long long, int>> arr;  // (value, index) to preserve index while sorting
    for (int i = 0; i < n; i++) {
        int y;
        cin >> y;
        pair<long long, int> p;
        p.first = y;
        p.second = i;
        arr.push_back(p);
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            // Two-pointer method
            int l = 0;
            int r = n - 1;
            long long target = x - arr[i].first - arr[j].first;

            while (l < r) {
                if (l == i || l == j) {
                    l++;
                    continue;
                } else if (r == i || r == j) {
                    r--;
                    continue;
                }
                long long current = arr[l].first + arr[r].first;
                if (current == target) {
                    cout << arr[i].second+1 << " " 
                            << arr[j].second+1 << " "
                            << arr[l].second+1 << " " 
                            << arr[r].second+1 << " " << endl ;
                    return 0;
                } else if (current > target) {
                    r--;
                } else {
                    l++;
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}