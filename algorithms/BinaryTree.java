package com.terrykwon;

class BinaryTree<E> {
    private Node<E> root;

    private BinaryTree() {
    }

    private void preorderPrint() {
        preorderPrintSub(root);
        System.out.println();
    }

    private void preorderPrintSub(Node<E> n) {
        if (n == null) return;

        System.out.print(" " + n.value +" ");
        preorderPrintSub(n.left);
        preorderPrintSub(n.right);
    }

    private void inorderPrint() {
        inorderPrintSub(root);
        System.out.println();
    }

    private void inorderPrintSub(Node<E> n) {
        if (n == null) return;

        inorderPrintSub(n.left);
        System.out.print(" " + n.value + " ");
        inorderPrintSub(n.right);
    }

    private void postorderPrint() {
        postorderPrintSub(root);
        System.out.println();
    }

    private void postorderPrintSub(Node<E> n) {
        if (n == null) return;
        postorderPrintSub(n.left);
        postorderPrintSub(n.right);
        System.out.print(" " + n.value +" ");
    }

    private static class Node<E> {
        Node<E> left;
        Node<E> right;
        E value;

        Node(E value) {
            left = null;
            right = null;
            this.value = value;
        }

        Node(Node<E> left, E value, Node<E> right) {
            this(value);
            this.left = left;
            this.right = right;
        }
    }

//    private class TreeTester {
//        TreeTester() {
//
//        }
//
//
//    }

    public static void main(String[] args) {
        BinaryTree<Integer> b1 = new BinaryTree<>();
        b1.root = new Node<>(1);
        b1.root.left= new Node<>(2);
        b1.root.right = new Node<>(3);
        b1.root.left.left = new Node<>(4);
        b1.root.left.right = new Node<>(5);
        b1.root.right.left = new Node<>(6);
        b1.root.right.right = new Node<>(7);

        b1.preorderPrint();
        b1.inorderPrint();
        b1.postorderPrint();
    }
}
