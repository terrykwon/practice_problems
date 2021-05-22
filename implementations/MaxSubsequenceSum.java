package com.terrykwon;

/**
 * Given a list of numbers, find the maximum sum of a contiguous subsequence.
 *
 * Consider the empty list as a valid subsequence with sum 0.
 */
public class MaxSubsequenceSum {

    public static void main(String[] args) {
        int[] test1 = {1, 2, -5, 4, -2, 6, -4};
        int[] test2 = {};
        int[] test3 = {-1, -1, -1, -1, 3, 4, 5, 6};

        System.out.println(maxSubsequenceSum2(test1));
        System.out.println(maxSubsequenceSum8(test1));

        System.out.println(maxSubsequenceSum2(test2));
        System.out.println(maxSubsequenceSum8(test2));

        System.out.println(maxSubsequenceSum2(test3));
        System.out.println(maxSubsequenceSum8(test3));
    }

    /**
     * Time complexity: O(n^3)
     */
    public static int maxSubsequenceSum2(int[] arr) {
        int sol = 0;
        for (int i = 0; i < arr.length; i++) {
            for (int j = i; j < arr.length; j++) {
               int sum = 0;
               for (int k = i; k < j+1; k++) { // +1 since sum of a closed interval!!
                   sum = sum + arr[k];
               }
               if (sum > sol) {
                   sol = sum;
               }
            }
        }
        return sol;
    }

    /**
     * Doesn't sum from the first element on every iteration.
     *
     * Time complexity: O(n^2)
     */
    public static int maxSubsequenceSum3(int[] arr) {
        int sol = 0;
        for (int i = 0; i < arr.length; i++) {
            int sum = 0;
            for (int j = i; j < arr.length; j++) {
                sum = sum + arr[j];
                if (sum > sol) {
                    sol = sum;
                }
            }
        }
        return sol;
    }

    /**
     * A recursive approach similar to Merge Sort.
     *
     * Time complexity: O(n * log(n))
     */
    public static int maxSubsequenceSum5(int[] arr) {
        if (arr.length == 0) return 0;

        return max5(arr, 1, arr.length-1);
    }

    private static int max5(int[] arr, int s, int t) {
        // Terminating case
        if (s == t) {
            return Math.max(arr[s], 0);
        }

        int m = (s + t) / 2; // Equivalent to division, then flooring

        int solL = max5(arr, s, m);
        int solR = max5(arr, m+1, t);

        int subSolL = 0;
        int sumL = 0;
        for (int i = m; i > s-1; i--) { // (m-s)+1 iterations, since closed interval
            sumL = sumL + arr[i];
            if (sumL > subSolL) subSolL = sumL;
        }

        int subSolR = 0;
        int sumR = 0;
        for (int i = m+1; i < t+1; i++) {
            sumR = sumR + arr[i];
            if (sumR > subSolR) subSolR = sumR;
        }

        return Math.max(Math.max(solL, solR), subSolL+subSolR);
    }

    /**
     * Looping over all possible "boundaries".
     *
     * Time complexity: O(n^2)
     */
    public static int maxSubsequenceSum7(int[] arr) {
        int sol = 0;

        // All possible "boundaries"
        for (int m = 1; m < arr.length-1; m++) {
            int subSolL = 0;
            int sumL = 0;
            for (int i = m; i > 0-1; i--) {
                sumL = sumL + arr[i];
                if (sumL > subSolL) subSolL = sumL;
            }

            int subSolR = 0;
            int sumR = 0;
            for (int i = m+1; i < arr.length; i++) {
                sumR = sumR + arr[i];
                if (sumR > subSolR) subSolR = sumR;
            }

            if (subSolL + subSolR > sol) {
                sol = subSolL + subSolR;
            }
        }

        return sol;
    }

    /**
     * Finally! Linear-time algorithm.
     * Uses recurrence relation:
     *     subsolM = max(subsolM-1 + arr[m], 0)
     *
     * In other words, track sums while maintaining a lower bound of 0.
     *
     * Time-complexity: O(n)
     */
    public static int maxSubsequenceSum8(int[] arr) {
        int sol = 0;
        int subSol = 0;

        for (int i = 0; i < arr.length; i++) {
            subSol = Math.max(subSol + arr[i], 0);

            if (subSol > sol) sol = subSol;
        }

        return sol;
    }
}
