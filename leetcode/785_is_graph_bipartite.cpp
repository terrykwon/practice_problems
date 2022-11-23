#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int color[100] = {0};  // Colors are {-1, 1}. 0 for unitialized.
        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (color[i] != 0) {
                continue;
            }
            color[i] = 1;  // Color, then push
            q.push(i);
            while (!q.empty()) {
                int x = q.front();
                q.pop();
                for (int y : graph[x]) {
                    if (color[y] == 0) {
                        color[y] = -color[x];
                        q.push(y);
                    } else if (color[y] == color[x]) {  
                        // If y is already colored, and it has the same color as
                        // x, then the graph is not bipartite.
                        return false;
                    }
                }
            }
        }

        return true;       
    }
};