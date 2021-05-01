#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();

    int counts[26] { 0 };  // empty items are implicitly initialized to 0

    for (char c : s) {
        counts[c - 'A'] += 1;
    }

    int odd_count = 0;
    for (int i = 0; i < 26; i++) {
        if (counts[i] % 2 != 0) {
            odd_count += 1;
        }
        if (odd_count > 1) {
            cout << "NO SOLUTION" << endl;
            return 0;
        }
    }

    char palindrome[n+1];
    palindrome[n] = '\0';  // Will access invalid address without 
                           // null terminator!!

    int j = 0;
    for (int i = 0; i < 26; i++) {
        if (counts[i] % 2 != 0) {
            palindrome[n/2] = 'A' + i;
            counts[i] -= 1;
        } 
        while (counts[i]) {
            palindrome[j] = 'A' + i;
            palindrome[n-j-1] = 'A' + i;
            j += 1;
            counts[i] -= 2;
        }
    }

    cout << palindrome << endl;

}