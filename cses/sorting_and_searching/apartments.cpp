#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Greedy solution: give each apartment to the smallest possible person.
 * Identical problem to overlapping intervals.
 */
int main() {
    int n, m, k;
    cin >> n >> m >> k;    

    vector<int> desired;
    vector<int> actual;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        desired.push_back(x);
    }

    for (int j = 0; j < m; j++) {
        int x;
        cin >> x;
        actual.push_back(x);
    }

    sort(desired.begin(), desired.end());
    sort(actual.begin(), actual.end());

    size_t d = 0;  // using int would produce warning since v.size() is unsigned
    size_t a = 0;
    int count = 0;

    while (d < desired.size() && a < actual.size()) {
        int current_apartment = actual[a];
        int desired_mean = desired[d];
        
        if (desired_mean - k <= current_apartment 
                && current_apartment <= desired_mean + k) {
            count++;
            d++;
            a++;
        } else if (current_apartment < desired_mean - k) {
            a++; 
        } else {  // current_apartment > desired_mean + k
            d++;
        }
    }

    cout << count << endl;
}
