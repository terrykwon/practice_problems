#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    /**
     * Classic "fire spread" starting from k nodes problem.
     */
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i,j});
                }
            }
        }

        pair<int, int> directions[4] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        int depth;
        if (q.empty()) {  // Bit unclean... case where all 0s vs. isolated 2
            depth = 0;
        } else {
            depth = -1;
        }
        
        while (!q.empty()) {
            depth++;

            int level = q.size();
            for (int k = 0; k < level; k++) {
                auto[i, j] = q.front();  // C++17 multiple assignment
                q.pop();
                
                cout << i << "," << j << "    ";

                for (auto &d : directions) {
                    int i_next = i + d.first;
                    int j_next = j + d.second;
                    
                    if (i_next < 0 || i_next >= m 
                            || j_next < 0 || j_next >= n) {
                        continue;
                    }

                    if (grid[i_next][j_next] == 1) {
                        grid[i_next][j_next] = 2;
                        q.push({i_next, j_next});
                    }
                }
            }
            cout << endl;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return depth;
    }
};