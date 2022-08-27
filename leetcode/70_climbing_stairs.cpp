#include <iostream>
using namespace std;

const int N = 50;
int M[N] = {0};

class Solution {
public:
    int climbStairs(int n) {
        // Note that we can store just the previous two values instead of
        // the entire history as a DP table!
        M[1] = 1;
        M[2] = 2;
        for (int i = 3; i <= n; i++) {
            M[i] = M[i-1] + M[i-2];
        }
        return M[n];
    }
};