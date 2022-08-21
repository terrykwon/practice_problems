#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        map<char, int> m;
        for (char c : s) {
            m[c]++;  // operator [] will construct a new element if 
                     // it doesn't exist. int will default to 0 as per 
                     // 'value initialization'.
        }
        for (char c : t) {
            if (m[c] == 0) {
                return false;
            }
            m[c]--;
        }
        return true;
    }
};

int main() {
    
}