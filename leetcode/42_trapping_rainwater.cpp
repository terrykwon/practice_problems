#include <iostream>
#include <vector>
using namespace std;


/**
 * Single pass solution. Observe that if there exists a taller wall further
 * ahead, then the height of the puddle is bound by the left wall (and the same
 * in the opposite direction).
 */ 
class Solution2 {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        if (n == 0) return ans;

        int left = 0;
        int right = n-1;

        int left_max = 0;
        int right_max = 0;

        while (left < right) {
            left_max = max(left_max, height[left]);  // max including itself
            right_max = max(right_max, height[right]);

            if (left_max < right_max) {  // left is a definite bound
                ans += left_max - height[left];
                left++;
            } else {
                ans += right_max - height[right];
                right--;
            }
        }
        return ans;
    }
};

/**
 * Dynamic programming solution, O(2n) pass with O(2n) memory.
 */
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;

        if (n == 0) return ans;

        // Stores the left and right "walls" relative to each position.
        int left_max[n]; 
        int right_max[n];
 
        left_max[0] = 0;
        for (int i = 1; i < n; i++) {
            left_max[i] = max(left_max[i-1], height[i-1]);
        }
        
        right_max[n-1] = 0;
        for (int i = n-2; i >= 0; i--) {
            right_max[i] = max(right_max[i+1], height[i+1]);
        }

        for (int i = 0; i < n; i++) {
            ans += max(min(left_max[i], right_max[i]) - height[i], 0);
        }

        return ans;
    }
};


int main() {
    Solution2 s;
    vector<int> h1 = {1,2,3,4,5};  // 0
    vector<int> h2 = {4,2,0,4,3,2,5};  // 9
    vector<int> h3 = {4,1,5,1,3,3,1,4,1};  // 11
    vector<int> h4 = {5,4,1,2};  // 1
    cout << s.trap(h1) << endl;
    cout << s.trap(h2) << endl;
    cout << s.trap(h3) << endl;
    cout << s.trap(h4) << endl;
    
}