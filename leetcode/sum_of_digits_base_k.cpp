#include <iostream>
using namespace std;

class Solution {
public:
    int sumBase(int n, int k) {
        int sum = 0;
        while (n > 0) {
            sum += n % k;
            n /= k;
        }        
        return sum;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    Solution s;
    cout << s.sumBase(n, k) << endl;
}