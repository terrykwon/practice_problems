#include <vector>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> sums;
        sums.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++) {
            sums.push_back(sums.back() + nums[i]);
        }
        return sums;
    }
};