#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

/**
 * Intuition: can store ALL current intervals in a multiset.
 */ 
int main() {
    // TLE without these two lines (>1s vs. 0.66s, large difference)
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    int x, n, p;    
    cin >> x >> n;

    set<int> lights{0, x};
    multiset<int> distances{x};

    for (int i = 0; i < n; i++) {
        cin >> p;
        // ** VERY IMPORTANT: using std::lower_bound(lights.begin(), ...)
        // is O(N), not O(log(N))!!!!!!

        // finds the first light greater than p
        // auto it_right = lower_bound(lights.begin(), lights.end(), p);
        auto it_right = lights.lower_bound(p);
        auto it_left = it_right;
        --it_left;

        distances.erase(distances.find(*it_right - *it_left));

        distances.insert(*it_right - p);
        distances.insert(p - *it_left);
        lights.insert(p);  // inserts before position it_lower

        auto it_last = distances.end();
        --it_last;  // the last value is the position before end()

        cout << *it_last << " ";
    }
    return 0;
}

// Naive: O(N), TLE
void main2() {
    int x, n;    
    cin >> x >> n;

    vector<int> lights = {0, x};
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p; 
        auto lower = lower_bound(lights.begin(), lights.end(), p);
        lights.insert(lower, p);

        int max = 0;
        for (int j = 1; j < lights.size(); j++) {
            if (lights[j] - lights[j-1] > max) {
                max = lights[j] - lights[j-1];
            }
        }
        cout << max << " ";
    }
}