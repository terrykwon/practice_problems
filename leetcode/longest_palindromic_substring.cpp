#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * "Naive" O(n^2) solution by expanding around all possible centers.
 * 
 * d1 stores the max-length palindrome of odd length at position i. d2 does the
 * same for even-lengths.
 */ 
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<int> d1(n), d2(n);

        int max_length = 1;
        int max_index = 0;

        for (int i = 0; i < n; i++) {
            d1[i] = 1;
            while (0 <= i-d1[i] && i+d1[i] < n) {
                if (s[i - d1[i]] != s[i + d1[i]]) {
                    break;
                }
                d1[i]++;
                if (d1[i]*2-1 > max_length) {
                    max_length = d1[i]*2-1;
                    max_index = i;
                }
            }

            d2[i] = 0;
            while (0 <= i-d2[i] && i+d2[i]+1 < n) {
                if (s[i - d2[i]] != s[i + d2[i] + 1]) {
                    break;
                }
                d2[i]++;
                if (d2[i]*2 > max_length) {
                    max_length = d2[i]*2;
                    max_index = i;
                }
            }
        }

        if (max_length % 2 == 0) {
            return s.substr(max_index - (max_length/2)+1, max_length);
        } else {
            return s.substr(max_index - (max_length/2), max_length);
        }
    }
};

/**
 * TODO: Implement Manacher's algorithm
 */
class Solution2 {
public:
    string longestPalindrome(string s) {

    }
};

int main() {
    Solution s;

    string x1 = "abccbefceb";
    string x2 = "abccbeceb";
    string x3 = "a";
    string x4 = "aaaaa";
    string x5 = "aa";

    cout << s.longestPalindrome(x1) << endl;
    cout << s.longestPalindrome(x2) << endl;
    cout << s.longestPalindrome(x3) << endl;
    cout << s.longestPalindrome(x4) << endl;
    cout << s.longestPalindrome(x5) << endl;

}