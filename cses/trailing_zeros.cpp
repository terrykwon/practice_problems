#include <iostream>
#include <cmath>
using namespace std;

/**
 * Feels like there might be a closed form solution?
 */
int main() {
    long long n;
    cin >> n;

    long long zeros = 0;
    
    int exponent = 1;
    while (n >= pow(5, exponent)) {
        zeros += (n / (long long) pow(5, exponent));
        exponent += 1;
    }
    cout << zeros << endl;
}

// Counts the number of five factors for each term. 
// Too slow, didn't pass.
void attempt() {
    int n;
    cin >> n;

    long long total_fives = 0;

    long long current_fives;
    int current;

    for (int i = 1; i <= n; i++) {
        current_fives = 0;
        current = i;
        while (current % 5 == 0) {
            current /= 5;
            current_fives += 1;
        }
        total_fives += current_fives;
    }
    cout << total_fives << endl;
}