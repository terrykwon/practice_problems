#include <vector>
#include <map>
#include <set>
#include <iostream>
using namespace std;


// return all quadruplets such that four elements sum to `target`.
// O(N^2 logN)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> quad_set;

        map<int, vector<pair<int, int>>> pairwise_sums;

        for (int a = 0; a < nums.size()-1; a++) {
            for (int b = a+1; b < nums.size(); b++) {
                int sum = nums[a] + nums[b];
                pairwise_sums[sum].push_back(make_pair(a, b));
            }
        }

        map<int, bool> lookup_history;

        // iterate over all pairwise sums, look up target - sum
        for (auto it = pairwise_sums.begin(); 
                it != pairwise_sums.end(); it++) {
            int sum = it->first;

            // The "complement" has already been searched over
            if (lookup_history[target-sum]) {
                continue;
            } 
            lookup_history[sum] = true;

            int to_find = target - sum;

            if (pairwise_sums.find(to_find) == pairwise_sums.end()) {
                continue;
            }
            vector<pair<int, int>> found = pairwise_sums[to_find];
            vector<pair<int, int>> existing = it->second;

            // combine all combinations of pairs
            // but there cannot be overlaps
            for (int i = 0; i < found.size(); i++) {
                pair<int, int> found_pair = found[i];

                for (int j = 0; j < existing.size(); j++) {
                    pair<int, int> existing_pair = existing[j];

                    // Some indices are double-counted, i.e.) 0 1 2 3 and
                    // 2 0 3 1 may be both found, but since the quadruplet
                    // is identical, the set only stores one copy.
                    if (!(found_pair.first == existing_pair.first
                            || found_pair.first == existing_pair.second
                            || found_pair.second == existing_pair.first
                            || found_pair.second == existing_pair.second)) {

                        vector<int> quad;
                        quad.push_back(nums[existing_pair.first]);
                        quad.push_back(nums[existing_pair.second]);
                        quad.push_back(nums[found_pair.first]);
                        quad.push_back(nums[found_pair.second]);

                        sort(quad.begin(), quad.end());

                        quad_set.insert(quad);
                    }
                }
            }
        }

        vector<vector<int>> quadruplets;
        copy(quad_set.begin(), quad_set.end(), back_inserter(quadruplets));

        return quadruplets;
    }
};

int main() {
    Solution s;
    vector<int> nums{1, 2, 3, 4, 2};
    int target = 10;
    vector<vector<int>> quadruplets = s.fourSum(nums, target);

    for (auto v : quadruplets) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
}