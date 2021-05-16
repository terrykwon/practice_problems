#include <iostream>
#include <map>
using namespace std;

/**
 * Find the length of the longest contiguous subsequence with no duplicate
 * elements.
 * 
 * This solution calculates the longest possible length ending at index i 
 * in a single pass (with log(N) lookups). The thing to note here is that
 * subsequence from arr[i-1] ... arr[i-1 - length] is guaranteed to contain
 * unique values.
 */ 
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    map<int, int> last_seen;
    int longest_interval = 0;
    int current_interval = 0;  // longest nonduplicate sequence ending at i

    for (int i = 0; i < n; i++) {
        int current = arr[i];
        map<int, int>::iterator it = last_seen.find(current);
        if (it != last_seen.end()) {
            int last_seen_index = it->second;
            current_interval = min(i-last_seen_index, current_interval+1);
        } else {
            current_interval++;
        }

        if (current_interval > longest_interval) {
            longest_interval = current_interval;
        }

        last_seen[current] = i;
    }
    cout << longest_interval << endl;
}