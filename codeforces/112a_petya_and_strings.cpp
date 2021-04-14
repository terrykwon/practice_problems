#include <iostream>
using namespace std;

int main() {
    string a, b;
    char a_i, b_i;

    cin >> a >> b;

    for (int i = 0; i < a.length(); i++) {
        a_i = tolower(a[i]);
        b_i = tolower(b[i]);
        if (a_i == b_i) {
            continue;
        } else if (a_i < b_i) {
            cout << -1 << endl;
            return 0;
        } else {
            cout << 1 << endl;
            return 0;
        }
    }
    cout << 0 << endl;
}