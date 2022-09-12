#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, compare> k_closest;

        for (auto p : points) {
            k_closest.push(p);
            if (k_closest.size() > k) {
                k_closest.pop();
            }
        }

        vector<vector<int>> result;
        for (int i = 0; i < k; i++) {
            result.push_back(k_closest.top());
            k_closest.pop();
        }

        return result;
    }

private:
    /**
     * A binary predicate that takes two elements of type T and returns a bool.
     */
    struct compare {
        bool operator()(vector<int>& p, vector<int>& q) {
            return p[0]*p[0]+p[1]*p[1] < q[0]*q[0]+q[1]*q[1]; 
        }
    };
};