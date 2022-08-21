#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // If subsequence sum falls below zero, it is always better to start a
        // new subsequence. The corner case is when all elements are zero.
        long long sum = 0;       
        long long max_sum = nums[0];
        for (int i : nums) {
            sum += i; 
            if (sum > max_sum) {
                max_sum = sum;
            }
            if (sum < 0) {
                sum = 0;
            }
        }
        return max_sum;
    }
};

int main() {
    
}
