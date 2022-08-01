#include <iostream>
#include <set>
#include <vector>
using namespace std;

// is there a closed form solution?
// naive set removal: O(nlog(n))
int main() {
    int n;
    cin >> n;

    set<int> s;
    // vector<int> s;
    for (int i = 1; i <= n; i++) {
        s.insert(i);
    }

    set<int>::iterator it = s.begin();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 1; j++) {
            it++;  
            if (it == s.end()) {  // past-the-end
                it = s.begin();  // first element
            }
        }
        cout << *it << ' ';
        it = s.erase(it);
        if (it == s.end()) {
            it = s.begin();
        }
    }
    cout << endl;
}