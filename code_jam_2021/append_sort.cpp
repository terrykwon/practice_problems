/**
 * Not solved yet! 
 */ 
#include <iostream>
#include <string>
using namespace std;

// Is a a prefix of b?
bool is_prefix(string a, string b) {
    if (a.length() > b.length()) {
        return false;
    }
    return a == b.substr(0, a.length());
}


// Guaranteed not to be 9, 99, 999, etc.
string add_one(string num) {
    string result = "";
    int carry = 1;

    for (int j = num.length()-1; j >= 0; j--) {
        int digit = num[j] - '0' + carry;
        if (digit == 10) {
            carry = 1;
            digit = 0;
        } else {
            carry = 0;
        }
        result.insert(0, 1, char(digit + '0')); 
    }
    return result;
}


void test_case() {
    int n;
    cin >> n;

    string prev, curr;
    cin >> prev;

    int count = 0;

    // cout << " " << prev << " ";

    for (int i = 1; i < n; i++) {
        cin >> curr;

        // already sorted
        if (prev.length() < curr.length()) {
            prev = curr;
            // cout << " " << prev << " ";
            continue;
        } 

        int k = prev.length() - curr.length();  // 0, 1, 2, ...
        
        if (is_prefix(curr, prev)) {
            // they may be equal
            if (curr == prev) {
                curr.push_back('0');
                count += 1;
                prev = curr;
                // cout << " " << prev << " ";
                continue;
            }

            // prev = curr + 1, unless the following digits of prev are all 9's,
            // in which case just k+1 0's are added.
            
            // check if following digits are all 9's
            bool all_nines = true;
            for (int j = prev.length()-1; j >= prev.length()-k; j--) {
                if (prev[j] != '9') {
                    all_nines = false;
                    break;
                }
            }

            if (all_nines) {
                // add (k+1) 0's
                for (int j = 0; j < k+1; j++) {
                    curr.push_back('0');
                }
                count += k+1;
            } else {
                // add 1
                curr = add_one(prev);
                count += k;
            }
        } else {
            // Cases: if curr is smaller than the len(curr) first digits of
            // prev, or larger (can't be equal since checked at is_prefix).
            bool curr_smaller = true;
            for (int j = 0; j < curr.length(); j++) {
                if (prev[j] == curr[j]) {
                    continue;
                }
                if (prev[j] > curr[j]) {
                    curr_smaller = true;
                    break;
                } else {
                    curr_smaller = false;
                    break;
                }
            }

            if (curr_smaller) {
                // add (k+1) 0's
                for (int j = 0; j < k+1; j++) {
                    curr.push_back('0');
                }
                count += k+1;
            } else {
                // add k 0's
                for (int j = 0; j < k; j++) {
                    curr.push_back('0');
                }
                count += k;
            }
        }
        
        prev = curr;
        // cout << prev << " ";
    }
    cout << count << endl;
}

int main() {
    // cout << is_prefix("hello", "hello_world") << endl;
    // cout << is_prefix("hello", "helli_world") << endl;
    // cout << is_prefix("1", "189") << endl;
    // cout << add_one("109") << endl;
    // cout << add_one("189") << endl;
    // cout << add_one("9999999") << endl;

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        test_case();
    }
}