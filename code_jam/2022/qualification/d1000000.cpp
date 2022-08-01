#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

void test_case(int t) {
    int N;
    vector<int> d;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        d.push_back(x);
    }
    
    int m = 1; 
    sort(d.begin(), d.end());
    for (int i = 0; i < d.size(); i++) {
        if (d[i] >= m) {
            m++;
        }
    }

    cout << "Case #" << t << ": " << m-1 << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        test_case(t);
    }
}