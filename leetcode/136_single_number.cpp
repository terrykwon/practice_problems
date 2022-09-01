#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // XOR trick
        int x = 0;
        for (int n : nums) {
            x = x ^ n;
        }
        return x;
    }
};