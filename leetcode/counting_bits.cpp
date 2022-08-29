#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        if (n == 0) {
            return vector<int> {0};
        }
        vector<int> results(n+1);
        results[0] = 0;
        results[1] = 1;

        int x = 2;
        for (int i = 2; i <= n; i++) {
            if (i == 2*x) {
                x *= 2;
            }
            results[i] = 1 + results[i-x];
        }
        return results;
    }
};