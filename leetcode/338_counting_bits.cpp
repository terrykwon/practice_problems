#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> results(n+1);
        results[0] = 0;

        int x = 1;
        for (int i = 1; i <= n; i++) {
            if (i == 2*x) {
                x *= 2;
            }
            results[i] = 1 + results[i-x];
        }
        return results;
    }
};