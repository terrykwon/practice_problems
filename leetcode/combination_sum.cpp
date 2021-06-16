#include <iostream>
#include <vector>
#include <set>
using namespace std;


void print_vv(vector<vector<int>> v) {
    for (auto outer : v) {
        for (auto inner : outer) {
            cout << inner << " ";
        }
        cout << endl;
    }
}

void print_set(set<int>& s) {
    for (auto e : s) {
        cout << e << " ";
    }
    cout << endl;
}

/**
 * This solution uses a DP table, but actually is equivalent in time complexity
 * to just DFS + backtracking as it revists all past "branches" (combinations),
 * and less memory-efficient as well.
 */
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        const int MAX_N = 500;
        vector<vector<vector<int>>> dp(MAX_N+1);

        // range constructor
        set<int> unique_numbers(candidates.begin(), candidates.end());

        for (int c : unique_numbers) {
            dp[c].push_back({c});
            for (int i = 1; i <= target; i++) {
                if (i - c > 0 && dp[i-c].size() > 0) {
                    for (vector<int> v : dp[i-c]) {
                        vector<int> v_copy = v;
                        v_copy.push_back(c);
                        dp[i].push_back(v_copy);
                    }
                } 
            }
        }

        return dp[target];
    };

};

int main() {
    vector<int> candidates{2,2,3,5};
    int target = 8;
    Solution s;
    print_vv(s.combinationSum(candidates, target));

}