#include <iostream>
#include <string>
using namespace std;


// string s;

/**
 * Given a string of concatenated digits 1234567891011..., find the digit
 * at position k. 
 */ 
int query(long long k) {
    long long range = 9;
    long long digits = 1;  // to prevent int casts

    long long traversed = 0;

    while (k > digits * range) {
        k -= digits * range;
        traversed += range;

        digits += 1;
        range *= 10;

        // cout << "traversed: " << traversed << " range: " << range << endl;
    }

    long long number = traversed + (k+digits-1) / digits;  // equivalent to ceil
    int position = (k+digits-1) % digits;  // 0 = leftmost

    // cout << "number: " << number << " position: " << position << endl;

    return to_string(number)[position] - '0';
}


int main() {
    int q;
    cin >> q;

    // for (int i = 1; i < 100; i++) {
    //     string digits = to_string(i);
    //     for (int j = 0; j < digits.length(); j++) {
    //         s.push_back(digits[j]);
    //     }
    // }
    // cout << s << endl;

    long long k;
    for (int i = 0; i < q; i++) {
        cin >> k; 
        cout << query(k) << endl;
    }    
} 