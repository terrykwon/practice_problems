#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        // Notice that the height of the rectangle is bounded by min(left,
        // right). Therefore the optimum at the unbounded end is simply the
        // furthest bar. Other closer possibilities don't have to be considered.
        int l = 0;
        int r = height.size() - 1;
        int max_area = 0;
        while (l < r) {
            int area = min(height[l], height[r]) * (r - l);
            if (area > max_area) {
                max_area = area;
            }
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return max_area;
    }
};

int main() {
    Solution s;
    vector<int> height = {1,8,6,2,5,4,8,3,7};

    cout << s.maxArea(height) << endl;
}