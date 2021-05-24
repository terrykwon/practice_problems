#include <iostream>
#include <string>
using namespace std;


const int MOD = 1'000'000'007;

void test_case() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    string s_prime = s.substr(0, (n+1)/2);
    int n_prime = s_prime.size();

    // now find the number of possible strings smaller than s_prime
    // using the first K letters of the alphabet

    long long total = 0;
    for (char c : s_prime) {
        total *= k;
        total += c - 'a';
        total %= MOD;
    }

    // edge case: when largest_prefix = s_prime
    bool suffix_larger = false;
    for (int i = 0; i < n - n_prime; i++) {
        if (s[n-n_prime-1-i] < s[n_prime+i]) {
            suffix_larger = true;
            break;
        } else if (s[n-n_prime-1-i] > s[n_prime+i]) {
            break;
        } else {
            continue;
        }
    }

    total = (total + suffix_larger) % MOD;
    cout << total << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        test_case();
    }
}