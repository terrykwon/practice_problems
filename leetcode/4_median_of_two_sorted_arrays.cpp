#include <iostream>
#include <vector>
#include <list>
using namespace std;

// Optimal solution: O(log(n+m));
// TODO: return
class Solution2 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    }
};

// Simple solution: (n+m), incrementing two indices.
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int mid = (n+m) / 2;
        int i = 0;
        int j = 0;

        // pair.first = 0 if i, 1 if j.
        // pair.second = index
        list<pair<int,int>> last_two_indices;
        while (i+j < mid + 1) {
            if (i >= n) {
                last_two_indices.push_back({1, j});
                j++;
            } else if (j >= m) {
                last_two_indices.push_back({0, i});
                i++;
            } else if (nums1[i] < nums2[j]) {
                last_two_indices.push_back({0, i});
                i++;
            } else {
                last_two_indices.push_back({1, j});
                j++;
            }
            if (last_two_indices.size() > 2) {
                last_two_indices.pop_front();
            }
        }

        if ((n+m) % 2 == 0) {
            pair<int, int> left_pair = last_two_indices.front();
            pair<int, int> right_pair = last_two_indices.back();
            double sum = 0.0;

            if (left_pair.first == 0) {
                sum += nums1[left_pair.second];
            } else {
                sum += nums2[left_pair.second];
            }

            if (right_pair.first == 0) {
                sum += nums1[right_pair.second];
            } else {
                sum += nums2[right_pair.second];
            }

            return sum / 2;
        } else {
            pair<int, int> median_pair = last_two_indices.back();
            if (median_pair.first == 0) {
                return nums1[median_pair.second];
            } else {
                return nums2[median_pair.second];
            }
        }

        return 0;
    }
};

int main() {
    Solution s;
    vector<int> nums1{2, 3};
    vector<int> nums2{4, 5, 6};
    double median = s.findMedianSortedArrays(nums1, nums2);
    cout << median << endl;
}