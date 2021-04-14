#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int i = 0;
    int kth, next;

    while (i < k) {
        cin >> kth;
        if (kth > 0) {
            i++;
        } else {
            cout << i << endl; // all zeros from hence on
            return 0;
        }
    }

    // Count number of identical elements
    while (i < n) {
        cin >> next; 
        if (kth == next) {
            i++;
        } else {
            break;
        }
    }
    cout << i << endl;

    return 0;
}