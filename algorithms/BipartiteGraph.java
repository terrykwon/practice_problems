package com.terrykwon;

import java.util.LinkedList;
import java.util.Queue;

public class BipartiteGraph {

    public boolean isBipartite(int[][] graph) {
        boolean[] visited = new boolean[graph.length];
        boolean[] team = new boolean[graph.length]; // Team true and false

        Queue<Integer> q = new LinkedList<>();

        for (int i = 0; i < graph.length; i++) {
            if (!visited[i]) {
                // Perform BFS
                visited[i] = true;
                q.add(i);
                team[i] = true; // arbitrary
                while (!q.isEmpty()) {
                    int u = q.remove();
                    boolean current = team[u];
                    for (int v : graph[u]) {
                        if (!visited[v]) {
                            visited[v] = true;
                            team[v] = !current;
                            q.add(v);
                        } else { // v has been visited. It must be the opposite color of current.
                            if (team[v] == current) {
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }

}
