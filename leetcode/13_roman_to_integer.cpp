#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> M = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int result = 0;
        for (int i = 0; i < s.length()-1; i++) {
            int val_current = M[s[i]];
            int val_next = M[s[i+1]];
            if (val_current < val_next) {  // e.g.) IV
                result -= val_current;
            } else {
                result += val_current;
            }
        }
        result += M[s[s.length()-1]];
        return result;
    }
};