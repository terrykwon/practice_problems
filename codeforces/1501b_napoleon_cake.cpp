#include <iostream>
#include <vector>
using namespace std;


void test_case() {
    int n, a;
    cin >> n;

    vector<int> creams;
    vector<int> pancakes;
    for (int i = 0; i < n; i++) {
        cin >> a;
        creams.push_back(a);
    }

    int depth = creams[n-1];
    for (int j = n-1; j >= 0; j--) {
        depth = max(depth, creams[j]);
        if (depth >= 1) {
            pancakes.push_back(1);
        } else {
            pancakes.push_back(0);
        }
        depth--;
    }

    for (int k = n-1; k >=0; k--) {
        cout << pancakes[k] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        test_case();
    }    
}