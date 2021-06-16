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
 * 1 <= candidates.length <= 30
 * 1 <= candidates[i] <= 200
 * All elements of candidates are distinct.
 * 1 <= target <= 500
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
                        // cout << c << endl;
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