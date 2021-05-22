package com.terrykwon;

import java.util.Arrays;

public class ThreeEqualParts {
    public static void main(String[] args) {
        int[] a1 = new int[] {1, 0, 1, 0, 1};
        Utils.printArray(threeEqualParts(a1));
    }

    private static int[] threeEqualParts(int[] A) {
        int[] none = new int[] {-1, -1};
        int[] ones = new int[A.length];
        int j = 0;
        for (int i = 0; i < A.length; i++) {
            if (A[i] == 1) {
                ones[j] = i;
                j += 1;
            }
        }

        if (j % 3 != 0) return none;
        if (j == 0) return new int[] {0, 2}; // All zeros; arbitrary split is fine

        int s1, t1, s2, t2, s3, t3;

        int k = j / 3;
        s1 = ones[0];
        t1 = ones[k-1];
        s2 = ones[k];
        t2 = ones[2*k - 1];
        s3 = ones[2*k];
        t3 = ones[3*k - 1];

        // Compare the gaps between the ones
        if (!(t1-s1 == t2-s2) || !(t1-s1 == t3-s3)) return none;

        // Ensure that the trailing zeros are sufficient
        int z = A.length - t3 - 1;
        int z2 = s3 - t2 - 1;
        int z1 = s2 - t1 - 1;

        if (!(z2 >= z && z1 >= z)) return none;

        return new int[] {t1 + z, t2 + z + 1};
    }
}
