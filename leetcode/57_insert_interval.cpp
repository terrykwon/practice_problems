#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        bool inserted = false;
        int n = intervals.size();

        vector<vector<int>> result;

        for (int i = 0; i < n; i++) {
            vector<int> v = intervals[i];
            if (v[0] > newInterval[1]) {
                // newInterval is behind -> insert here
                result.push_back(newInterval);

                result.insert(result.end(), intervals.begin()+i, intervals.end());
                inserted = true;
                break;
            } else if ((v[0] >= newInterval[1] && v[1] <= newInterval[0])
                    || (v[1] >= newInterval[0] && v[0] <= newInterval[1])) {
                // newInterval overlaps
                newInterval[0] = min(v[0], newInterval[0]);
                newInterval[1] = max(v[1], newInterval[1]);
            } else {
                // newInterval is ahead
                result.push_back(v);
            }
        }
        if (!inserted) {
            result.push_back(newInterval);
        }
        return result;
    }
};