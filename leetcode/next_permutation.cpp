#include <iostream>
#include <vector>
using namespace std;

/**
 * Return the next lexicographically greater permutation.
 * Must be in-place. 
 * 
 * Important algorithm! Knuth TAOCP Algorithm L (volume 4A).
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 2) {
            return;
        }

        int j = nums.size() - 2;
        while (nums[j] >= nums[j+1]) {  // j: last index that can be changed
            --j;

            if (j < 0) {
                sort(nums.begin(), nums.end());
                return;
            }
        }

        int l = nums.size() - 1;

        while (l >= 1 && nums[l] <= nums[j]) {  // l: smallest increase
            --l;
        }

        swap(nums[j], nums[l]);
        reverse(nums.begin()+j+1, nums.end());
    }
};

int main() {
    Solution s;
    vector<int> a{1,5,1};
    for (int i = 0; i < 5; i++) {
        for (auto e : a) {
            cout << e << " ";
        }
        cout << endl;
        s.nextPermutation(a);
    }
}

