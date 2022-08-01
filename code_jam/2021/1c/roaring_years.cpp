#include <iostream>
#include <string>
using namespace std;


// TODO


void test_case() {
    string year;
    cin >> year; 

    if (year.length() == 1) {
        cout << 12 << endl;
        return;
    }

    long long minimum = (long long)1e18 + 5;

    for (int i = 1; i <= year.length() / 2; i++) {
        for (int x = 0; x <= 1; x++) {
            string candidate;
            long long component = stoll(year.substr(0, i)); 
            component += x;

            while (candidate.length() < year.length()) {
                candidate += to_string(component);
                component += 1;
            }

            // cout << candidate << " ";
            if (stoll(candidate) > stoll(year) && stoll(candidate) < minimum) {
                minimum = stoll(candidate);
            }
        }
    }

    cout << minimum << endl;
}


int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        test_case();
    }
}