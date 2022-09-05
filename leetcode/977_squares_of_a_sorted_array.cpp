#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // Create two arrays. Note: we can do this in-place with two pointers.
        //
        // [-4,-1,0,3,10] 
        // [-4 -1], [0, 3, 10]
        // [16 1], [0 9 100]
        // [1 16] [0 9 100]
        deque<int> u;
        deque<int> v;
        for (int n : nums) {
            if (n < 0) {
                u.push_front(n*n);
            } else {
                v.push_back(n*n);
            }
        }

        // Combine the two sorted arrays u and v. This is the merge operation
        // in merge sort.
        int i = 0;
        int j = 0;
        vector<int> result;
        while (i < u.size() || j < v.size()) {
            if (i == u.size()) {
                result.push_back(v[j]);
                j++;
            } else if (j == v.size()) {
                result.push_back(u[i]);
                i++;
            } else if (u[i] > v[j]) {
                result.push_back(v[j]);
                j++;
            } else {  // u[i] <= v[j]
                result.push_back(u[i]);
                i++;
            }
        }
        return result;
    }
};