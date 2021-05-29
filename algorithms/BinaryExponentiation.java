package com.terrykwon;

public class BinaryExponentiation {
    public static void main(String[] args) {
        System.out.println(binPowRecursive(2, 4));
        System.out.println(binPow(2, 8));
    }

    /**
     * Computes a^n in O(logN) time.
     * Uses recursion of dividing n by half, then squaring.
     */
    private static long binPowRecursive(long a, long n) {
        if (n == 0) return 1;
        long res = binPowRecursive(a, n/2);
        if (n % 2 == 0) return res * res;
        else return res * res * a;
    }

    /**
     * Different to the recursive version.
     * This decomposes n to actual binary (1, 2, 4, ...) exponents
     */
    public static long binPow(long a, long n) {
        long res = 1;
        while (n > 0) {
            if ((n & 1) == 1) res = res * a;
            a = a * a;
            n = n >> 1;
        }
        return res;
    }
}
