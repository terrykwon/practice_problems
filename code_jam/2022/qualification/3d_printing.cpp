#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

int L = 1e6;
void test_case(int t) {
    vector<vector<int>> ink;

    for (int i = 0; i < 4; i++) {
        vector<int> v;
        ink.push_back(v); 
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            int x;
            cin >> x;
            ink[j].push_back(x);
        }
    }

    int mins[4];

    for (int i = 0; i < 4; i++) {
        mins[i] = *min_element(ink[i].begin(), ink[i].end());
    }

    cout << "Case #" << t << ": ";

    int sum = accumulate(mins, mins+4, 0);
    if (sum < L) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    int left = L;
    for (int i = 0; i < 4; i++) {
        int take = min(left, mins[i]);
        left -= take;
        cout << take << " ";
        if (left == 0) {
            for (int j = i+1; j < 4; j++) {
                cout << 0 << " ";
            }
            cout << endl;
            return;
        }
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        test_case(t);
    }
}