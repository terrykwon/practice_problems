#include <iostream>
#include <vector>
#include <deque>
using namespace std;


int main() {
    int n;
    cin >> n;    

    // vector<vector<int>> vv = generate(n);
    vector<deque<int>> codes;

    codes.push_back(deque<int>{0});
    codes.push_back(deque<int>{1});

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < (1<<i); j++) {
            codes[j].push_front(0);
        } 
        for (int j = (1<<i)-1; j >= 0; j--) {
            // prepend 1 to the codes of length(n-1), but in *reverse order*.
            deque<int> copied = codes[j];
            copied[0] = 1;
            codes.push_back(copied);
        }
    }

    for (auto v : codes) {
        for (auto i : v) {
            cout << i;
        }
        cout << endl;
    }
}