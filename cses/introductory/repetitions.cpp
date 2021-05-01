#include <iostream>
using namespace std;


int main() {
    string s;
    cin >> s;

    int max = 0;
    int streak = 0;
    char prev = s[0];

    for (char c : s) {
        if (c == prev) {
            streak += 1;
        } else {
            prev = c;
            streak = 1;
        }
        if (streak > max) {
            max = streak;
        }
    }
    cout << max << endl;
}