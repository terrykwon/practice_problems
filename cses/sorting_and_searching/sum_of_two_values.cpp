#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

/**
 * Find two elements in the array that sum to X.
 * 
 * We only need to traverse once (while inserting into the hashmap)!
 * If (X-current) is not currently in the map, then later when we reach 
 * (X-current), current will be in the map.
 * 
 * `map` passes, but `unordered_map` produces TLE--why???
 */
int main() {
    long long n, x;
    cin >> n >> x;
    
    map<long long, int> lookup;

    for (int i = 0; i < n; i++) {
        long long num;
        cin >> num;

        long long looking_for = x - num;

        auto it = lookup.find(looking_for);
        if (it != lookup.end()) {
            cout << it->second + 1 << " " << i+1 << endl;
            return 0;
        } else {
            lookup[num] = i;
        }
    }

    cout << "IMPOSSIBLE" << endl;
}