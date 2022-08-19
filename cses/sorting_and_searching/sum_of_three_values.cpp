#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> arr;  // (value, index) to preserve index while sorting
    for (int i = 0; i < n; i++) {
        int y;
        cin >> y;
        pair<int, int> p;
        p.first = y;
        p.second = i;
        arr.push_back(p);
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        // Two-pointer method
        int l = 0;
        int r = n - 1;
        int target = x - arr[i].first;

        while (l < r) {
            if (l == i) {
                l++;
                continue;
            } else if (r == i) {
                r--;
                continue;
            }
            int current = arr[l].first + arr[r].first;
            if (current == target) {
                cout << arr[i].second+1 << " " << arr[l].second+1 << " " 
                        << arr[r].second+1 << " " << endl ;
                return 0;
            } else if (current > target) {
                r--;
            } else {
                l++;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}