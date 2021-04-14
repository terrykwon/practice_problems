#include <iostream>
#include <algorithm>
using namespace std;


void test_case(int t) {
    int N;
    cin >> N;
    int L[N];

    for (int i = 0; i < N; i++) {
        cin >> L[i];
    }

    int score = 0;

    for (int i = 0; i < N-1; i++) {
        int j = i; // min index 
        for (int k = i+1; k < N; k++) {
            if (L[k] < L[j]) {
                j = k;
            }
        }
        score += j - i + 1;
        reverse(L + i, L + j + 1);
        // cout << L[i];  // debug
    }

    cout << "Case #" << t << ": " << score << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        test_case(t);
    }
}