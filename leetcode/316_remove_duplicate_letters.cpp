#include <string>;
using namespace std;

// remove duplicate characters such that the result is the SMALLEST possible
// in lexicographic order!!
class Solution {
public:
    string removeDuplicateLetters(string s) {
        string result;
        sort(s.begin(), s.end());
        result.push_back(s[0]);

        for (char c : s) {
            if (c != result.back()) {
                result.push_back(c);
            }
        }
    }
};