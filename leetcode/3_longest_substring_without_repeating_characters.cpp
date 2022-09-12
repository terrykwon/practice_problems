#include <iostream>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> last_instances;  // (char, last_instance)
        int current_length = 0;
        int longest_length = 0;
        int current_start = 0;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (last_instances.find(c) != last_instances.end()) {  // contains
                int last_instance = last_instances[c];
                if (last_instance >= current_start) {
                    // s[i] exists somewhere between current_start and i-1
                    // so update the beginning of the substring to the very
                    // next position.
                    current_start = last_instance + 1; 
                }
            } 
            last_instances[c] = i;
            current_length = i - current_start + 1; 
            if (current_length > longest_length) {
                longest_length = current_length;
            }
        }
        return longest_length;
    }
};