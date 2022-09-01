#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int l = 0;
        long long d_l = 1;
        long long d_r = 1;
        int y = x;
        while (y) {  // Just log(x) + 1
            y /= 10;
            l++;
            d_l *= 10;
        }

        for (int i = 0; i < l/2; i++) {
            int left = (x % d_l) / (d_l/10);
            int right = (x / d_r) % 10;
            if (left != right) {
                return false;
            }
            d_r *= 10;
            d_l /= 10;
        }
        return true;
    }
};