#include <iostream>
#include <algorithm>
using namespace std;


void test_case(int t) {
    int R, C;
    cin >> R >> C;

    cout << "Case #" << t << ": " << endl;

    for (int i = 0; i < R*2+1; i++) {
        for (int j = 0; j < C*2+1; j++) {
            if (i < 2 && j < 2) {
                cout << ".";
                continue;
            }

            if (i % 2 == 0 && j % 2 ==0) {
                cout << "+";
            } else if (i % 2 == 0 && j % 2 == 1) {
                cout << "-";
            } else if (i % 2 ==1 && j % 2 == 0) {
                cout << "|";
            } else {
                cout << ".";
            }
        }
        cout << endl;
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        test_case(t);
    }
}