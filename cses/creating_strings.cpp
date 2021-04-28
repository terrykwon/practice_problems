#include <iostream>
#include <string>
// #include <set>
#include <vector>
#include <algorithm>  // next_permutation
using namespace std;

/**
 * Permutations with duplicate elements. 
 */
int main() {
    string s;
    cin >> s;  

    // No need to use set because next_permutation doesn't overcount.
    // set<string> permutations;
    vector<string> permutations;

    // next_permutations returns the next LEXICOGRAPHICALLY GREATER
    // permutation!!! So to traverse them all, s must be sorted first.
    sort(s.begin(), s.end());
    do {
        // permutations.insert(s);
        permutations.push_back(s);
    } while (next_permutation(s.begin(), s.end()));

    cout << permutations.size() << endl;
    for (auto p : permutations) {
        cout << p << endl;
    }
}