package com.terrykwon;

import java.util.Arrays;

/**
 * Given a list of cities and their prices, determine the min cost set of
 * cities to sleep in, subject to the maximum distance constraint of D.
 */
public class BestSchedule {
    private static int c = 0;

    public static void main(String[] args) {
        // 10 cities
        int D1 = 15;
        int[] p1 = {0, 5, 21, 3, 2, 16, -8, 20, 3, 0}; // n elements
        int[] d1 = {0, 2, 5, 2, 3, 5, 14, 5, 9, 5}; // n elements

        c = 0;
        System.out.println(minCost1(0, p1.length-1, p1, d1, D1));
        System.out.println("calls: " + c + "\n");

        c = 0;
        System.out.println(minCost2(p1.length-1, p1, d1, D1));
        System.out.println("calls: " + c + "\n");

        c = 0;
        System.out.println(minCost3(p1.length-1, p1, d1, D1));
        System.out.println("calls: " + c + "\n");

        System.out.println(minCost4(p1.length-1, p1, d1, D1));
    }

    /**
     * Very inefficient. Considers n-1 possible "optimal" stopping points, then recurses into those subintervals.
     * [s, t]
     */
    private static int minCost1(int s, int t, int[] p, int[] d, int D) {
        c += 1;
        int sol = Integer.MAX_VALUE; // Assume to be infinity

        int summedD = Arrays.stream(d, s+1, t+1).sum(); // command-P to view parameters
        if (summedD <= D) {
            sol = p[t]; // Can't return here because of case where negative prices might exist
        }

        for (int i = s+1; i <= t-1; i++) {
            int subsol1 = minCost1(s, i, p, d, D);
            int subsol2 = minCost1(i, t, p, d, D);
            sol = Math.min(sol, subsol1+subsol2);
        }

//        System.out.println(String.format("[%d, %d): summedD: %d sol: %d", s, t, summedD, sol));

        return sol;
    }

    /**
     * Considers all possible optimal last stopping points.
     *
     * n is the index of the last stopping point.
     */
    private static int minCost2(int n, int[] p, int[] d, int D) {
        c += 1;
        if (n == 0) return 0; // If the current stop is the true optimal.

        int sol = Integer.MAX_VALUE;

        for (int i = 0; i <= n-1; i++) {
            int summedD = Arrays.stream(d, i+1, n+1).sum();
            if (summedD <= D) {
                sol = Math.min(sol, p[n] +  minCost2(i, p, d, D));
            }
        }

        return sol;
    }

    /**
     * Same as 2, but memoized to reduce recursive calls.
     *
     * O(n^3)
     */
    private static int[] M1 = new int[100]; // Memoization table
    private static int minCost3(int n, int[] p, int[] d, int D) {
        c += 1;

        if (n == 0) return 0;

        if (M1[n] != 0) {
//            System.out.println("hit! " + n);
            return M1[n];
        }

        int sol = Integer.MAX_VALUE;

        for (int i = n-1; i >= 0; i--) { // n times
//        for (int i = 0; i <= n-1; i++) {
            int summedD = Arrays.stream(d, i+1, n+1).sum(); // n times
            if (summedD <= D) {
                sol = Math.min(sol, p[n] +  minCost3(i, p, d, D)); // n times
            }
        }

        M1[n] = sol;
        return sol;
    }

    /**
     * Iterative solution with memoization.
     *
     * O(n^2)
     */
    private static int[] M2 = new int[100];
    private static int minCost4(int n, int[] p, int[] d, int D) {
        M2[0] = 0;

        for (int i = 1; i <= n; i++) {
            // Prevent unnecessary repeated computations:
            // (1) distance summations: do backwards while maintaining d_j+1
            // (2) minimum tracking: don't iterate whole set of valid j's to find minimum--
            //     the minimum is min(current_min, M2[j-1])
            int minForValidJ = Integer.MAX_VALUE;
            int distToJ = d[i]; // Distance between i and j
//            for (int j = 0; j <= i-1; j++) {
            for (int j = i-1; j >= 0 && distToJ <= D; j--) {
//                int distToJ = 0;
//                for (int k = j+1; k <=i; k++) {
//                    distToJ += d[k];
//                }
                distToJ += d[j];

//                if (distToJ <= D) {
//                    if (M2[j] < minForValidJ) minForValidJ = M2[j];
//                }
                if (M2[j] < minForValidJ) minForValidJ = M2[j];
            }
            M2[i] = minForValidJ + p[i];
        }

        return M2[n];
    }



}
