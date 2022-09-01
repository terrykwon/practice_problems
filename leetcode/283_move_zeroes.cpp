#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int z = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                // The final position of nums[i] is z.
                // The next number, if it exists, fills position z+1.
                nums[z] = nums[i];
                z++;
            }
        }
        fill(nums.begin()+z, nums.end(), 0);
    }
};