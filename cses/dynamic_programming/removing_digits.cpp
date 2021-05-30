#include <iostream>
using namespace std;

/**
 * Decrease N down to 0 by subtracting from it one of its digits at each step.
 *
 * Although this is listed as a DP problem, a greedy solution of just
 * subtracting the largest digit at each step works.
 * 
 * Intuition: let N_1, N_2 such that N_1 < N_2. Then OPT(N_1) <= OPT(N_2).
 * Proof:
 * If N_2 > N_1 + 9, then this holds trivially since the max subtraction is 9.
 * If N_2 <= N_1 + 9, then think of these three cases:
 * 
 * a) N_1 = XXX1, N_2 = XXX9 (all digits except the last are identical)
 * b) N_1 = XX34, N_2 = XX43 (all digits except the last two are identical)
 * c) N_1 = 999X, N_2 = 1000Y (the second-to-last digit is a 9, in which case 
 *                             overflow happens)
 * 
 * In all three cases, the next number of N_2 cannot be less than the next
 * number of N_1.
 * 
 * Since this property holds, then it is always optimal to decrease N by the
 * maximum possible amount.
 */ 
int main() {
    int n;
    cin >> n;

    int steps = 0;

    while (n > 0) {
        // find max digit
        int max = 0;
        int div = 1;
        while (n / div > 0) {
            int d = (n / div) % 10;
            if (d > max) {
                max = d;
            }
            div *= 10;
        }

        n -= max;
        steps++;
    }

    cout << steps << endl;
}