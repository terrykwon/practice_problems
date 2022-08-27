#include <iostream>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> m;
        for (char c : magazine) {
            m[c]++;  // operator [] will construct a new element if 
                     // it doesn't exist. int will default to 0 as per 
                     // 'value initialization'.
        }
        for (char c : ransomNote) {
            if (m[c] == 0) {
                return false;
            }
            m[c]--;
        }
        return true;       
    }
};
