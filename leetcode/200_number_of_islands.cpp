#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>> &grid, int i, int j, int m, int n) {
        if (grid[i][j] == '0') {
            return;
        }

        grid[i][j] = '0';

        pair<int, int> directions[] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        for (auto &d : directions) {
            int i_next = i + d.first;
            int j_next = j + d.second;

            if (i_next >= 0 && i_next < m && j_next >= 0 && j_next < n) {
                dfs(grid, i_next, j_next, m, n);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j, m, n);
                    count++;
                }
            }
        }
        return count;
    }
};