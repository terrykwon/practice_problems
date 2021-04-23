#include <iostream>
using namespace std;


int main() {
    int n;
    cin >> n;

    long long prev;
    cin >> prev;

    long long curr;
    long long count = 0;

    for (int i = 1; i < n; i++) {
        cin >> curr;
        if (curr < prev) {
            count += prev - curr;
            curr = prev;
        }
        prev = curr;
    }
    cout << count << endl;
}