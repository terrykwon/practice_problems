package com.terrykwon;

public class LongestNondecSubseq {
    private static int c = 0;

    public static void main(String[] args) {
        int[] s1 = new int[] {40, 41, 2, 41, 7, 8, 15, 1, 3}; // 4

        c = 0;
        System.out.println(String.format("%d : %d calls", alg1(s1), c));

//        System.out.println(alg2(s1, s1.length-1));
        alg2(s1, s1.length-1);
    }

    /**
     * Returns the length of the longest subsequence ending at i.
     */
    private static int alg1(int[] a) {
        return  alg1Sub(a, a.length-1, Integer.MAX_VALUE);
    }

    private static int alg1Sub(int[] a, int i, int m) {
        c += 1;

        if (i == 0) return 0;

        int sol1 = alg1Sub(a, i-1, m); // longest without adding i as the last number

        int sol2 = Integer.MIN_VALUE;
        if (a[i] <= m) { // It's possible to add a[i] to this subsequence, since it is still nondecreasing
            sol2 = 1 + alg1Sub(a, i-1, a[i]); // a[i] is the new maximum
        }

        return Math.max(sol1, sol2);
    }

    /**
     * Memoized solution: O(n^2)
     *
     * M stores the length of the LNS at i, with the last element being a_i.
     * Therefore, at iteration i+1, one merely needs to check the maximum of the previous subsolutions,
     * satisfying the condition that a_j <= a_i+1.
     *
     * k is the inclusive index.
     */
    private static int alg2(int[] a, int k) {
        int[] M = new int[100]; // Can be just the length of input + 1
        int[] prev = new int[100]; // Ditto

        M[0] = 1;

        for (int i = 1; i <= k; i++) {
            int maxSub = 0;
            int prevSub = -1;
            for (int j = 0; j <= i-1; j++) {
                if (a[j] <= a[i] && M[j] > maxSub) {
                    maxSub = M[j];
                    prevSub = j;
                }
            }
            M[i] = maxSub + 1;
            prev[i] = prevSub;
        }

        int max = 0;
        int last = 0;
        for (int m = 0; m <= k; m++) {
//            System.out.println(M[m]);
            if (M[m] > max) {
                max = M[m];
                last = m;
            }
        }

        while (last != -1) {
            System.out.print(" " + a[last] + " ");
            last = prev[last];
        }

        System.out.println("length: " + max);

        return max;
    }
}
