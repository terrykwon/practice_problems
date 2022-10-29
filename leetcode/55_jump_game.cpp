#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jump_left = nums[0];
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > jump_left) {
                jump_left = nums[i];
            }
            if (jump_left == 0) {
                return false;
            }
            jump_left -= 1;
        }
        return true;
    }
};