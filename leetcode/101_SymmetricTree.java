package com.terrykwon;



public class SymmetricTree {
    private static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    public boolean isSymmetric(TreeNode root) {
        if (root == null) return true;

        TreeNode l = root.left;
        TreeNode r = root.right;

        return recursiveCheck(l, r);
    }

    private boolean recursiveCheck(TreeNode l, TreeNode r) {
        if (l == null && r == null) {
            return true;
        } else if (l == null || r == null) {
            return false;
        }

        if (l.val != r.val) {
            return false;
        }

        return recursiveCheck(l.left, r.right) && recursiveCheck(l.right, r.left);
    }
}
