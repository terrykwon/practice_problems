#include <iostream>
#include <vector>
#include <algorithm>  // sort
using namespace std;

bool comparator(const pair<int,int> &a, const pair<int,int> &b) {
    return (a.second < b.second);
}

/**
 * Maximum number of non-overlapping intervals.
 */
int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> intervals;

    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        intervals.push_back({start, end});
    }

    sort(intervals.begin(), intervals.end(), comparator);

    int count = 0;
    int last_end = 0;
    for (auto c : intervals) {
        if (c.first >= last_end) {
            count++;
            last_end = c.second;
        }
    }

    cout << count << endl;
}