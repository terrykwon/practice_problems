package com.terrykwon;

import java.util.ArrayList;
import java.util.List;

/**
 * Find all paths from s to t.
 */
public class PathFinding {

    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        return allPaths(graph, 0, graph.length-1);
    }

    private List<List<Integer>> allPaths(int[][] g, int s, int t) {
        boolean[] visited = new boolean[g.length];
        List<List<Integer>> paths = new ArrayList<>();

        List<Integer> path = new ArrayList<>();

        dfs(g, visited, s, t, path, paths);

        return paths;
    }

    private void dfs(int[][] g, boolean[] visited, int u, int t,
                            List<Integer> path, List<List<Integer>> paths) {
        path.add(u); // Since assured that u hasn't been visited previously
        visited[u] = true;

        if (u == t) {
            paths.add(new ArrayList<>(path)); // Make a copy and append to results
            return;
        }

        for (int v : g[u]) {
            dfs(g, visited, v, t, path, paths);
            path.remove(path.size()-1); // Backtrack
        }
    }

}
