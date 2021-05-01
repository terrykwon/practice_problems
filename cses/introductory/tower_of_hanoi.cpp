#include <iostream>
#include <vector>
using namespace std;

void print_vv(vector<vector<int>> vv) {
    cout << endl;
    for (auto v : vv) {
        cout << "X ";
        for (auto e : v) {
            cout << e << " ";
        }
        cout << endl;
    }
    cout << endl;
} 

// calls default constructor for three stacks
vector<vector<int>> stacks(3);

void move(int n, int source, int target) {
    if (n == 1) {
        int element = stacks[source].back();
        stacks[source].pop_back();
        stacks[target].push_back(element);
        cout << source+1 << " " << target+1 << endl;  // since 1-indexed
        // print_vv(stacks);
        return;
    } 

    int remaining = 3 - source - target;  // how clever :)

    move(n-1, source, remaining);
    move(1, source, target);
    move(n-1, remaining, target);
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        stacks[0].push_back(n-i-1);
    }

    cout << (1<<n) - 1 << endl;  // number of moves
    move(n, 0, 2);
}