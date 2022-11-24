#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * s = 0, t = n-1
     */
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size(); 

        vector<vector<int>> paths;
        vector<int> current_path = {0};

        dfs(graph, n, 0, current_path, paths);
        
        return paths;
    }

    void dfs(vector<vector<int>>& graph, int n, int u, 
            vector<int>& current_path,
            vector<vector<int>>& paths) {
        if (u == n-1) {
            paths.push_back(current_path);
        } else {
            for (int v: graph[u]) {
                current_path.push_back(v);
                dfs(graph, n, v, current_path, paths);
                current_path.pop_back();
            }
        }

    }
};