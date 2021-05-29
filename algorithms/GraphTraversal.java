package com.terrykwon;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;

public class GraphTraversal {

    public static void main(String[] args) {
        List<Integer>[] adj = new ArrayList[7];
        for (int i = 0; i < 7; i++) {
            adj[i] = new ArrayList<>();
        }
        adj[0].add(1);
        adj[1].add(2);
        adj[1].add(3);
        adj[2].add(3);
        adj[3].add(4);
        dfs(adj);

        detectCycles(adj);
    }

    /**
     * Detect cycles in a directed graph.
     */
    private static boolean detectCycles(List<Integer>[] adj) {
        boolean[] visited = new boolean[adj.length];
        boolean[] path = new boolean[adj.length];

        for (int i = 0; i < adj.length; i++) {
            if (!visited[i] && detectCyclesRecurse(adj, i, visited, path)) {
                System.out.println("Cycle found!");
                return true;
            }
        }
        System.out.println("Cycle not found!");
        return false;
    }

    private static boolean detectCyclesRecurse(List<Integer>[] adj, int u, boolean[] visited, boolean[] path) {
        visited[u] = true;
        path[u] = true;
        for (int v : adj[u]) {
            if (path[v]) {
                return true;
            }
            if (!visited[v]) {
                if (detectCyclesRecurse(adj, v, visited, path)) {
                    return true;
                }
            }
            path[u] = false; // Backtrack
        }
        return false;
    }

    private static void dfs(List<Integer>[] adj) {
        boolean[] visited = new boolean[adj.length];
        for (int i = 0; i < adj.length; i++) {
            if (!visited[i]) {
                dfsRecurse(adj, i, visited);
            }
        }
    }

    private static void dfsRecurse(List<Integer>[] adj, int s, boolean[] visited) {
        System.out.println("Visiting " + s);
        visited[s] = true;
        for (int v : adj[s]) {
            if (!visited[v]) {
                dfsRecurse(adj, v, visited);
            }
        }
    }


    /**
     * BFS starting at source s, with a total of n nodes.
     */
    private static void bfs(List<Integer>[] adj, int s, int n) {
        Queue<Integer> q = new ArrayDeque<>();
        boolean[] visited = new boolean[n];

        q.add(s);

        while (!q.isEmpty()) {
            int current = q.remove();
            visited[current] = true;
            for (int neighbor: adj[current]) {
                if (!visited[neighbor]) q.add(neighbor);
            }
        }
    }
}
