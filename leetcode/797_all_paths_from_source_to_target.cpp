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

    int M[16] = {};
    /**
     * Variation: Just counting the number of paths.
     * Can be done in O(V+E). 
     */
    int countAllPaths(vector<vector<int>>& graph) {
        int n = graph.size();
        fill_n(M, 16, -1);  // Also acts as a visited array

        dfs2(graph, n, 0);

        return M[0];
    }
    
    void dfs2(vector<vector<int>>& graph, int n, int u) {
        cout << "dfs " << u << endl;
        if (u == n-1) {
            M[u] = 1;
            return;
        }

        if (M[u] == -1) {
            M[u] = 0;
            for (int v: graph[u]) {
                dfs2(graph, n, v);
                M[u] += M[v];
            }
        }
    }
};


int main() {
    Solution s;
    vector<vector<int>> graph = {
        {1,2,3},
        {4},
        {4},
        {4},
        {5,6,7},
        {8},
        {8},
        {8},
        {}
    };

    cout << s.countAllPaths(graph) << endl;
    return 0;
}