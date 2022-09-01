#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int MAX_LENGTH = 200;
        string prefix = ""; 

        for (int i = 0; i < MAX_LENGTH; i++) {
            if (i >= strs[0].size()) {
                return prefix;
            }
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