#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Maximum difference between a left-minimum and right-maximum.
        int n = prices.size();
        int l = 0;
        int r = 1;
        int max_profit = 0;
        while (r < n) {
            int profit = prices[r] - prices[l];
            if (profit <= 0) {
                l = r;  // Since p[r] is smaller than [l]
                r++;
                continue;
            }
            if (profit > max_profit) {
                max_profit = profit;
            }
            r++;
        }
        return max_profit;
    }
};

int main() {
    
}