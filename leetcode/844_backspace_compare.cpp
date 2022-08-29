#include <iostream>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i_s = s.length()-1;
        int i_t = t.length()-1;
        int skip_s = 0;
        int skip_t = 0;

        while (i_s >= 0 || i_t >= 0) {
            char c_s = i_s >= 0 ? s[i_s] : '*';  // null character
            char c_t = i_t >= 0 ? t[i_t] : '*';
            if (c_s == '#') {
                skip_s++;
                i_s--;
            } else if (c_t == '#') {
                skip_t++;
                i_t--;
            } else {  // Both are not '#'
                if (skip_s > 0) {
                    i_s--;
                    skip_s--;
                } else if (skip_t > 0) {
                    i_t--;
                    skip_t--;
                } else {
                    if (c_s != c_t) {
                        return false;
                    }
                    i_s--;
                    i_t--;
                }
            }
        }

        if (i_s > 0 || i_t > 0) {  // At least one character remaining
            return false;
        } else {
            return true;
        }
    }
};