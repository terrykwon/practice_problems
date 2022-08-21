#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size();

        while (l < r) {
            int m = (l+r) / 2;
            if (nums[m] == target) {
                return m;
            } else if (nums[m] < target) {
                l = m+1;
            } else {
                r = m;
            }
        }
        return -1;        
    }
};


int main() {
    
}