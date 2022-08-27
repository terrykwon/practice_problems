#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        for (char c: s) {
            if (stack.size() == 0 || c == '(' || c == '[' || c == '{') {
                stack.push_back(c);
                continue;
            }
            char top = stack.back(); 
            stack.pop_back(); 
            if (c == ')') {
                if (top != '(') return false;
            } else if (c == ']') {
                if (top != '[') return false;
            } else {
                if (top != '{') return false;
            }
        }
        return stack.size() == 0;
    }
};


int main() {
    Solution sol;
    string s = "()[]{}";
    cout << sol.isValid(s) << endl;
}