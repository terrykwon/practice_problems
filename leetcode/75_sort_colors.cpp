#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Dutch national flag problem---Dijkstra's algorithm.
     */
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int k = n - 1;
        int pivot = 1;

        while (j <= k) {
            if (nums[j] < pivot) {
                swap(nums[j], nums[i]);
                i++;
                j++;
            } else if (nums[j] == pivot) {
                j++;
            } else {
                swap(nums[k], nums[j]);
                k--;
            }
        } 
    }
};