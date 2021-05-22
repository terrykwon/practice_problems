package com.terrykwon;

public class CountPrimes {

    private static boolean isPrime(int i) {
        int l = 1;
        int r = (int) Math.pow(10, (int) Math.log10(i));
        while (l <= r) {
            if (!(i / l % 10 == i / r % 10)) return false;
            l *= 10;
            r /= 10;
        }
        return true;
    }

    private static int countPrimes(int n) {
        int c = 0;
        for (int i = 1; i <= n; i++) {
            if (isPrime(i)) c++;
        }
        return c;
    }
}
