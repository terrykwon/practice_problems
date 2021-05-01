#include <iostream>
using namespace std;


void test_case(int t) {
    int X, Y;
    string S;
    cin >> X >> Y >> S;

    int M[1000][2];
    int MAX = 1000 * 101;

    // Initialize first
    if (S[0] == 'C') {
        M[0][0] = 0;
        M[0][1] = MAX;
    } else if (S[0] == 'J') {
        M[0][0] = MAX;
        M[0][1] = 0;
    } else { // '?'
        M[0][0] = 0;
        M[0][1] = 0;
    }
    
    for (int i = 1; i < S.length(); i++) {
        if (S[i] == 'C') {
            M[i][0] = min(M[i-1][0], M[i-1][1]+Y); // CC vs. JC
            M[i][1] = MAX;
        } else if (S[i] == 'J') {
            M[i][0] = MAX;
            M[i][1] = min(M[i-1][1], M[i-1][0]+X); // JJ vs. CJ
        } else { // '?'
            M[i][0] = min(M[i-1][0], M[i-1][1]+Y); // CC vs. JC
            M[i][1] = min(M[i-1][1], M[i-1][0]+X); // JJ vs. CJ
        }
    }

    int min_score = min(M[S.length()-1][0], M[S.length()-1][1]);

    cout << "Case #" << t << ": " << min_score << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        test_case(t);
    }
}