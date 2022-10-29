#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int M[100005];       
    int INF = 100005;

    int coinChange(vector<int>& coins, int amount) {
        M[0] = 0;
        for (int i = 1; i <= amount; i++) {
            M[i] = INF;

            for (int c : coins) {
                if (i - c >= 0) {
                    M[i] = min(M[i], M[i-c] + 1);
                }
            } 
        }

        if (M[amount] == INF) {
            return -1;
        } else {
            return M[amount];
        }
    }
};