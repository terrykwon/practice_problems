#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool dfs(vector<int> adj[], int visited[], int u) {
        if (visited[u] == 1) {  // Encountered twice in this DFS path
            return false;
        } else if (visited[u] == 2) {  // We know that path forward terminates
            return true;
        }

        visited[u] = 1;
        for (int v : adj[u]) {
            bool acyclic = dfs(adj, visited, v);
            if (!acyclic) {
                return false;
            }
        }
        visited[u] = 2;

        return true;
    }

    /**
     * Cycle detection
     *  
     * @param numCourses: [1, 2000]
     * @param prerequisites: [0, 5000]
     */
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        int visited[numCourses];  // 0: unvisited, 1: entered, 2: left

        // IMPORTANT: variable-length array is filled with garbage.
        memset(visited, 0, sizeof(visited));  

        // To adjacency list
        for (auto &edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);  // Second has dependency to first
        }

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                bool acyclic = dfs(adj, visited, i);
                if (!acyclic) {
                    return false;
                } 
            }
        }
        return true;
    }
};
