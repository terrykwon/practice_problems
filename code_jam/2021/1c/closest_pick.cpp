#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;


void test_case() {
    int n;
    long long k;
    cin >> n >> k;

    vector<long long> picked;
    for (int i = 0; i < n; i++) {
        long long p;
        cin >> p;
        picked.push_back(p);
    }

    sort(picked.begin(), picked.end());

    vector<long long> intervals;

    for (int i = 0; i < picked.size() - 1; i++) {
        intervals.push_back(picked[i+1] - picked[i]);
    }

    long long first_interval = picked[0] - 1;
    long long last_interval = k - picked[picked.size() - 1];
    
    long long maximum;
    if (picked.size() <= 1) {
        maximum = first_interval + last_interval;
    } else {
        sort(intervals.begin(), intervals.end(), greater<int>());

        maximum = max({first_interval + last_interval,
                first_interval + intervals[0]/2,
                last_interval + intervals[0]/2,
                intervals[0]/2 + intervals[1]/2,
                intervals[0]-1});
    }

    double prob = (double)(maximum) / k;
    cout << prob << endl;
}


int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        test_case();
    }
}