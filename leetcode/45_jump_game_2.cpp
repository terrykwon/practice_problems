#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        int count = 1;
        int end = nums[0];       
        int i = 1;

        while (end < nums.size() - 1) {
            int max = end;
            while (i < nums.size() && i <= end) {
                if (i + nums[i] > max) {
                    max = i + nums[i];
                }
                i++;
            } 
            end = max;
            count++;
        } 
        return count;
    }
}; 