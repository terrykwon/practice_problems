#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int n = max(a.length(), b.length());        
        // Pad zeros; although insert front is inefficient.
        while (a.length() < n) {
            a.insert(0, 1, '0');
        }
        while (b.length() < n) {
            b.insert(0, 1, '0');
        }
        string result;

        int carry = 0;
        for (int i = n-1; i >= 0; i--) {
            int x = a[i] - '0';
            int y = b[i] - '0';

            int current_result = x + y + carry; 
            if (current_result >= 2) {
                current_result = current_result - 2;
                carry = 1;
            } else {
                carry = 0;
            }

            cout << current_result << endl;

            result.push_back(current_result + '0');
        }
        if (carry == 1) {
            result.push_back('1');
        }
        reverse(result.begin(), result.end());  // std
        return result;
    }
};

int main() {
    Solution s;
    string a = "100011";
    string b = "11";

    cout << s.addBinary(a, b) << endl;
    cout << a[4] << endl;
}