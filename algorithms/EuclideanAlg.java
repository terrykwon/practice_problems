package com.terrykwon;

public class EuclideanAlg {
    public static void main(String[] args) {
        System.out.println(gcdRecursive(126, 36));
        System.out.println(gcd(126, 36));
        System.out.println(gcd(36, 126));
    }

    /**
     * Time complexity: O(log(min(a,b)))
     */
    public static int gcdRecursive(int a, int b) {
        if (b == 0) return a;
        return gcdRecursive(b, a % b);
    }

    public static int gcd(int a, int b) {
        while (b > 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    }

    public static int lcm(int a, int b) {
//        return a * b / gcd(a,b);
        // To avoid integer overflows:
        return a / gcd(a,b) * b; // Since the first division would always yield an integer
    }
}
