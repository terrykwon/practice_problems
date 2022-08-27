#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> m;       
        int length = 0;
        for (char c : s) {
            m[c]++;
            if (m[c] == 2) {
                length += 2;
                m[c] = 0;
            }
        }
        for (auto const& [key, val] : m) {
            if (val > 0) {
                return length + 1;
            }
        }
        return length;
    }
};