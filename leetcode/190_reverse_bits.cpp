#include <iostream>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t m = 0;
        for (int i = 0; i < 32; i++) {
            uint32_t x = n & 1;
            m = m << 1;
            m = m | x;
            n = n >> 1;
        }
        return m;
    }
};