#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    multiset<int> towers;
    for (int a : arr) {
        // Using lower_bound(towers.begin(), towers.end(), a+1) causes TLE!!!
        // Why?? Because multiset uses *bidirectional iterators*! Using 
        // std::lower_bound will cause O(N) search (since it is meant for
        // random access iterators).
        auto it = towers.lower_bound(a+1);
        if (it != towers.end()) {
            towers.erase(it);
        }
        towers.insert(a);
    }
    cout << towers.size() << endl;
}