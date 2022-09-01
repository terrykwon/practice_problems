#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = ""; 

        // We can bound the number of positions searched by the length of
        // strs[0] because no common prefix can be longer than that.
        for (int i = 0; i < strs[0].size(); i++) {
            char first = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].size()) {
                    return prefix;
                } 
                char current = strs[j][i]; 
                if (first != current) {
                    return prefix;
                }
            }
            prefix.push_back(first);
        }
        return prefix;  
    }
};