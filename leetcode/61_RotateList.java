package com.terrykwon;

public class RotateList {

    private class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }

    private ListNode rotateRight(ListNode head, int k) {
        int c = 1;
        ListNode n = head;
        while (n.next != null) {
            n = n.next;
            c++;
        }

        k = k % c;

        ListNode m = head;
        for (int i = 0; i < c - k - 1; i++) {
            m = m.next;
        }

        ListNode newHead = m.next;
        m.next = null;
        n.next = head;

        return newHead;
    }
}
