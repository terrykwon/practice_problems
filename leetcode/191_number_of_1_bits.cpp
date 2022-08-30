#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int weight = 0;
        while (n > 0) {
            n = n & (n-1);  // "Removes" least significant bit.
            weight++;
        }
        return weight; 
    }
};