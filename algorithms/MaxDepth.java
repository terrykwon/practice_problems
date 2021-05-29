package com.terrykwon;

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Stack;

public class MaxDepth {
    public class TreeNode {
         int val;
         TreeNode left;
         TreeNode right;
         TreeNode(int x) { val = x; }
    }

    /**
     * Find the maximum depth of a binary tree.
     * BFS while keeping track of the level.
     */
    public int maxDepth(TreeNode root) {
        if (root == null) return 0;

        Deque<TreeNode> q = new ArrayDeque<>();

        int depth = 0;
        q.add(root);

        while (!q.isEmpty()) {
            int nodesInLevel = q.size();
            for (int i = 0; i < nodesInLevel; i++) {
                TreeNode n = q.removeFirst();

                if (n.left != null) {
                    q.add(n.left);
                }

                if (n.right != null) {
                    q.add(n.right);
                }
            }
            depth += 1;
        }

        return depth;
    }
}
