#include <iostream>
#include <vector>
#include <algorithm>  // sort
using namespace std;


/**
 * Maximum number of intersecting intervals at any given time.
 * 
 * Imagine counting the number of people inside a subway station, with entrance
 * and exit machines!
 */
int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> records;

    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        records.push_back({start, 1});
        records.push_back({end, -1});
    }

    int count = 0;
    int max = 0;

    sort(records.begin(), records.end());  // sorte by first elements
    for (auto r : records) {
        count += r.second;
        if (count > max) {
            max = count;
        }
    }

    cout << max << endl;
}