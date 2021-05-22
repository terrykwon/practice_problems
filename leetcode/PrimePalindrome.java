package com.terrykwon;

import org.junit.platform.commons.util.StringUtils;

import java.util.List;

/**
 * Find the smallest prime palindrome greater or equal to N.
 */
public class PrimePalindrome {
    public static void main(String[] args) {
        System.out.println(isPalindrome(1));
        System.out.println(isPalindrome(351));
        System.out.println(isPalindrome(22));
        System.out.println(isPalindrome(121));
        System.out.println(isPalindrome(12321));
        System.out.println(isPalindrome(1221));

        System.out.println(evenPalindrome(10));
        System.out.println(evenPalindrome(1));
        System.out.println(oddPalindrome(10));
        System.out.println(oddPalindrome(1));

        System.out.println(oddPalindrome(123));

        System.out.println(primePalindrome(1));
        System.out.println(primePalindrome(5));
        System.out.println(primePalindrome(10));
        System.out.println(primePalindrome(5000));
    }


    private static boolean isPalindrome(int i) {
        int l = 1;
        int r = (int) Math.pow(10, (int) Math.log10(i));
        while (l <= r) {
            if (!(i / l % 10 == i / r % 10)) return false;
            l *= 10;
            r /= 10;
        }
        return true;
    }

    private static boolean isPrime(int i) {
        for (int j = 2; j < (int) Math.sqrt(i); j++) {
            if (i % j == 0) return false;
        }
        return true;
    }

    private static int evenPalindrome(int left) {
        int i = left;
        int p = left;
        while (i > 0) {
            p = p * 10 + i % 10;
            i /= 10;
        }
        return p;
    }

    private static int oddPalindrome(int left) {
        int i = left / 10;
        int p = left;
        while (i > 0) {
            p = p * 10 + i % 10;
            i /= 10;
        }
        return p;
    }

    private static int primePalindrome(int N) {
        int digits = (int) Math.log10(N);
        int i = (int) Math.pow(10, digits / 2);

        if (digits % 2 == 0) { // Start with odd palindromes

        }
        while(true) {
            for (int j = i; j < 10*i-1; j++) {
                int p2 = oddPalindrome(j);
                if (p2 > N && isPrime(p2)) return p2;
            }

            for (int k = i; k < 10*i-1; k++) {
                int p1 = evenPalindrome(k);
                if (p1 > N && isPrime(p1)) return p1;
            }

            i *= 10;
        }
    }
}
