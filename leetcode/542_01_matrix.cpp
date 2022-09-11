#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    /**
     * A simple BFS problem. The key is in ensuring that each depth is visited
     * only once. This is done through "blacking out" deeper layers, while
     * staring from depth 0.
     */
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();  // >= 1    
        int n = mat[0].size();  // >= 1

        const vector<pair<int, int>> DIRECTIONS = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        queue<pair<int, int>> q;

        vector<vector<int>> result(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    result[i][j] = 0;
                    q.push({i,j});
                } else {
                    result[i][j] = -1; // "black-out"
                }
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front();  // unpacking
            int current_distance = result[r][c];
            q.pop();
            for (auto d : DIRECTIONS) {
                int r_prime = r + d.first;
                int c_prime = c + d.second;

                if (r_prime >= 0 && r_prime < m && 
                        c_prime >= 0 && c_prime < n) {
                    if (result[r_prime][c_prime] == -1) {
                        result[r_prime][c_prime] = current_distance + 1; 
                        q.push({r_prime, c_prime});
                    }
                }
            }
        } 
        return result;
    }
};