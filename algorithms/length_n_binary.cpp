#include <iostream>
#include <vector>
using namespace std;


void generate_recurse(vector<vector<int>>& all, vector<int>& current, int n) {
    if (current.size() == n) {
        all.push_back(current);
        return;
    }

    // This copies; assigning the same object would need pointers.
    vector<int> copy = current;
    current.push_back(0);
    copy.push_back(1);

    generate_recurse(all, current, n);
    generate_recurse(all, copy, n);
}

vector<vector<int>> generate(int n) {
    vector<vector<int>> all;
    vector<int> empty;

    generate_recurse(all, empty, n);

    return all;
}

int main() {
    int n;
    cin >> n;    

    vector<vector<int>> vv = generate(n);

    for (auto v : vv) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
}