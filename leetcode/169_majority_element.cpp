#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Naive: just counter -> check if any >= half.
        // Interesting: Boyer–Moore majority vote algorithm        
        // but very limited advantage: saves hashmap space.
        int candidate = nums[0];
        int flag = 1;
        for (int i = 1; i < nums.size(); i++) {
            int current = nums[i];
            if (current != candidate) {
                flag -= 1;
            } else {
                flag += 1;
            }
            if (flag < 0) {
                candidate = current;
                flag = 1;
            }
        }
        return candidate;
    }
};