#include <iostream>
#include <set>
using namespace std;

/**
 * If (x-1) was previously encountered, then we can always add x to that
 * sublist. 
 */ 
int main() {
    int n;
    cin >> n;
    int arr[n];    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    set<int> subsets;

    for (int a : arr) {
        set<int>::iterator tail = subsets.find(a-1);
        if (tail != subsets.end()) {
            subsets.insert(a);
            subsets.erase(tail);
        } else {
            subsets.insert(a);
        }
    }

    cout << subsets.size() << endl;
}